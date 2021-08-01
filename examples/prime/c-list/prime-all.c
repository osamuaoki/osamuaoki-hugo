#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

#if STYLE==1
typedef struct _primelist {
    long prime; 
    struct _primelist *next;
    } primelist;
#elif STYLE==2
typedef struct _primelist primelist;
struct _primelist {
    long prime; 
    primelist *next;
    };
#else /* default */
struct _primelist {
    long prime; 
    struct _primelist *next;
    };
typedef struct _primelist primelist;
#endif

primelist *head=NULL, *tail=NULL;

int checkprime(long n) {
    primelist *p;
    long i, n_div_i, n_mod_i;
    int flag;
    flag = TRUE;
#if STYLE == 4
    p = head;
    while(p) {
#else /* default */
    for (p = head; p != NULL ; p = p->next) {
#endif
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
#if STYLE == 4
        p = p->next;
#endif
    }
    return flag;
}

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max;
    n_max = atol(argv[1]);
#if STYLE == 4
    n = 1;
    while(n <= n_max) {
        n++;
#else /* default */
    for (n = 2; n <= n_max; n++) {
#endif
        if (checkprime(n)) {
#if STYLE == 3
            q = malloc(sizeof(primelist));
            q->next = NULL;
#else /* default */
            q= calloc(1, sizeof(primelist));
#endif
            q->prime = n;
            if (head == NULL) {
                head = q;
            } else {
                tail->next=q;
            }
            tail = q;
        }
    }
#if STYLE == 4
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
#else /* default */
    for (p = head; p != NULL; p = p->next) {
        printf ("%ld\n", p->prime);
    }
    for (p = head; p != NULL; q = p->next, free(p), p = q) {}
#endif
    return EXIT_SUCCESS;
}

