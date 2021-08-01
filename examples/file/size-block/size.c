/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h> /* exit, malloc */
#include <stdio.h>  /* printf, perror, freed */
#include <errno.h>  /* perror */
#include <locale.h> /* setlocale */
#define BUFFSIZE (1024*4)
int
main(int argc, char* argv[])
{
    FILE *f;
    char *buf;
    size_t n = BUFFSIZE, i, size = 0;
    if (argc != 2) {
        printf("E: Need a filename as an argument.\n");
        return EXIT_FAILURE;
    }
    if ((buf = (char *) malloc(n)) == NULL) {
        perror("E: Can not make a buffer");
        exit(EXIT_FAILURE);
    }
    if ((f = fopen(argv[1], "r")) == NULL) {
        perror("E: Can not open input file");
        exit(EXIT_FAILURE);
    }
    for (;;) {
        i = fread(buf, 1, n, f);
        if (ferror(f)) {
            perror("E: Error reading input file");
            exit(EXIT_FAILURE);
        } else if (i == 0) {
            break;
        } else {
            size += i;
        }
    }
    if (fclose(f)) {
        perror("E: Can not close input file");
        exit(EXIT_FAILURE);
    }
    setlocale(LC_ALL,"");
    return (printf("\nFile size: %'zi\n", size));
}

