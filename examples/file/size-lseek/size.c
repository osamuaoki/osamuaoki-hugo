/* vi:set ts=4 sts=4 expandtab: */
#include <stdio.h>      /* printf, perror */
#include <errno.h>      /* perror */
#include <stdlib.h>     /* exit */
#include <fcntl.h>      /* open */
#include <sys/stat.h>   /* open */
#include <sys/types.h>  /* open, lseek */
#include <unistd.h>     /* lseek */
#include <locale.h>     /* setlocale */

int
main(int argc, char* argv[])
{
    int fd;
    off_t size;
    if (argc != 2) {
        printf("E: Need a filename as an argument.\n");
        return EXIT_FAILURE;
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror("E: Can not open input file");
        exit(EXIT_FAILURE);
    }
    size = lseek(fd, 0, SEEK_END);
    setlocale(LC_ALL,"");
    printf("\nFile size: %'zi\n", size);
    return EXIT_SUCCESS;
}

