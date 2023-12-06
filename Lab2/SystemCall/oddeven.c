#include <stdio.h>
#include <stdlib.h>

int values[1000];

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main () {



    FILE *fwrite = fopen("transition_file.txt","r");

    int n, num;
    fscanf (fwrite, "%d", &n);
    printf("%d\n", n);
    for(int i = 0;i<n;i++){
        fscanf (fwrite, "%d", &num);
        if(num%2 == 0) printf("%d is even\n", num);
        else printf("%d is odd\n", num);
        printf("%d\n", num);
    }

    return 0;
}

/**
gcc -o oddeven oddeven.c
./oddeven
**/
