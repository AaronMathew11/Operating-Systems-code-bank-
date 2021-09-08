#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int fd[2];
    int arr[20];
    int n,start,end;
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    //fd[0]- read
    //fd[1]- write
    if(pipe(fd)==-1)
        printf("Error in opening Pipe\n");
    pid_t pid = fork();
    if(pid<0)
        perror("Error in Fork\n");
    else if (pid==0)
        {
            //Child process
            start=0;
            end=n/2;
        }
    else
        {
            //Parent process
           start=n/2;
           end=n;
        }
    int sum=0;
    for(int i=start;i<end;i++)
        sum+=arr[i];
    
    printf("Calculated partial sum: %d\n",sum);

    if(pid==0)
    {
        close(fd[0]);
        if(write(fd[1],&sum,sizeof(int))==-1)
            printf("Error in writing process");
        close(fd[1]);
    }
    else
    {
        int value,totalsum;
        close(fd[1]);
        if(read(fd[0],&value,sizeof(int))==-1)
            printf("Error in reading process");
        totalsum+=value;
        printf("Final sum: %d",totalsum);
        wait(NULL);
    }
    return 0;
}