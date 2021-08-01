/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h> /* exit, malloc */
#include <stdio.h>  /* printf, perror, freed */
#include <errno.h>  /* perror */
#include <locale.h> /* setlocale */
#define BUFFSIZE (1024*1024*4)

int
main(int argc, char* argv[])
{
    FILE *fi, *fo;
    char *buf;
    size_t n = BUFFSIZE, i;
    if (argc != 3) {
        printf("E: Need 2 filenames as arguments.\n");
        return EXIT_FAILURE;
    }
    if ((fi = fopen(argv[1], "r")) == NULL) {
        perror("E: Can not open input file");
        return EXIT_FAILURE;
    }
    if ((fo = fopen(argv[2], "w")) == NULL) {
        perror("E: Can not open output file");
        return EXIT_FAILURE;
    }
    if ((buf = (char *) malloc(n)) == NULL) {
        perror("E: Can not make a buffer");
        exit(EXIT_FAILURE);
    }
    for (;;) {
        i = fread(buf, 1, n, fi);
        if (ferror(fi)) {
            perror("E: Error reading input file");
            exit(EXIT_FAILURE);
        } else if (i == 0) {
            break;
        } else {
            if (fwrite(buf, 1, i, fo) != i) {
                perror("E: Error writing output file");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (fclose(fi)) {
        perror("E: Can not close input file");
        exit(EXIT_FAILURE);
    }
    if (fclose(fo)) {
        perror("E: Can not close output file");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

