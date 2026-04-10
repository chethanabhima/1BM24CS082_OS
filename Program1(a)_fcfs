#include<stdio.h>

void main(){
   int n;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   int id[n],tempid;
   float at[n],bt[n],ct[n],tat[n],wt[n],cur_time=0,avgWT=0, avgTAT=0;
   float tempat, tempbt;
   printf("\nEnter the arrival time and the burst time for: \n");
   for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i);
        id[i]=i;
        scanf("%f",&at[i]);
        scanf("%f",&bt[i]);
   }
   for(int i=0;i<n-1;i++){
    if(at[i]>at[i+1]){
       tempat=at[i];
       at[i]=at[i+1];
       at[i+1]=tempat;

       tempbt=bt[i];
       bt[i]=bt[i+1];
       bt[i+1]=tempbt;

       tempid=id[i];
       id[i]=id[i+1];
       id[i+1]=tempid;
    }
   }
   for(int i=0;i<n;i++){
     if(cur_time<at[i]){
        cur_time=at[i];
     }
     ct[i]=cur_time+bt[i];
     tat[i]=ct[i]-at[i];
     wt[i]=tat[i]-bt[i];
     cur_time=ct[i];
   }

   //average
   for(int i=0;i<n;i++){
    avgWT+=wt[i];
    avgTAT+=tat[i];
   }
   avgWT/=n;
   avgTAT/=n;

   //display
   for(int i=0;i<n;i++){
    printf("\nProcess id %d:\n Arrival Time: %f\n Burst Time: %f\n Completion Time: %f\n Waiting Time: %f\n Turnaround Time: %f\n",id[i],at[i],bt[i],ct[i],wt[i],tat[i]);
   }
   printf("Average waiting time= %f",avgWT);
   printf("\nAverage turnaround time= %f", avgTAT);
}
