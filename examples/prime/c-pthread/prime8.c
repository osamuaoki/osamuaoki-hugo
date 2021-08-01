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
#ifdef DEBUG
    printf ("I: LOOPING inner AA        i=%li, n0=%li, n1=%li\n", i, thd->n0, thd->n1);
#endif
        if (checkprime(i)) {
#ifdef DEBUG
    printf ("I: LOOPING inner CC         i=%li, n0=%li, n1=%li\n", i, thd->n0, thd->n1);
#endif
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
#ifdef DEBUG
    printf ("I: LOOPING inner ZZ         i=%li, n0=%li, n1=%li\n", i, thd->n0, thd->n1);
#endif
        }
    }
}

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max, i, nd;
    n_max = atol(argv[1]);
    head = calloc(1, sizeof(primelist));
    tail = head;
    tail->prime = 2;
    n = 2;
    while((n - 1) * (n - 1) <= n_max) {
        n++;
        if (checkprime(n)) {
            q= calloc(1, sizeof(primelist));
            tail->next = q;
            tail = q;
            tail->prime = n;
        }
    }
    nd = (n_max - n ) / (long) TMAX + 1L;
    for (i=0; i < TMAX; i++) {
        /* TMAX thread of checkprime loop */
        thd[i].n0 = n;
        thd[i].n1 = n + nd;
        if (thd[i].n1 >= n_max) {
            thd[i].n1 = n_max;
        }
	n = thd[i].n1;
#ifdef DEBUG
        printf ("I: LOOPING outer          i=%li, n0=%li n1=%li\n", i, thd[i].n0, thd[i].n1);
#endif
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
#ifdef DEBUG
        printf ("I: LOOPING join          i=%li\n", i);
#endif
        tail->next = thd[i].head;
        tail = thd[i].tail;
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

