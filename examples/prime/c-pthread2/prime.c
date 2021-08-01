#include "prime.h"

primelist *head=NULL, *tail=NULL;
thdata       thd[TMAX];

int main(int argc, char **argv) {
    primelist *p = NULL, *q = NULL;
    long n, n_max, i, nd, tmax = TMAX;
    n_max = atol(argv[1]); /* >=3 */
    head = calloc(1, sizeof(primelist));
    tail = head;
    tail->prime = 2;
    n = 2;
    while((n - 1) * (n - 1) < n_max) {
        n++;
        if (checkprime(n)) {
            q= calloc(1, sizeof(primelist));
            tail->next = q;
            tail = q;
            tail->prime = n;
        }
    }
    nd = (n_max - n + tmax - 1) / (long) tmax;
    for (i=0; i < tmax; i++) {
        /* tmax thread of checkprime loop */
        thd[i].n0 = n + 1; /* next unchecked */
        thd[i].n1 = n + nd;
        if (thd[i].n1 >= n_max) {
            thd[i].n1 = n_max;
        }
	n = thd[i].n1;
        if (pthread_create(&thd[i].th,
                NULL, 
                (void *) subthread, 
                (void *) &(thd[i]) ) ) {
            printf ("E: error creating thread at %li\n", i);
        }
    }
    for (i=0; i < tmax; i++) {
        /* tmax thread of checkprime loop */
        if (pthread_join(thd[i].th, (void *) NULL) ) {
            printf ("E: error joining thread at %li\n", i);
        }
        if (thd[i].head != NULL) { /* prime found */
            tail->next = thd[i].head;
            tail = thd[i].tail;
        }
    }

    p=head;
    while(p) {
        printf ("%ld\n", p->prime);
        p = p->next;
    }
    p=head;
    while(p) {
        q = p->next;
	    free(p);
	    p = q;
    }
    return EXIT_SUCCESS;
}
