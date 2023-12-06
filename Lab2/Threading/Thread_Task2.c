#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
void* func(void* arg)
{
    /// Codes here
    return NULL;
}
**/

struct arg_struct {
    int thread_no;
    int x;
};

void *print_the_arguments(void *arguments)
{
    struct arg_struct *args = arguments;
    printf("Thread %d prints %d\n", args -> thread_no, args -> x);
    pthread_exit(NULL);
    return NULL;
}
int main()
{

    pthread_t thread1[5];
    int k = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            struct arg_struct args;
            args.thread_no = i;
            args.x = ++k;


            pthread_create(&thread1[i], NULL, print_the_arguments, (void*)&args);

            pthread_join(thread1[i], NULL);
        }

    }

    return 0;
}

/**
gcc -o Thread_Task2 Thread_Task2.c -pthread
./Thread_Task2
**/
