/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit */
#include <stdio.h>      /* [f]printf perror */
#include <signal.h>     /* signal */
#include <unistd.h>     /* getpid pause */

void
handler(int signum)
{
    printf("\n=== SIGNAL %d handler ===\n", signum);
    printf("First round ... ignored.  Next round activated.\n");
    (void) signal(SIGINT, SIG_DFL); /* set signal behavior to default */
}
int
main(int argc, char* argv[])
{
    printf("PID=%d", getpid());
    (void) signal(SIGINT, handler); /* set signal behavior to handler */
    (void) signal(SIGHUP, SIG_IGN); /* set signal behavior to ignore */
    while(1) {
        pause();    /* waiting for signal */
    }
    return EXIT_SUCCESS;
}
