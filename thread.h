#ifndef CBASICS_THREAD_H
#define CBASICS_THREAD_H

#include <pthread.h>

/*
 * threads_handler creates 2 threads looping on a counter to 20.
 */
int threads_handler();

int counter;
pthread_mutex_t mutex;

#endif //CBASICS_THREAD_H
