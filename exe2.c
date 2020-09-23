//
//  main.c
//  exe1.2
//
//  Created by НУРИЯ on 9/23/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void clrscr(){
    system("@cls||clear");
};
int main() {
    clrscr();
    int num, temp, tt=0, min=0;
    int d=0; // i=0; j=0;
    float average_turnaround_time=0, average_wait_time=0;
    float totalTAT=0; totalTAT=0;
    
    printf("\nEnter the number of processes: ");
    scanf("%d", &num);
    
    int bt[20]={0}, at[20]={0}, tat[20]={0}, wt[20]={0}, exitTime[20]={0};
    
    for(int i=0; i<num; i++){
        printf("Arrival time of process[%d]: ", i+1);
        scanf("%d", &at[i]);
        printf("\nBurst time of process[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }
    
// comparing the processes according to their burst time
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            if(bt[i]>bt[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
    }
}

    min=at[0];
 
    for(int i=0; i<num; i++){
        if(min>at[i]){
            min=at[i];
            d=i;
            
        }
    }
    tt=min;
    exitTime[d]=tt+bt[d];
    tt=exitTime[d];
    
    for(int i=0; i<num; i++){
        if(at[i]!=min){
            exitTime[i]=bt[i]+tt;
            tt=exitTime[i];
        }
    }
    for(int i=0; i<num; i++){
        tat[i]=*(exitTime-at[i]);
        totalTAT=totalTAT+tat[i];
        wt[i]=tat[i]-bt[i];
        totalTAT=totalTAT+wt[i];
    }
    average_turnaround_time=totalTAT/num;
    average_wait_time=totalTAT/num;
    printf("Process Arrival-time(s) Burst-time(s) Waiting time(s) Turnaroud time(s)\n");
    for(int i=0; i<num; i++){
        printf("Average Waiting Time=%f\nAverage turnaround time=%f", average_wait_time, average_turnaround_time);
       
    }
}
