/* vi:set ts=4 sts=4 expandtab: */
#include "common.h"

void httpd6(int fdsock, int hit)
{
    char buf[PIPE_BUF +1];
    FILE *f;              /* for log_printf */
    ssize_t r, i, j;
    size_t l, m;
    int fd, k;
    struct pair {
        char *ext;
        char *filetype;
    };
    struct pair extlist[] = {
            {"html", "text/html" },
            {"htm",  "text/html" },
            {"css",  "text/css" },
            {"js",   "text/javascript" },
            {"jpeg", "image/jpeg"},
            {"jpg",  "image/jpg" },
            {"png",  "image/png" },
            {"gif",  "image/gif" },
            {"ico",  "image/ico" },
            {"gz",   "image/gz"  },
            {"xz",   "image/xz"  },
            {"tar",  "image/tar" },
            {"zip",  "image/zip" },
            {NULL, NULL}};
    /* messages */
    char *mes403 = 
"HTTP/1.1 403 Forbidden\nContent-Length: 185\n"
"Connection: close\n"
"Content-Type: text/html\n\n"
"<html><head>\n"
"<title>403 Forbidden</title>\n"
"</head><body>\n"
"<h1>Forbidden</h1>\n"
"The requested URL, file type or operation is forbidden on this webserver.\n"
"</body></html>\n";

    char *mes404 =
"HTTP/1.1 404 Not Found\nContent-Length: 136\n"
"Connection: close\n"
"Content-Type: text/html\n\n"
"<html><head>\n"
"<title>404 Not Found</title>\n"
"</head><body>\n"
"<h1>Not Found</h1>\n"
"The requested URL was not found on this server.\n"
"</body></html>\n";

    char *http_header =
"HTTP/1.1 200 OK\nServer: httpd\nContent-Length: %ld\n"
"Connection: close\n"
"Content-Type: %s\n"
"charset=utf-8\n\n";

    /* Start of the routine to handle the HTTP request*/
    r = read(fdsock, buf, PIPE_BUF);
    if (r == -1) {
        log_printf("ERROR: system call: read, "
                "%s, hit=%d exiting pid=%d.\n", strerror(errno), hit, getpid());
        exit(EXIT_FAILURE);
    }
    if (r == 0) {
        (void) write(fdsock, mes403, sizeof(mes403));
        log_printf("ERROR: 403 Forbidden: zero length request, "
                "hit=%d exiting pid=%d.\n", hit, getpid());
        exit(EXIT_FAILURE);
    }

    buf[r] = '\0';  /* null terminated */
    r++;            /* size of buf used */
    for (i = 0; i < r; i++) {
        if (buf[i] == '\r' || buf[i] == '\n') {
            buf[i] = '_';
        }
    }
    log_printf("READ(%d): %s\n", hit, buf);
    if (strncmp(buf, "GET ", 4) && strncmp(buf, "get ", 4)) {
        (void) write(fdsock, mes403, sizeof(mes403));
        log_printf("ERROR: 403 Forbidden: Only simple GET supported, "
                "hit=%d exiting pid=%d.\n", hit, getpid());
        exit(EXIT_FAILURE);
    }
    /* string is "GET /FILE_PATH " + other extras */
    for (i = 4; i < r; i++) {
        if (buf[i] == ' ') {
            if (buf[i - 1] == '/') {
                (void) strcpy(&buf[i], "index.html");
            } else {
                buf[i] = '\0';
            }
            break;
        }
    }
    for (j = 4; j < i - 1; j++) {
        if (buf[j] == '.' && buf[j + 1] == '.') {
            (void) write(fdsock, mes403, sizeof(mes403));
            log_printf("ERROR: 403 Forbidden: URL with \"..\" is illegal, "
                    "hit=%d exiting pid=%d.\n", hit, getpid());
            exit(EXIT_FAILURE);
        }
    }
    l = strlen(buf);
    for (k =0; extlist[k].ext != NULL; k++) {
        m = strlen(extlist[k].ext);
        if (!strncmp(&buf[l - m], extlist[k].ext, m)) {
            break;
        }
    }
    if (extlist[k].ext == NULL) {
        (void) write(fdsock, mes403, sizeof(mes403));
        log_printf("ERROR: 403 Forbidden: file extension type is illegal, "
                "hit=%d exiting pid=%d.\n", hit, getpid());
        exit(EXIT_FAILURE);
    }
    log_printf("SEND(%d): %s as %s\n", hit, &buf[5], extlist[k].filetype);
    fd = open(&buf[5], O_RDONLY); /* open the file for reading */
    if (fd == -1) {
        (void) write(fdsock, mes404, sizeof(mes404));
        log_printf("ERROR: 404 Not Found: failed to open file, "
                "hit=%d exiting pid=%d.\n", hit, getpid());
        exit(EXIT_FAILURE);
    }
    l = lseek(fd, (off_t)0, SEEK_END);      /* file length */
    (void) lseek(fd, (off_t)0, SEEK_SET);
    (void) sprintf(buf, http_header, l, extlist[k].filetype);
    (void) write(fdsock, buf, strlen(buf)); /* send header */
    while ((r = read(fd, buf, PIPE_BUF)) > 0) {
        (void) write(fdsock, buf, r);       /* send file in block */
    }
    sleep(1);               /* allow socket to drain before signal */
    close(fdsock);
    log_printf("CLOSE(%d)\n", hit);
    exit(EXIT_FAILURE);     /* terminate child */
}

