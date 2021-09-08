#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    printf("we are in the child process\n");
    printf("Process ID: %d",(int)getpid());
    for(int i=0;i<n;i++)
        printf("%s",argv[i]);
}