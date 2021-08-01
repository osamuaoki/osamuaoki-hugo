/* vi:set ts=4 sts=4 expandtab: */
#include <stdlib.h>     /* exit getenv */
#include <stdio.h>      /* [f]printf perror */
#include <string.h>     /* strlen */
#include <unistd.h>     /* getpid getppid fork exec sleep */
#include <sys/types.h>  /* getpid getppid wait */
#include <sys/wait.h>   /* wait */

int
main(int argc, char* argv[])
{
    pid_t p;
    int pipefd[2], e;
    char buf;
    char * b = "MESSAGE: passed from child to parent via pipe\n";
    fprintf(stderr, "parent  PID     = %d\n", getpid());
    fprintf(stderr, "parent  PPID    = %d\n", getppid());
    if (pipe(pipefd) == -1) {   /* create pipe */
        perror("E: pipe");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "--- Let's fork ...\n");
    p = fork();
    if (p == -1) {
        perror("E: Fork error\n");
        exit(EXIT_FAILURE);
    } else if (p == 0) {    /* child process */
        close(pipefd[0]);   /* Close unused read end fd */
        printf("child   PID     = %d\n", getpid());
        printf("child   PPID    = %d\n", getppid());
        printf("child   write to pipe\n");
        write(pipefd[1], b, strlen(b));
        dup2(pipefd[1], STDOUT_FILENO);
        printf("child>  ls -l forkexec.c\n");
        e = execlp("/bin/ls", "ls", "-l", "forkexec.c", NULL);   /* execute ls -l */
        close(pipefd[1]);   /* Close used write end fd */
        _exit(e);           /* idiom to end child process "immediately" */
    } else {                /* parent process */
        close(pipefd[1]);   /* Close unused write end fd */
        fprintf(stderr, "parent  PID     = %d\n", getpid());
        fprintf(stderr, "parent  PPID    = %d\n", getppid());
        fprintf(stderr, "parent  forked  = %d\n", p);
        fprintf(stderr, "parent  read from pipe\n");
        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDERR_FILENO, &buf, 1);
        }
        close(pipefd[0]);   /* Close used read end fd */
        wait(NULL);         /* Wait for child */
        fprintf(stderr, "parent  child exited.\n");
    }
    return EXIT_SUCCESS;
}
