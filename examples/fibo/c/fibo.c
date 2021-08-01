#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    long n = strtol(argv[1], NULL, 10);
    long a = 0;
    long b = 1;
    long c;
    while (b < n) {
        printf("%ld\n", b);
        c = b;
        b = a + b;
        a = c;
        if (b < 0) {
            printf("E: overflow %ld\n", b);
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}
