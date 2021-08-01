#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 100000000
#define TRUE 1
#define FALSE 0

int main (int argc, char ** argv) {
    long n_max = atol (argv[1]);
    long j = 1;
    long p[ARRAY_SIZE];
    long n, k, i, n_div_i, n_mod_i;
    int flag_prime;
    for (n = 2; n < n_max; n++) {
        flag_prime = TRUE;
        /* search for all pimes found */
        for (k = 1; k < j; k++) {
            i = p[k];
            n_div_i = n / i;
            n_mod_i = n % i;
            if (n_mod_i == 0) {
                flag_prime = FALSE;
                break; /* found not to be prime */
            }
            if (n_div_i < i) {
                break; /* no use doing more i-loop if n < i*i */
            }
        }
        if (flag_prime == TRUE) {
            p[j]=n;
            j++;
            if (j>ARRAY_SIZE) {
                printf ("E: Overflow array after %ld\n", p[j-1]);
                return EXIT_FAILURE;
            }
        }
    }
    for (k=1; k < j; k++) {
        printf ("%ld\n", p[k]);
    }
    return EXIT_SUCCESS;
}

