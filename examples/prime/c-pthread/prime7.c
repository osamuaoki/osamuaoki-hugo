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
    long                n;
    int                 flag;
    sem_t               read_ready;
    sem_t               read_done;
    sem_t               write_ready;
    sem_t               write_done;
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

void subthread(thdata *thd) {
    while(TRUE) {
        sem_post(&(thd->read_ready));
        sem_wait(&(thd->read_done));
        thd->flag = checkprime(thd->n);
#ifdef DEBUG
        printf ("I: LOOPING inner         n=%li, flag=%i\n", thd->n, thd->flag);
#endif
        sem_post(&(thd->write_ready));
        sem_wait(&(thd->write_done));
    }
}

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max, m;
    int i;
    n_max = atol(argv[1]);
    head = calloc(1, sizeof(primelist));
    tail = head;
    tail->prime = 2;
    for (i=0;i<TMAX;i++){
        sem_init(&thd[i].read_ready, 0, 0);
        sem_init(&thd[i].read_done, 0, 0);
        sem_init(&thd[i].write_ready, 0, 0);
        sem_init(&thd[i].write_done, 0, 0);
        if (pthread_create(&thd[i].th,
                NULL, 
                (void *) subthread, 
                (void *) &(thd[i]) ) ) {
            printf ("E: error creating thread at %i\n", i);
        }
    }
    n = 2; /* last number started   checking of prime*/
    m = 2; /* last number completed checking of prime */
    while(m < n_max) {
#ifdef DEBUG
        printf ("I: LOOPING outer          n=%li, m=%li\n", n, m);
#endif
        if ((n + 1 - m < TMAX) && (n + 1 <= m * m) && (n + 1 <= n_max)) {
            n = n + 1;
#ifdef DEBUG
            printf ("I: n++ for n=%li, m=%li\n", n, m);
#endif
            /* start checkprime(n) */
#ifdef DEBUG
            printf ("I: WAIT thd[n%%TMAX].read_ready for n%%TMAX=%li, n=%li\n", n%TMAX, n);
#endif
            sem_wait(&(thd[n%TMAX].read_ready));
            thd[n%TMAX].n = n;
            sem_post(&(thd[n%TMAX].read_done));
#ifdef DEBUG
            printf ("I: POST thd[n%%TMAX].read_done for n%%TMAX=%li, n=%li\n", n%TMAX, n);
#endif
        }
        if ((n + 1 - m >= TMAX) || (n >= m * m) || (n >= n_max) ) {
            m++;
#ifdef DEBUG
            printf ("I: m++ for n=%li, m=%li\n", n, m);
#endif
            /* close checkprime(m) */
#ifdef DEBUG
            printf ("I: WAIT thd[m%%TMAX].write_ready for m%%TMAX=%li, m=%li\n", m%TMAX, m);
#endif
            sem_wait(&(thd[m%TMAX].write_ready));
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
            sem_post(&(thd[m%TMAX].write_done));
#ifdef DEBUG
            printf ("I: POST thd[m%%TMAX].write_done for m%%TMAX=%li, m=%li\n", m%TMAX, m);
#endif
        }
    }
    for (i=0;i<TMAX;i++){
        if (pthread_cancel(thd[i].th)) {
            printf ("E: error canseling thread at %i\n", i);
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

