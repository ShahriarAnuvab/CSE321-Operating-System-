#include<stdio.h>
#include <fcntl.h>

char filename[100];
char strinp[1000];
char strtowrite[1000];

int main()
{

    scanf("%s", &filename);

	int fd1 = open(filename, O_CREAT | O_WRONLY );
	if (fd1 ==-1) {
		printf("File(fd1) open failed\n");
		return 0;
	}
	printf("Opened the fd1 = % d\n", fd1);

    scanf("\n");
	fgets(strinp, sizeof(strinp) , stdin);
	while(1){
        if (strinp[0]=='-' & strinp[1]=='1' & strinp[2]=='\n') break;
        strcat(strtowrite , strinp);
        fgets(strinp, sizeof(strinp) , stdin);
	}

    write(fd1 , strtowrite , strlen(strtowrite));

	if (close(fd1) ==-1) {
		printf("File(fd1) close was unsuccessful\n");
		return 0;
	}
	printf("closed the fd1.\n");


	return 0;
}
