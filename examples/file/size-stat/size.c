/* vi:set ts=4 sts=4 expandtab: */
#include <stdio.h>      /* printf, perror */
#include <errno.h>      /* perror */
#include <stdlib.h>     /* exit */
#include <sys/types.h>  /* stat */
#include <sys/stat.h>   /* stat */
#include <unistd.h>     /* stat */
#include <locale.h>     /* setlocale */

int
main(int argc, char* argv[])
{
    struct stat st;
    off_t size;
    if (argc != 2) {
        printf("E: Need a filename as an argument.\n");
        return EXIT_FAILURE;
    }
    if (stat(argv[1], &st) == -1) {
        perror("E: Can not stat input file");
        exit(EXIT_FAILURE);
    }
    size = st.st_size;
    setlocale(LC_ALL,"");
    printf("\nFile size: %'zi\n", size);
    return EXIT_SUCCESS;
}

