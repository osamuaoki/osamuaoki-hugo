/* vi:set ts=4 sts=4 expandtab: */
#include <stdio.h>          /* [fs]printf */
#include <stdlib.h>         /* exit getpid getenv */
#include <string.h>         /* strncmp */
#include <unistd.h>         /* lseek read write fork sleep */
#include <sys/types.h>      /* lseek getpid BSD_portability */
#include <errno.h>          /* errno */
#include <fcntl.h>          /* open close */
#include <signal.h>         /* sigaction */
#include <sys/socket.h>     /* socket bind listen accept */
#include <arpa/inet.h>      /* htonl htons */

#define WEB_ROOT    "public_html/"
#define LOG_FILE    "httpd6.log"
#define MAXFD       32
#define MAXBACKLOG  64
#define PIPE_BUF    (8*1024)

/* provide "FILE *f;" by the caller routine */
/* ## is GNU extension to allow zero __VA_ARGS__ */
#define log_printf(fmt, ...)  \
    f = fopen(LOG_FILE, "a");\
    (void) fprintf(f, fmt, ##__VA_ARGS__);\
    (void) fflush(f);\
    fclose(f);\
    sync();

void httpd6(int fdsock, int hit);
int main (int argc, char **argv);
