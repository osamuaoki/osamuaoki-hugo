/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int
main(int argc, char* argv[])
{
    int n = 12345678;
    printf("init        %%i  -> %i\n", n);
    printf("init        %%'i -> %'i\n", n);
    setlocale(LC_ALL,"");
    printf("env         %%i  -> %i\n", n);
    printf("env         %%'i -> %'i\n", n);
    setlocale(LC_ALL,"C");
    printf("C           %%i  -> %i\n", n);
    printf("C           %%'i -> %'i\n", n);
    setlocale(LC_ALL,"en_US.UTF-8");
    printf("en_US.UTF-8 %%i  -> %i\n", n);
    printf("en_US.UTF-8 %%'i -> %'i\n", n);
    setlocale(LC_ALL,"fr_FR.UTF-8");
    printf("fr_FR.UTF-8 %%i  -> %i\n", n);
    printf("fr_FR.UTF-8 %%'i -> %'i\n", n);
    setlocale(LC_ALL,"de_DE.UTF-8");
    printf("de_DE.UTF-8 %%i  -> %i\n", n);
    printf("de_DE.UTF-8 %%'i -> %'i\n", n);
    setlocale(LC_ALL,"ja_JP.UTF-8");
    printf("ja_JP.UTF-8 %%i  -> %i\n", n);
    printf("ja_JP.UTF-8 %%'i -> %'i\n", n);
    return EXIT_SUCCESS;
}

