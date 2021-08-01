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

struct _thdata {
    pthread_t           th;
    int                 flag;
};
typedef struct _thdata thdata;

primelist *head=NULL, *tail=NULL;

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

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max, m;
    n_max = atol(argv[1]);
    /* thdata = calloc(TMAX, sizeof(thdata)); */
    head = calloc(1, sizeof(primelist));
    tail = head;
    tail->prime = 2;
    n = 2; /* last number checking for prime */
    m = 2; /* last number checked  for prime */
    while(m < n_max) {
#ifdef DEBUG
        printf ("I: out LOOP n=%li, m=%li (%li)\n", n, m, n-m);
#endif
        if ((n + 1 - m < TMAX) && (n + 1 <= m * m) && (n + 1 <= n_max)) {
            n = n + 1;
            /* start checkprime(n) */
            if (pthread_create(&thd[n%TMAX].th,
                        NULL,
                        (void *) checkprime,
                        (void *) n) ) {
                printf ("E: error creating thread at %li\n", n);
            }
#ifdef DEBUG
        printf ("I: n++      n=%li, m=%li (%li)\n", n, m, n-m);
#endif
        }
        if ((n + 1 - m >= TMAX) || (n + 1 > m * m) || (n + 1 > n_max) ) {
            m++;
            /* close checkprime(m) */
            pthread_join(thd[m%TMAX].th, (void *) &thd[m%TMAX].flag);
#ifdef DEBUG
        printf ("I: m++      n=%li, m=%li (%li)\n", n, m, n-m);
#endif
            if (thd[m%TMAX].flag) {
                /* if prime, update list with m */
                q = calloc(1, sizeof(primelist));
        	    tail->next = q;
        	    tail = q;
            	tail->prime = m;
#ifdef DEBUG
        printf ("I: prime  ------------------------------  m=%li\n", m);
            } else {
        printf ("I: not prime  XXXXXXXXXXXXXXXXXXXXXXXXXX  m=%li\n", m);
#endif
            }
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
	    /* free(p); */
	    p = q;
    }
    return EXIT_SUCCESS;
}

