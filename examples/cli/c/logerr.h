#include <stdlib.h>
#include <stdio.h>

#ifdef NLOGERR
#define logerr(level,fmt,...)
#else
#define logerr(level,fmt, ...) \
if(level <= logerr_level) { \
    fprintf(stderr, "%s: %s:%d: ", \
        level >= 3 ? "D" : level == 2 ? "I" : level == 1 ? "N" : "W" , \
        __FILE__, __LINE__); \
    fprintf(stderr, fmt, ##__VA_ARGS__); \
    fflush(stderr); \
    } \
else /* the single statement cliche to avoid breaking if(...)-construct */
#endif

#define LOGERR_WARN        0       /* W: warning       always */
#define LOGERR_NOTICE      1       /* N: notice        -v */
#define LOGERR_INFO        2       /* I: informational -vv */
#define LOGERR_DEBUG       3       /* D: debug         -vvv */

int logerr_level = LOGERR_WARN;

