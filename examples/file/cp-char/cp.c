/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit */
#include <stdio.h>      /* printf, perror */
#include <errno.h>      /* perror */
#include <locale.h>     /* setlocale */

int
main(int argc, char* argv[])
{
    FILE *fi, *fo;
    int i;
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
    for (;;) {
        i = getc(fi);
        if (ferror(fi)) {
            perror("E: Error reading input file");
            exit(EXIT_FAILURE);
        } else if (feof(fi)) {
            break;
        } else {
            putc(i, fo);
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

