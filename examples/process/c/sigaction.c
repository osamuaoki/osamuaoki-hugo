/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit */
#include <stdio.h>      /* [f]printf perror */
#include <signal.h>     /* signaction */
#include <unistd.h>     /* getpid pause */

static struct sigaction saint, sahup;

void
handler(int signum)
{
    printf("\n=== SIGNAL %d handler ===\n", signum);
    printf("First round ... ignored.  Next round activated.\n");
    saint.sa_handler = SIG_DFL;     /* signal behavior to default */
    sigaction(SIGINT, &saint, 0);   /* set signal */

}
int
main(int argc, char* argv[])
{
    printf("PID=%d", getpid());
    saint.sa_flags = 0;             /* default */
    sigemptyset(&saint.sa_mask);    /* create a open mask */
    /* sigaddset(&saint.sa_mask, SIGINT); no need since no SA_NODEFER */
    saint.sa_handler = handler;     /* signal behavior to handler */
    sigaction(SIGINT, &saint, 0);   /* set signal */

    sahup.sa_flags = SA_NODEFER;    /* set SA_NODEFER */
    sigemptyset(&sahup.sa_mask);    /* create a open mask */
    sigaddset(&sahup.sa_mask, SIGHUP); /* mask SIGHUP since SA_NODEFER */
    sahup.sa_handler = SIG_IGN;     /* signal behavior to ignore */
    sigaction(SIGHUP, &sahup, 0);   /* set signal */

    while(1) {
        pause();    /* waiting for signal */
    }
    return EXIT_SUCCESS;
}
