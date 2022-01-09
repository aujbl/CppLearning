#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 100

//-D_RENNTRANT: 使用线程安全函数编译
long long num = 0;              //全局变量，线程安全函数无效；自增时可能同时进行了自减，导致结果出错
void *thread_inc(void *arg);
void *thread_des(void *arg);

int main(int argc)
{
    pthread_t thread_id[NUM_THREAD];
    int i;
    printf("sizeof long long: %ld \n", sizeof(long long));
    for (i = 0; i < NUM_THREAD; i++)
    {
        if (i%2)
            pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
        else
            pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
    }

    for (i = 0; i < NUM_THREAD; i++)
        pthread_join(thread_id[i], NULL);

    printf("result: %lld \n", num);
    return 0;
}

void *thread_inc(void *arg)
{
    int i;
    for (i = 0; i < 50000000; i++)
        num += 1;
    return NULL;
}

void *thread_des(void * arg)
{
    int i;
    for (i = 0; i < 50000000; i++)
        num -= 1;
    return NULL;
}