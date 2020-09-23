//
//  main.c
//  exe1
//
//  Created by НУРИЯ on 9/22/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
//
#include<stdio.h>
 
int main()
{
    int at[20]={0}, bt[20]={0}, wt[20]={0},tat[20]={0}, ct[20]={0};
    int avrg_wt=0,avrg_tat=0,i,j;
    int n, s=0;
    float totTAT=0.0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
 
    printf("\nEnter arrival time and burst time:\n");
    
       for(i=0; i<n; i++) {
           printf("arrivalTime[%d]:\n", i+1);
           scanf("%d", &at[i]);
           printf("burstTime[%d]:\n", i+1);
           scanf("%d", &bt[i]);
       }
    
    for(j=0; j<n; j++){
        if(j==0) s+=at[0];
        s+=bt[j];
        ct[j]+=s;
        
    }
      // calculation on ta time 
    for(int k=0; k<n; k++) {
           tat[k]=ct[k]+at[k];
        tat[k]=ct[k]-at[k];
        totTAT+=tat[k];
       }
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    wt[0]=0;
    
    //calculation of waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    avrg_wt/=i;
    avrg_tat/=i;
    printf("\n\nAverage Waiting Time:%d\nAverage Turnaround Time:%d",avrg_wt,avrg_tat);

}
