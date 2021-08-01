/* vi:set ts=4 sts=4 expandtab: */
#include <stdio.h>      /* printf, perror */
#include <errno.h>      /* perror */
#include <stdlib.h>     /* exit */
#include <fcntl.h>      /* open */
#include <sys/stat.h>   /* open */
#include <sys/types.h>  /* open lseek */
#include <unistd.h>     /* lseek */
#include <locale.h>     /* setlocale */

int
main(int argc, char* argv[])
{
    FILE *f;
    off_t size = 0;
    if (argc != 2) {
        printf("E: Need a filename as an argument.\n");
        return EXIT_FAILURE;
    }
    f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("E: Can not open input file");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        fgetc(f);
        if (ferror(f)) {
            perror("E: Error reading input file");
            exit(EXIT_FAILURE);
        }
        if (feof(f)) {
            break;
        } else {
            size += 1;
        }
    }
    if (fclose(f)) {
        perror("E: Can not close input file");
        exit(EXIT_FAILURE);
    }

    setlocale(LC_ALL,"");
    return (printf("\nFile size: %'zi\n", size));
}

