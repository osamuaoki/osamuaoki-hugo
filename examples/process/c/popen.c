/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit getenv */
#include <stdio.h>      /* [f]printf perror */
#include <unistd.h>     /* getpid getppid fork exec sleep */
#include <sys/types.h>  /* getpid getppid */

int
main(int argc, char* argv[])
{
    FILE* f;
    char * p;
    size_t size;
    p = malloc(1024);
    size = (size_t) 1024;
    fprintf(stderr, "main    PID     = %d\n", getpid());
    fprintf(stderr, "main    PPID    = %d\n", getppid());
    fprintf(stderr, "--- Let's fake shell command prompt with popen.\n");
    fprintf(stderr, "$ ls -li *.c; echo PPID=$PPID; echo PID=$$\n");
    f = popen("ls -li *.c; echo PPID=$PPID; echo PID=$$", "r");
    if (f < 0) {
        perror("E: popen");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "--- Let's print result of popen.\n");
    while (getline(&p, &size, f) >= 0) {
        fprintf(stderr, "%s", p);
    }
    pclose(f);
    return EXIT_SUCCESS;

}
