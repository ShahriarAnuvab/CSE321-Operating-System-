#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

/**
A call to wait() blocks the calling process until one of its child processes
exits or a signal is received. After child process terminates, parent
continues its execution after wait system call instruction.

Child process may terminate due to any of these:
(*) It calls exit()
(*) It returns (an int) from main
(*) It receives a signal (from the OS or another process) whose default
action is to terminate.
**/

int main()
{
    printf("Parent process ID:%d\n",getpid());
    pid_t p;
    p=fork();
    if(p <0) {
        printf("error");
        return 0;
    }
    else if(p==0)
    {
        printf("Child process ID:%d\n",getpid());
        pid_t q;

        q = fork();
        if(q < 0){
            printf("error");
            return 0;
        }
        else if(q==0){
            printf("Grand Child process ID:%d\n",getpid());
            return 0;
        }
        else{
            wait(NULL);
        }

        q = fork();
        if(q < 0){
            printf("error");
            return 0;
        }
        else if(q==0){
            printf("Grand Child process ID:%d\n",getpid());
            return 0;
        }
        else{
            wait(NULL);
        }

        q = fork();
        if(q < 0){
            printf("error");
            return 0;
        }
        else if(q==0){
            printf("Grand Child process ID:%d\n",getpid());
            return 0;
        }
        else{
            wait(NULL);
        }

    }
    else{
        wait(NULL);
    }

    return 0;
}

/**
gcc -o SysCallTask5 SysCallTask5.c
./SysCallTask5
**/
