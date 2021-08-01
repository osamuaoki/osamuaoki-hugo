#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    long n = strtol(argv[1], NULL, 10);
    printf("Parsed as %ld\n", n);
    return EXIT_SUCCESS;
}
