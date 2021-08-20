#include <stdio.h>
int main()
{
      int n,i,j,arrival[20],burst[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arrival[i]);
    for(i=0;i<n;i++)
        scanf("%d",&burst[i]);
    int wt[20], tat[20], total_wt = 0, total_tat = 0;
     wt[0] = 0;
    for (int i = 1; i < n ; i++)
    {
        wt[i] = burst[i-1] + wt[i-1] ;
    }
    for (int i = 0; i < n ; i++)
    {
        tat[i] = burst[i] + wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
 
    printf("%d",(float)total_wt / (float)n);
    printf("%d",(float)total_tat / (float)n);
    return 0;
}