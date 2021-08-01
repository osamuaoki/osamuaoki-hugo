/* a short command line option example */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> /* getopt */
int main(int argc, char **argv)
{
    int c;
    int verbose = 0;
    while ((c = getopt(argc, argv, "af:v")) != -1) {
        switch (c) {
        case 'a':
            printf("option a\n");
            break;
        case 'f':
            printf("option f with %s.\n", optarg);
            break;
        case 'v':
            verbose = 1;
            break;
        default:
            printf("unknown option = %c = ascii(0%x)\n",
                    optopt, optopt);
            printf("return value of getopt() = %c\n", c);
        }
    }
    printf("verbose mode = %i\n", verbose);
    if (optind < argc) {
        int j = 1;
        while (optind < argc) {
            printf("argument[%i]=%s\n", j, argv[optind++]);
            j++;
        }
    }
    return EXIT_SUCCESS;
}
