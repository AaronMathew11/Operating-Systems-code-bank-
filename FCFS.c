#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
int t[30],bt[30],wt[30],tt[30];
for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
}
for(int i=0;i<n;i++){
    scanf("%d",&bt[i]);
}
float avgwt=0;
float avgtt=0;
wt[0]=0;
    for(int i=1;i<n;i++){
    wt[i]=bt[i-1]+wt[i-1]+t[i-1]-t[i];
    }
for(int i=0;i<n;i++){
        tt[i]=bt[i]+wt[i];
    }    
for(int i=0;i<n;i++){
    avgwt=avgwt+wt[i];
}
avgwt=avgwt/n;
for(int i=0;i<n;i++){
    avgtt=avgtt+tt[i];
}
avgtt=avgtt/n;
printf("%.2f %.2f",avgtt,avgwt);
return 0;
}