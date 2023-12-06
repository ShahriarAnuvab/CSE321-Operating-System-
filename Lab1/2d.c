#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

   char email_id[500];
   gets(email_id);

   char * token = strtok(email_id, "@");

   char * tokens[10][500];
   int total_tokens = 0;

   while( token != NULL & total_tokens<10) {
      *tokens[total_tokens++] = token;
      token = strtok(NULL, " ");
   }

   if(total_tokens==2 & strcmp(*tokens[1], "kaaj.com") == 0 ) {
        printf("Email address is outdated\n");
   }


   else if(total_tokens==2 & strcmp(*tokens[1], "sheba.xyz") == 0 ) {
        printf("Email address is okay\n");
   }

   return 0;

}