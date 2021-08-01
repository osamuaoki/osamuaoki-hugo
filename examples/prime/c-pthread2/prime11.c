#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0
#define TMAX 64L

struct _primelist {
    long prime; 
    struct _primelist *next;
    };
typedef struct _primelist primelist;

primelist *head=NULL, *tail=NULL;

struct _thdata {
    pthread_t           th;
    long                n0;
    long                n1;
    primelist           *head;
    primelist           *tail;
};
typedef struct _thdata thdata;

thdata       thd[TMAX];

int checkprime(long n) {
    primelist *p;
    long i, n_div_i, n_mod_i;
    int flag;
    flag = TRUE;
    p = head;
    while(p) {
        i = p->prime;
        n_div_i = n / i;
        n_mod_i = n % i;
        if (n_mod_i == 0) {
            flag = FALSE;
            break; /* found not to be prime */
        }
        if (n_div_i < i) {
            break; /* no use doing more i-loop if n < i*i */
        }
        p = p->next;
    }
    return flag;
}

void subthread(thdata *thd) {
    long i;
    primelist *p=NULL, *q=NULL;
    thd->head = NULL;
    for (i = thd->n0; i <= thd->n1; i++) {
        if (checkprime(i)) {
            q = calloc(1, sizeof(primelist));
            q->prime = i;
            if (!thd->head) {
                thd->head = q;
                p = q;
            } else {
                p->next = q;
                p = q;
            }
            thd->tail = q;
        }
    }
}

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max, i, nd;
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
    nd = (n_max - n + TMAX - 1) / (long) TMAX;
    for (i=0; i < TMAX; i++) {
        /* TMAX thread of checkprime loop */
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
    for (i=0; i < TMAX; i++) {
        /* TMAX thread of checkprime loop */
        if (pthread_join(thd[i].th, (void *) NULL) ) {
            printf ("E: error joining thread at %li\n", i);
        }
        if (thd[i].head != NULL) { /* append if prime found */
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

