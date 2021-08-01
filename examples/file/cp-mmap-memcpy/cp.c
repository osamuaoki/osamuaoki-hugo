/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h> /* exit, malloc */
#include <stdio.h>  /* printf, perror */
#include <errno.h>  /* perror */
#include <fcntl.h>      /* open */
#include <unistd.h>     /* lseek, write */
#include <sys/stat.h>   /* open */
#include <sys/types.h>  /* open, lseek */
#include <sys/mman.h>   /* mmap */
#include <locale.h> /* setlocale */
#include <string.h>     /* memcpy */
int
main(int argc, char* argv[])
{
    int fdi, fdo;
    void *src, *dst;
    size_t size;
    ssize_t offset;
    if (argc != 3) {
        printf("E: Need 2 filenames as arguments.\n");
        return EXIT_FAILURE;
    }
    if ((fdi = open(argv[1], O_RDONLY)) < 0) {
        perror("E: Can not open input file");
        exit(EXIT_FAILURE);
    }
    size = lseek(fdi, 0, SEEK_END);
    src = mmap(NULL, size, PROT_READ, MAP_SHARED, fdi, 0);
    if (src == (void *) -1) {
        perror("E: Can not map input file");
        exit(EXIT_FAILURE);
    }
    if ((fdo = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 00666)) < 0) {
        perror("E: Can not open output file");
        exit(EXIT_FAILURE);
    }
    offset = lseek(fdo, size -1, SEEK_SET);
    if (offset == (ssize_t) -1) {
        perror("E: lseek() error");
        exit(EXIT_FAILURE);
    }
    offset = write(fdo, "", 1); /* dummy write at the end */
    if (offset == (ssize_t) -1) {
        perror("E: write() error");
        exit(EXIT_FAILURE);
    }
    dst = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fdo, 0);
    if (dst == MAP_FAILED) {
        perror("E: Can not map output file");
        exit(EXIT_FAILURE);
    }
    memcpy(dst, src, size);
    if (munmap(src, size)) {
        perror("E: Can not unmap input file");
        exit(EXIT_FAILURE);
    }
    if (munmap(dst, size)) {
        perror("E: Can not unmap output file");
        exit(EXIT_FAILURE);
    }
    if (close(fdi)) {
        perror("E: Can not close input file");
        exit(EXIT_FAILURE);
    }
    if (close(fdo)) {
        perror("E: Can not close output file");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

