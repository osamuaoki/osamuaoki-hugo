#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _primelist primelist;
struct _primelist {
    long prime; 
    primelist *next;
    };

primelist *head=NULL, *tail=NULL;

int checkprime(long n) {
    primelist *p;
    long i, n_div_i, n_mod_i;
    int flag;
    flag = TRUE;
    for (p = head; p != NULL ; p = p->next) {
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
    }
    return flag;
}

int main(int argc, char **argv) {
    primelist *p=NULL, *q=NULL;
    long n, n_max;
    n_max = atol(argv[1]);
    for (n = 2; n <= n_max; n++) {
        if (checkprime(n)) {
            q= calloc(1, sizeof(primelist));
            q->prime = n;
            if (head == NULL) {
                head = q;
            } else {
                tail->next=q;
            }
            tail = q;
        }
    }
    for (p = head; p != NULL; p = p->next) {
        printf ("%ld\n", p->prime);
    }
    for (p = head; p != NULL; q = p->next, free(p), p = q) {}
    return EXIT_SUCCESS;
}

