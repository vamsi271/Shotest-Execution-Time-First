#include<unistd.h>
#include<stdio.h>
//waiting time=wt;
//turn around time=tat;
int main()
{
  printf("Code by :- P harsha vardhan reddy ,reg : 11702405, roll : 52\n");
  printf("-------------------------------------------------------------\n");
  printf("CPU is idol for 3 unit times\n");
  printf("\n");
  sleep(3);
  int count,j,n,time,remain,flag=0,tq=1;
  int wt=0,tat=0,at[10],bt[10],rt[10];
  printf("Enter The Total Number of Process You Want To Execute:\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival_Time  %d :",count+1);
    scanf("%d",&at[count]);
    printf("Enter Burst_Time %d :",count+1);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("\n\nProcess\t|Turnaround_Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=tq && rt[count]>0)
    {
      time=time+rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=tq;
      time+=tq;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wt=wt+time-at[count]-bt[count];
      tat=tat+time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage_Waiting_Time= %f\n",wt*1.0/n);
  printf("Average_Turnaround_Time = %f",tat*1.0/n);
  return 0;
}

