#include<stdio.h>
int main()
{
    int n,arrival[20],burst[20],priority[20],p,t,c=0,vip,wait,check=0;
    float avgwt;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&burst[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&priority[i]);
    for(t=0;c!=n;)
    {
        p=n;
        check=0;
        for(int i=0;i<n;i++)
            if(arrival[i]<=t && priority[i]<p && burst[i]!=0)
                {
                    vip=i;
                    check=1;
                }
                
        if(check=1)
        {
            c++;
            wait+=t-arrival[vip]-burst[vip];
            burst[vip]=0;
            t+=burst[vip];
        }
        else t++;
    }
    avgwt=(float)wait/n;
    printf("%d",avgwt);
}