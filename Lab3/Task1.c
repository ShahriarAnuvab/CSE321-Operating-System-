#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int arrival[10000];
int   burst[10000];

int cmpfunc (const void * a, const void * b) {
    return ( arrival[*(int*)a] - arrival[*(int*)b] );
}
///qsort(array, 5, sizeof(int), cmpfunc);

int finishtime[10000], inexecution[10000], finished[10000];
int inf = 100000000;

void clear_arrays(){

    for(int i = 0;i<10000;i++){
        arrival[i] = 0, burst[i] = 0, finishtime[i] = 0, inexecution[i] = 0, finished[i] = 0;
    }

}

int main () {
    int n;

    clear_arrays();

    scanf("%d", &n);
    for(int i = 1;i<=n;i++) {
        scanf("%d", &arrival[i]);
        scanf("%d", &burst[i]);
    }



    int current = -1;
    int t = 0;
    int told ;
    int finishedcnt = 0;

    while(finishedcnt < n){
        told = t;
        if(current == -1){
            int burst1 = inf;
            for(int i = 1;i<=n;i++){
                if(finished[i]==0 && arrival[i] <= t){
                    if(burst[i]<burst1){
                        burst1 = burst[i];
                        current = i;
                    }
                }
            }
            if(current == -1){
                int arrival1 = inf;
                burst1 = inf;
                for(int i = 1;i<=n;i++){
                    if(finished[i]==0 && arrival[i] <= arrival1){
                        if(burst[i]<burst1){
                            arrival1 = arrival[i];
                            burst1 = burst[i];
                            current = i;
                        }
                    }
                }
                t = fmax(t, arrival1);
            }
        }

        printf("process %d at time: %d\n",current, t );
        ///
        int temp[10000];
        int tempcnt = 0;;
        for(int i = 1;i<=n;i++){
            if(finished[i] == 0 && i!=current && (arrival[i]>=t && arrival[i]<t +burst[current])){
                temp[tempcnt++] = i;
            }
        }

        qsort(temp, tempcnt, sizeof(int), cmpfunc);
        printf("Candidates till time = %d:\n",t +burst[current]);
        for(int i = 0;i<tempcnt;i++) printf("%d ", temp[i]);
        printf("\n");
        int choosen = -1;
        for(int i = 0;i<tempcnt;i++){
            if( burst[temp[i]] < burst[current] - (arrival[temp[i]]-t) ) {
                choosen = temp[i];
                break;
            }
        }
        /// arrival
        /// burst, finishtime, inexecution, finished
        /// t, finishedcnt, current

        if(choosen==-1){
            finishtime[current] = t + burst[current];
            inexecution[current] += burst[current];
            t = t + burst[current];
            burst[current] = 0;
            finished[current] = 1;
            finishedcnt++;
            printf("process %d finished at time: %d\n",current, t );
            printf("%d to %d: %d\n", told,t,current);
            current  = -1;

        }
        else{
            inexecution[current] += arrival[choosen] - t;
            burst[current] -= arrival[choosen] - t;
            t = t + arrival[choosen] - t;
            printf("%d to %d: %d\n", told,t,current);
            current = choosen;
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
