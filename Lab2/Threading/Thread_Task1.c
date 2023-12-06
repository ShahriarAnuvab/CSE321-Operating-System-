#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* thread_function(void* i)
{
    int *i1 = (int*)i;
    printf("thread-%d running\n", *i1);
    return NULL;
}

int main()
{

    pthread_t thread1[5];
    for(int i = 1;i<=5;i++){
        pthread_create(&thread1[i-1], NULL, thread_function, &i);
        pthread_join(thread1[i-1], NULL);
        printf("thread-%d closed\n", i);
    }

    return 0;
}

/**
gcc -o Thread_Task1 Thread_Task1.c -pthread
./Thread_Task1
**/
