#include "thread.h"
#include "common.h"

#define MAX_COUNTER 20

void thread_a_counter()
{
    pthread_mutex_lock(mutex);
    while (counter < MAX_COUNTER)
    {
        counter++;
        printf("in %s counter is %d.\n", __func__, counter);
    }
    counter = 0;
    pthread_mutex_unlock(mutex);
}

void thread_b_counter()
{
    pthread_mutex_lock(mutex);
    while (counter < MAX_COUNTER)
    {
        counter++;
        printf("in %s counter is %d.\n", __func__, counter);
    }
    counter = 0;
    pthread_mutex_unlock(mutex);
}

int threads_handler()
{
    int err = 0;
    pthread_t thread_a;
    pthread_t thread_b;
    pthread_create(&thread_a, NULL, thread_a_counter, NULL);
    pthread_create(&thread_b, NULL, thread_b_counter, NULL);
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    return err;
}