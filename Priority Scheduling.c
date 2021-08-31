#include<stdio.h>
int main()
{
    int n,i,arrival[20],burst[20],priority[20],is_completed[20],start_time[20],turnaround[20],waiting[20],completion[20];
    int e=0,current_time=0,max=0,index=-1,avgtt,avgwt,total_wait=0,total_tt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(i=0;i<n;i++)
        scanf("%d",&burst[i]);
    for(i=0;i<n;i++)
        scanf("%d",&priority[i]);
    while(e!=n)
    {
        for(i=0;i<n;i++)
        {
            if(arrival[i]<=current_time && is_completed[i]==0)
            {
                if(priority[i]>max)
                {
                    max=priority[i];
                    index=i;
                }
                 if(priority[i]==max)
                {
                    if(arrival[i]<arrival[index])
                    {
                        max=priority[i];
                        index=i;
                    }
                }
            }
        }
         if(index!=-1)
        {
            start_time[index]=current_time;
            completion[index]=start_time[index]+burst[index];
            turnaround[index]=completion[index]-arrival[index];
            waiting[index]=turnaround[index]-burst[index];

            total_tt+=turnaround[index];
            total_wait+=waiting[index];

            is_completed[index]=1;
            e++;
            current_time=completion[index];
        }
        else{
            current_time++;
        }
    }
   
   avgtt=(float)total_tt/n;
   avgwt=(float)total_wait/n;
   printf("%d , %d",avgwt,avgtt);
}