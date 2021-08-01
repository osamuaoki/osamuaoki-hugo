#include "prime.h"

void subthread(thdata *thd) {
    long i;
    primelist *p=NULL, *q=NULL;
    thd->head = NULL;
    for (i = thd->n0; i <= thd->n1; i++) {
        if (checkprime(i)) {
            q = calloc(1, sizeof(primelist));
            q->prime = i;
            if (!thd->head) {
                thd->head = q;
                p = q;
            } else {
                p->next = q;
                p = q;
            }
            thd->tail = q;
        }
    }
}
