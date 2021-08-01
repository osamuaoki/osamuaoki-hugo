#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char foo[] = "abcdefgh";
    printf("Before foo[] = '%s'\n\n", foo);
    foo[3] = '@';
    printf("After  foo[] = '%s'\n\n", foo);
    return EXIT_SUCCESS;
}

