/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safe_strncpy.h"

char s1[10], s2[10];
int main(int argc, char ** argv)
{
    char *sc1 = "0123456789"; /* 11 bytes */
    char *sc2 = "I gotcha!";  /* 10 bytes */

    printf("%s\n", "Constant strings");
    printf("\tsc1 = %s\n", sc1);
    printf("\tsc2 = %s\n", sc2);
    safe_strncpy(s1, sc1, 10);
    safe_strncpy(s2, sc2, 10);
    printf("%s\n", "Copied strings: safe_strncpy\n"
        "\t\tIt should drop 9 at the end to be safe.");
    printf("\ts1  = %s\n", s1);
    printf("\ts2  = %s\n", s2);
    strncpy(s1, sc1, 10);
    printf("%s\n", "Copied strings: strncpy(s1, sc1, 10)\n"
        "\t\tprintf(..., s1) can not stop at the end.");
    printf("\ts1  = %s\n", s1);
    printf("\ts2  = %s\n", s2);
    strcpy(s1, sc1);
    printf("%s\n", "Copied strings: strcpy(s1, sc1)\n"
        "\t\tstrcpy overwrites onto s2.");
    printf("\ts1  = %s\n", s1);
    printf("\ts2  = %s\n", s2);
    return EXIT_SUCCESS;
}
