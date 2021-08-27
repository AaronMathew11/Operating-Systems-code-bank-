#include <stdio.h>
int main()
{
    int n,i,j,arrival[20],burst[20],priority[20],wt[20],tt[20],pos,temp;
    float avgwt=0.0,avgtt=0.0;
    wt[0]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(i=0;i<n;i++)
        scanf("%d",&burst[i]);
    for(i=0;i<n;i++)
        scanf("%d",&priority[i]);
    for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(priority[j]<priority[i])
                    {
                         temp=priority[i];
                         priority[i]=priority[pos];
                         priority[pos]=temp;

                          temp=burst[i];
                          burst[i]=burst[pos];
                          burst[pos]=temp;
                          
                          temp=arrival[i];
                          arrival[i]=arrival[pos];
                          arrival[pos]=temp;
                    }
                else if(priority[j]==priority[i])
                    {
                        if(arrival[j]<arrival[i])
                            {
                              temp=priority[i];
                              priority[i]=priority[pos];
                              priority[pos]=temp;
      
                               temp=burst[i];
                               burst[i]=burst[pos];
                               burst[pos]=temp;
                               
                               temp=arrival[i];
                               arrival[i]=arrival[pos];
                               arrival[pos]=temp;   
                            }
                      
                    }
            }
        }
        
        for(i=1;i<n;i++)
        {
            wt[i]=burst[i-1]+arrival[i-1]+wt[i-1]-arrival[i];
        }
        for(i=0;i<n;i++)
            tt[i]=burst[i]+wt[i];
        for(i=0;i<n;i++)
            avgwt+=wt[i];
        avgwt/=n;
        for(i=0;i<n;i++)
            avgtt+=tt[i];
        avgtt/=n;
        printf("%.2f %.2f",avgtt,avgwt);
        
    return 0;
}