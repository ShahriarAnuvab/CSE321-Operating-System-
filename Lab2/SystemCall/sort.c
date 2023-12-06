#include <stdio.h>
#include <stdlib.h>

int values[1000];

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main () {
    int n;
    scanf("%d", &n);
    for(int i = 0;i<n;i++) scanf("%d", &values[i]);


    FILE *fwrite = fopen("transition_file.txt","w");

    fprintf(fwrite,"%d\n", n);

    qsort(values, n, sizeof(int), cmpfunc);
    for( int i = 0;i<n;i++ ) {
        ///fprintf("%d ", values[i]);
        fprintf(fwrite,"%d ", values[i]);
    }
    fprintf(fwrite,"\n");
    fclose(fwrite);

    return 0;
}

/**
gcc -o sort sort.c
./sort
**/
