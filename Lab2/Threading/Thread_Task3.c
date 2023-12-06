#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int str_length(char str[]) {
	int count;
	for (count = 0; str[count] != '\0'; ++count);
	return count;
}



struct name{
    char c[20];
};


void *myThreadFunction(void *arguments)
{
    struct name *args = arguments;
    int sum = 0;
    for(int i = 0;i<sizeof(args->c) & args->c[i]!='\0';i++) sum += args->c[i];

    int* result = malloc(sizeof(int));
    *result = sum;
    return (void*)result;
}

int main()
{
    struct name n1, n2, n3;
    scanf("%s", &n1.c);
    scanf("%s", &n2.c);
    scanf("%s", &n3.c);

    pthread_t thread1[3];
    int* returned_value;
    int a,b,c;

    pthread_create(&thread1[0], NULL, myThreadFunction, (void*)&n1);
    pthread_join(thread1[0], (void**)&returned_value);
    a = *returned_value;
    free(returned_value);

    pthread_create(&thread1[1], NULL, myThreadFunction, (void*)&n2);
    pthread_join(thread1[1], (void**)&returned_value);
    b = *returned_value;
    free(returned_value);

    pthread_create(&thread1[2], NULL, myThreadFunction, (void*)&n3);
    pthread_join(thread1[2], (void**)&returned_value);
    c = *returned_value;
    free(returned_value);

    if(a==b && b==c) printf("Youreka\n");
    else if(a==b | b==c | a==c) printf("Miracle\n");
    else printf("Hasta la vista\n");

    return 0;
}

/**
gcc -o Thread_Task3 Thread_Task3.c -pthread
./Thread_Task3
**/
