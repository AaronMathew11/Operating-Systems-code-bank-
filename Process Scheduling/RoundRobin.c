#include<stdio.h>
void main()
{
    int n,qt,t,totalTime=0,c=0,po=0;
    scanf("%d",&n);
    scanf("%d",&qt);
    int at[20],bt[20],wt[20],cbt[20],p[20];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        p[i]=0;
    }
    double awt=0.0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        totalTime+=bt[i];
        cbt[i]=bt[i];
    }
    t=at[0];
    for(int i=0;i<n;i++)
    if(t>at[i])
    t=at[i];
    totalTime+=t;
    for(int i=0;i<n-1;i++)
    {
        int temp;
        for(int j=i+1;j<n;j++)
        {
           if(at[i]>at[j])
           {
               temp=at[i];
               at[i]=at[j];
               at[j]=temp;
               temp=bt[i];
               bt[i]=bt[j];
               bt[j]=temp;
           }
        }
    }
    while(t<totalTime)
    {
        for(int i=0;i<n;i++)
        {
            if(at[i]<=t && bt[i]>0 && p[i]==0)
            {
                c++;
                p[i]=c;
            }
        }
        t+=qt;
        p[po]=++c;
        int l=999;
        for(int i=0;i<n;i++)
        {
            if(p[i]<l && p[i]!=0 && bt[i]>0)
            {
                l=p[i];
                po=i;
            }
        }
        bt[po]-=qt;
        if(bt[po]<=0)
        {
            t+=bt[po];
            wt[po]=t-at[po]-cbt[po];
        }
    }
    for(int i=0;i<n;i++)
    awt+=wt[i];
    awt/=n;
    printf("%f",awt);
}