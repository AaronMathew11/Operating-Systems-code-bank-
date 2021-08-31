#include<stdio.h>
int main()
{
    int n,i,j,k=1,t,b=0,min,arrival[20],burst[20],priority[20],is_completed[20],start_time[20],turnaround[20],waiting[20],completion[20],temp[20];
    int e=0,current_time=0,max=0,index=-1,avgtt,avgwt,total_wait=0,total_tt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(i=0;i<n;i++)
        scanf("%d",&burst[i]);
    for(i=0;i<n;i++)
        scanf("%d",&priority[i]);
    
    for(i=0;i<n;i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(arrival[i]<arrival[j])
            {
                t=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=t;

                t=burst[i];
                burst[i]=burst[j];
                burst[j]=t;
            }
        }   
    }

    for(j=0;j<n;j++)
    {
        b+=burst[j];
        min=burst[k];
        for ( i = k; i < n; i++)
        {
            min=priority[k];
            if(b<=arrival[i])
            {
                if()
            }
        }
        
    }
}