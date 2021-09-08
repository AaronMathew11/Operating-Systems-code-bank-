#include<stdio.h>
int main()
{
    int n,arrival[20],burst[20],tempburst[20],wait,c=0,small,end;
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
         
    burst[19]=9999;
    for(int t=0;c!=n;t++)
    {
        small=19;
        for(int i=0;i<n;i++)
        {
            if(arrival[i]<=t && burst[i]<burst[small] && burst[i]>0 )
                  small=i;  
        }
      burst[small]--;
      if(burst[small]==0)
      {
            c++;
            end=t+1;
            wait+=end-arrival[small]-tempburst[small];
      }
        }

    awt=(float)wait/n;
    printf("%.2f",awt);
}