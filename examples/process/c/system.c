/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit getenv system */
#include <stdio.h>      /* [f]printf perror */

int
main(int argc, char* argv[])
{
    printf("main    HOME    = %s\n", getenv("HOME"));
    printf("main    PATH    = %s\n", getenv("PATH"));
    printf("main    TERM    = %s\n", getenv("TERM"));
    printf("main    DISPLAY = %s\n", getenv("DISPLAY"));
    printf("--- Let's fake shell command prompt with system\n");
    printf("$ ls -li system.c\n");
    system("ls -li system.c");
    return EXIT_SUCCESS;

}
