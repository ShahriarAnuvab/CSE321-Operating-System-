#include <stdio.h>
#include <stdlib.h>



int main(){

    int a,b;
    char c[100];

    scanf("%d %d %s", &a, &b, &c);

    ///printf("%d\n", a);
    ///printf("%d\n", b);
    ///printf("%s\n", c);


    if(a>b) printf("%d" , a-b);
    else if(a<b) printf("%d" , a+b);
    else printf("%d" , a*b);

    return 0;
}
