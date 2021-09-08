#include<stdio.h>
int main()
{
    int n,arrival[20],burst[20],tempburst[20],wait,c=0,small=19;
    float awt;
    scanf("%d",&n);
    int process =n;
    for(int i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst[i]);
        tempburst[i]=burst[i];
    }
         
    burst[small]=9999;
    for(int t=0;c!=n;)
    {
        burst[small]=9999;
        for(int i=0;i<n;i++)
        {
            if(arrival[i]<=t && burst[i]<burst[small] && burst[i]>0 ) 
               small=i;
        }
               c++;
                t+=burst[small];
                burst[small]=0;
                wait+=t-arrival[small]-tempburst[small];  
    }
    awt=(float)wait/n;
    printf("%.2f",awt);
}