#include <stdio.h>

int n, m;               /// Number of processes and number of resources
int alloc[100][100];    /// Allocation Matrix
int max[100][100];      /// MAX Matrix
int avail[100];         /// Available Resources
int f[100];             /// Boolean array for finished processes
int ans[100];           /// Storing sequences
int ind;                /// Index for storing safe sequences


void initialize_variables(){

    n = m = ind = 0;

    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++) {
            alloc[i][j] = max[i][j] = 0;
        }
    }

    for(int j = 0;j<100;j++){
        avail[j] = f[j] = ans[j] = 0;
    }


}

int main()
{

    initialize_variables();

	scanf("%d", &n);
	scanf("%d", &m);

	for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) scanf("%d", &alloc[i][j]);
	}



	for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) scanf("%d", &max[i][j]);
	}


    for(int j = 0;j<m;j++) scanf("%d", &avail[j]);

	int f[n], ans[n];
	int ind = 0;
	for (int k = 0; k < n; k++) {
		f[k] = 0;
		ans[k] = -1;
	}

	int need[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}


	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	for(int i=0;i<n;i++) {
        if(f[i]==0)
        {

            printf("Deadlock Ahead\n");
            return 0;
        }
	}


    printf("Safe here\n");
    return 0;
}
