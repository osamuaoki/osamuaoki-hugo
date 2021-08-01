#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct _primelist {
    long prime; 
    struct _primelist *next;
    };
typedef struct _primelist primelist;

primelist *head=NULL, *tail=NULL;

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
    long n, n_max;
    n_max = atol(argv[1]);
    head = calloc(1, sizeof(primelist));
    tail = head;
    tail->prime = 2;
    n = 2;
    while(n <= n_max) {
        n++;
        if (checkprime(n)) {
            q= calloc(1, sizeof(primelist));
            tail->next = q;
            tail = q;
            tail->prime = n;
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

