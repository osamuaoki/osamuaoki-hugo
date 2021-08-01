#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    const char* bar = "abcdefgh";
    printf("Before bar* = '%s'\n\n", bar);
    bar[3] = '@';
    printf("After  bar* = '%s'\n\n", bar);
    return EXIT_SUCCESS;
}

