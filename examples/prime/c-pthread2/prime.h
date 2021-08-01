#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0
#define TMAX 64L

struct _primelist {
    long prime; 
    struct _primelist *next;
    };
typedef struct _primelist primelist;

extern primelist *head, *tail;

struct _thdata {
    pthread_t           th;
    long                n0;
    long                n1;
    primelist           *head;
    primelist           *tail;
};
typedef struct _thdata thdata;

extern thdata       thd[TMAX];

int checkprime(long n);
void subthread(thdata *thd);
int main(int argc, char **argv);
