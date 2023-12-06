#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char chr[1000];

    gets(chr);

    if(strlen(chr) < 8){
        printf("Password has to be minimum 8 characters");
        return 0;
    }

    int caps = 0 , lows = 0, digs = 0, sp = 0;

    for(int i = 0;i<strlen(chr);i++){
        if(chr[i]>=65 & chr[i]<=90) caps++;
        if(chr[i]>=97 & chr[i]<=122) lows++;
        if(chr[i]>=48 & chr[i]<=57) digs++;
        if(chr[i] == '_' | chr[i] == '$' | chr[i] == '#' | chr[i] == '@') sp = 1;
    }

    char *errors[10][2000];
    int e_index = 0;


    if(caps==0) *errors[e_index++] = (char*)"Uppercase Missing";
    if(lows==0) *errors[e_index++] = (char*)"Lowercase Missing";
    if(digs==0) *errors[e_index++] = (char*)"Digit Missing";
    if(sp==0) *errors[e_index++] = (char*)"Special Missing";


    if(caps*lows*digs*sp > 1) {
        printf("OK\n");
        return 0;
    }

    printf("%s",*errors[0]);
    for(int i = 1;i<e_index;i++) printf(", %s",*errors[i]);

    return 0;

}
