/* vi:set ts=4 sts=4 expandtab: */
#include "common.h"

int main (int argc, char **argv)
{
    FILE *f;              /* for log_printf */
    int port, fdbl, hit, fdsock, pid, i;
    socklen_t addrlen;
    static struct sockaddr_in6 client_address, server_address;
    static struct sigaction sacld, sahup;
    if (argc < 1 || argc > 3) {
        (void) fprintf(stderr, "Mini-httpd6:\nUsage: httpd6 [port [PATH]]\n");
        exit(EXIT_FAILURE);
    } else if (argc == 1) {
        port = 8080;
    } else {
        if ((int) strlen(argv[1]) > 6) {
            (void) fprintf(stderr, "E: port is more than 5 digits.\n");
            exit(EXIT_FAILURE);
        }
        port = atoi(argv[1]);
    }
    if (port < 1024 || port > 60000) {
        (void) fprintf(stderr, "E: Invalid port number as argument. "
                "Try 1024-60000.\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 3) {
        if ((int) strlen(argv[2]) > 81) {
            (void) fprintf(stderr, "E: PATH is more than 80 chars.\n");
            exit(EXIT_FAILURE);
        }
        if (chdir(argv[2])) {
            (void) fprintf(stderr, "E: Can not change to directory %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    } else { /* default argc = 1 or 2 */
        if (chdir(getenv("HOME"))) {
            (void) fprintf(stderr, "E: Can not change to directory %s.\n", 
                getenv("HOME"));
            exit(EXIT_FAILURE);
        }
        if (chdir(WEB_ROOT)) {
            (void) fprintf(stderr, "E: Can not change to directory %s.\n", 
                WEB_ROOT);
            exit(EXIT_FAILURE);
        }
    }
    sacld.sa_flags = 0;             /* default */
    sigemptyset(&sacld.sa_mask);    /* create a open mask */
    sacld.sa_handler = SIG_IGN;     /* ignore child death */
    sigaction(SIGINT, &sacld, 0);   /* set signal */
    sahup.sa_flags = 0;             /* default */
    sigemptyset(&sahup.sa_mask);    /* create a open mask */
    sahup.sa_handler = SIG_IGN;     /* ignore terminal hungup */
    sigaction(SIGINT, &sahup, 0);   /* set signal */
    for (i = 0; i <= MAXFD; i++) {
        (void) close(i);            /* close STDIN, STDOUT, ... */
    }
    pid = fork();
    if (pid == -1) {
        log_printf("ERROR: system call: fork, %s, exiting pid=%d.\n", 
                strerror(errno), getpid());
        exit(EXIT_FAILURE);
    } else if (pid != 0) {
        (void) fprintf(stderr, "I: Sucessfully daemonize httpd6.\n");
        return EXIT_SUCCESS;        /* parent exit and deamonize */
    }
    if (setpgrp()) {                /* set PGID of child to PGID of parent */
        log_printf("ERROR: system call: setgrp, %s, exiting pid=%d.\n", 
                strerror(errno), getpid());
        exit(EXIT_FAILURE);
    }
    log_printf("LOG: httpd starting with parent pid=%d.\n", getpid());
    fdbl = socket(AF_INET6, SOCK_STREAM, 0);
    if (fdbl == -1) {
        log_printf("ERROR: system call: socket, %s, exiting pid=%d.\n", 
                strerror(errno), getpid());
        exit(EXIT_FAILURE);
    }
    server_address.sin6_family = AF_INET6;              /* IPV6 , see ip(7)*/
    server_address.sin6_addr = in6addr_any;
    server_address.sin6_port = htons(port);             /* host to network */
    if (bind(fdbl, (struct sockaddr *) &server_address, 
            sizeof(server_address)) == -1) {
        log_printf("ERROR: system call: bind, %s, exiting pid=%d.\n", 
                    strerror(errno), getpid());
        exit(EXIT_FAILURE);
    } else {
        log_printf("LOG: bind: with IPv6 accept, port=%d.\n", port);
    }
    if (listen(fdbl, MAXBACKLOG) == -1) {
        log_printf("ERROR: system call: listen, %s, exiting pid=%d.\n", 
                strerror(errno), getpid());
        exit(EXIT_FAILURE);
    }
    log_printf("LOG: httpd successfuly bind and listen at port %i.\n", port);
    for (hit = 1; ; hit++) {
        addrlen = sizeof(client_address);
        fdsock = accept(fdbl, (struct sockaddr *) &client_address, &addrlen);
        if (fdsock == -1) {
            log_printf("ERROR: system call: accept, %s, exiting pid=%d.\n", 
                    strerror(errno), getpid());
            exit(EXIT_FAILURE);
        }
        log_printf("LOG: httpd hit=%i.\n", hit);
        pid = fork();
        if (pid == -1) {
            log_printf("ERROR: system call: fork, %s, exiting pid=%d.\n", 
                    strerror(errno), getpid());
            exit(EXIT_FAILURE);
        } else if (pid != 0) {
            (void) close(fdsock);                   /* parent */
        } else {
            (void) close(fdbl);                     /* child */
            log_printf("LOG: httpd forked child pid=%i.\n", getpid());
            httpd6(fdsock, hit);                     /* no return */
        }
    }
}

