#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int i;
    assert(argv[1] != NULL);
    assert(argv[2] == NULL);
    i = atoi(argv[1]);
    assert(i >= 0);
    if (i >= 0) {
        printf("Argument is a single non-negative value: %i\n", i);
    }
    return EXIT_SUCCESS;
}
