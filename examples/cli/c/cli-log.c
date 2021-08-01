#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> /* getopt */
#include "logerr.h"

int main(int argc, char **argv)
{
    int c;
    int logerr_level = 0;
    char* env_debug = NULL;
    env_debug = getenv("DEBUG");
    if (env_debug) {
        logerr_level = atoi(env_debug);
    }
    while ((c = getopt(argc, argv, "v")) != -1) {
        switch (c) {
        case 'v':
            logerr_level += 1;
            break;
        default:
            printf("unknown option = %c = ascii(0%x)\n",
                    optopt, optopt);
            printf("return value of getopt() = %c\n", c);
        }
    }
    printf("logerr_level = %i\n", logerr_level);
    logerr(LOGERR_NOTICE,"optind = %i\n", optind);
    logerr(LOGERR_INFO,"argc = %i\n", argc);
    logerr(LOGERR_DEBUG,"argv[0] = %s\n", argv[0]);
    if (optind + 2 == argc) {
        printf("%s %s!\n", argv[optind], argv[optind+1]);
    } else {
        logerr(LOGERR_WARN,"%i arg(s) / 2 args needed\n", argc - optind);
        printf("Oops!\n");
    }
    return EXIT_SUCCESS;
}
