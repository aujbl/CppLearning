#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 100

                                //-D_RENNTRANT: 使用线程安全函数编译
long long num = 0;              //全局变量，线程安全函数无效；自增时可能同时进行了自减，导致结果出错
pthread_mutex_t mutex;          //互斥量
                                //使用mutex保护临界资源,保护线程导致等待时间变长

void *thread_inc(void *arg);
void *thread_des(void *arg);

int main(int argc)
{
    pthread_t thread_id[NUM_THREAD];
    int i;
    pthread_mutex_init(&mutex, NULL);        //初始化

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
    pthread_mutex_destroy(&mutex);      //销毁
    return 0;
}

void *thread_inc(void *arg)
{
    int i;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < 50000000; i++)
        num += 1;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *thread_des(void * arg)
{
    int i;
    pthread_mutex_lock(&mutex);             //减少调用互斥量可以减少等待时间
    for (i = 0; i < 50000000; i++)
    {
        // pthread_mutex_lock(&mutex);      //频繁调用互斥量会导致程序非常慢
        num -= 1;
        // pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}