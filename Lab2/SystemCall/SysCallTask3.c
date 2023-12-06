#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t p;
    ///printf("before fork\n");
    p=fork();
    if(p <0) {
        printf("error");
    }
    else if(p==0)
    {
        if(getpid() % 2 == 1){
            pid_t q = fork();
            if(q<0){
                printf("error");
            }
            else if(q==0){
                printf("grandchild's process id = %d\n",getpid() );
            }
            else {
                wait(NULL);
            }
        }
        printf("child's process id = %d\n",getpid() );
    }
    else{
        wait(NULL);
        printf("parent's pid = %d\n", getpid());
        if(getpid() %2 == 0) printf("%d\n", 3);
        else printf("%d\n", 2);

    }
    ///printf("Common\n");
    return 0;
}

/**
gcc -o SysCallTask3 SysCallTask3.c
./SysCallTask3
**/
