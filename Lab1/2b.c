#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int str_length(char str[]) {
	int count;

	for (count = 0; str[count] != '\0'; ++count);

	return count;
}


int main()
{


    FILE *stream = fopen("example_read.txt", "r");
    FILE *fptr = fopen("example_write.txt","w");

    char buffer[10000];
    ///int line_cunt = 0;
    while (fgets(buffer, sizeof buffer, stream) != NULL)
    {
        // process buffer
        ///printf("Line no# %d: %s", ++line_cunt, buffer);
        ///if(buffer[0] == '\n') printf("Empty line\n");

        if(buffer[0] == '\n') continue;

        int size_str = str_length(buffer);
        if(size_str==0) continue;
        if(buffer[0]!=' ')fprintf(fptr,"%c",buffer[0]);
        for(int i = 1;i<size_str;i++){
            if(buffer[i-1]==' ' & buffer[i]==' ') continue;
            fprintf(fptr,"%c",buffer[i]);
        }
    }

    if (feof(stream)) ;
    else ;

    fclose(stream);
    fclose(fptr);

   return 0;
}