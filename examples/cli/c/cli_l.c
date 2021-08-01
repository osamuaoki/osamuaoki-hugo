/* a long command line option example */

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>        /* getopt_long */

int main(int argc, char **argv)
{
    int c;
    int i = 0;
    int verbose = 0;
    static struct option longopts[] = {
        {"append", no_argument, 0, 'a'},
        {"verbose", no_argument, 0, 'v'},
        {"file", required_argument, 0, 'f'},
        {"long", no_argument, 0, 0},
        {"longextra", required_argument, 0, 0},
        {NULL, 0, NULL, 0}
    };
    while ((c = getopt_long(argc, argv, "af:v", longopts, &i)) != -1) {
        switch (c) {
        case 0: /* for longopts[all][3] == 0 */
            printf ("option %s", longopts[i].name);
            if (optarg)
                printf (" with arg %s", optarg);
            printf ("\n");
            break;
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
            printf("unknown option = %c = ascii(0%x)\n", optopt, optopt);
            printf("return value of getopt_long() = %c\n", c);
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

