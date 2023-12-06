#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{


    int f = fork();
    if(f <  0){
        printf("Error\n");
        return 0;
    }
    else if(f == 0){
        char *args[] = { NULL};
        execvp("./sort", args);
    }
    else{
        wait(NULL);
        char *args[] = { NULL};
        execvp("./oddeven", args);
    }


    return 0;
}

/**
gcc -o SysCallTask4 SysCallTask4.c
./SysCallTask4
**/
