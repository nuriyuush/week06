//
//  main.c
//  exe3
//
//  Created by НУРИЯ on 9/24/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
// Nuriya Umirbekova exe3
#include<stdio.h>
int main() {
    int n=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", & n);
    
    int d=n;
    int i, x = 0, s, t_Quantum;
    int at[20]={0}, bt[20]={0};
    int tat[20]={0}, wt[20]={0}, tempry[20]={0};
    
    float totTAT=0.0, totWT=0;
    float avrg_turnaround_time, avrg_waiting_time=0;

    printf("\nEnter arrival time and burst time:\n");
    for(i=0; i<n; i++) {
        printf("arrivalTime[%d]:\n", i+1);
        scanf("%d", &at[i]);
        printf("burstTime[%d]:\n", i+1);
        scanf("%d", &bt[i]);
        tempry[i] = bt[i];
    }

    printf("\nEnter time quantum:\t");
    scanf("%d\n", &t_Quantum);
    
    for(s=0,i=0;d!=0;) {
        
        if (tempry[i]<=t_Quantum&&tempry[i]>0){
            s=s+tempry[i];
            tempry[i]=0;
            x=1;
        } else if (tempry[i]>0){
            tempry[i]=tempry[i]-t_Quantum;
            s=s+t_Quantum;
        }
        
        if(tempry[i]==0 && x==1) {
            d=d-1;
            tat[i]=s-at[i];
            wt[i]=s-at[i]-bt[i];
            totWT=totWT+s-at[i]-bt[i];
            totTAT=totTAT+s-at[i];
            x=0;
        }
        
        if(i==n-1) {
            i=0;
        } else if (at[i+1]<=s) {
            i++;
        } else {
            i=0;
        }
    }

    avrg_waiting_time=totWT/n;
    avrg_turnaround_time=totTAT/n;
    printf("\n");
    for (i=0; i<n; i++) {
        printf("Process %d\n  arrivalTime %d\n  burstTime %d\n  turnAroundTime %d\n  waitingTime %d\n", i+1, at[i], bt[i], tat[i], wt[i]);
    }
    
    printf("\nAverageTurnAroundTime:%f\nAverageWaitingTime:%f", avrg_turnaround_time, avrg_waiting_time);

}

//Conclusion from running and testing: FCFS, Short job and Round Robin are different scheduling algorithms.
//  In FCFS waiting time is much longer in comparison with other algorithms due to it performs as a queue, where all actions are made one after another according on the initial order.
//  In Short Job the algorithm is based on implementing shortest processes in first according to their busrt time, which makes work faster.
//  In round robin the time of return data is fastest due to a specialized time quantum.
