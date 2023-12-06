#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t p;
    p=fork();
    if(p <0) {
        printf("error");
        return 0;
    }
    else if(p==0){
        pid_t q = fork();
        if(q < 0){
            printf("error");
            return 0;
        }
        else if(q==0){
            printf("I am grandchild\n");
        }
        else {
            wait(NULL);
            printf("I am child\n");
        }
    }
    else {
        wait(NULL);
        printf("I am parent\n");
    }

    return 0;
}

/**
gcc -o SysCallTask2 SysCallTask2.c
./SysCallTask2

**/
