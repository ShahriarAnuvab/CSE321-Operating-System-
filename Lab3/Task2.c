#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int  arrival[10000];
int    burst[10000];

int quantum, n;

int finishtime[10000], inexecution[10000], finished[10000];
int inf = 100000000;

void clear_arrays(){

    for(int i = 0;i<10000;i++){
        arrival[i] = 0, burst[i] = 0, finishtime[i] = 0, inexecution[i] = 0, finished[i] = 0;
    }

}

int main () {


    clear_arrays();

    scanf("%d", &n);
    scanf("%d", &quantum);
    for(int i = 1;i<=n;i++) {
        scanf("%d", &burst[i]);
    }



    int current = -1;
    int t = 0;
    int told ;
    int finishedcnt = 0;

    while(finishedcnt < n){
        int shortest_burst_time = inf;
        for(int i = 1;i<=n;i++){
            if(finished[i]!=0) continue;
            if(burst[i] < shortest_burst_time) {
                shortest_burst_time =burst[i];
            }
        }
        for(int k = 0;k<shortest_burst_time/quantum;k++){
            for(int i = 1;i<=n;i++){
                if(finished[i]!=0) continue;
                told = t;
                t=t+quantum;
                printf("%d to %d: process#%d\n",told,t,i);
                inexecution[i] += quantum;
                burst[i] -= quantum;
                if(burst[i] == 0){
                    finished[i] = 1;
                    finishtime[i] = t;
                    finishedcnt++;
                }
            }
        }
        if(shortest_burst_time%quantum == 0) continue;
        for(int i = 1;i<=n;i++){
                if(finished[i]!=0) continue;
                if(burst[i]>quantum){
                    told = t;
                    t=t+quantum;
                    printf("%d to %d: process#%d\n",told,t,i);
                    inexecution[i] += quantum;
                    burst[i] -= quantum;
                }
                else{
                    told = t;
                    t = t + burst[i];
                    printf("%d to %d: process#%d\n",told,t,i);
                    inexecution[i] += burst[i];
                    burst[i] = 0;
                    finished[i] = 1;
                    finishtime[i] = t;
                    finishedcnt++;
                }
        }


    }

    printf("Completion time:\n");
    for(int i = 1;i<=n;i++){
        printf("For process %d: %d\n", i , finishtime[i]);
    }


    printf("Turn around time:\n");
    double avtat = 0.0;
    for(int i = 1;i<=n;i++){
        printf("For process %d: %d\n", i , finishtime[i] - arrival[i]);
        avtat += (finishtime[i] - arrival[i])*1.0;
    }

    printf("Waiting time:\n");
    double avw = 0.0;
    for(int i = 1;i<=n;i++){
        printf("For process %d: %d\n", i , finishtime[i] - arrival[i] - inexecution[i]);
        avw += (finishtime[i] - arrival[i] - inexecution[i])*1.0;
    }

    printf("Average turn around time: %f\n", avtat / n);
    printf("Average waiting time: %f\n", avw / n);

    return 0;
}
