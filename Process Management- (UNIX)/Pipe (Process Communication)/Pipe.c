#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int fd[2];
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
            close(fd[1]);
            char recievedmessage[100];
            if(read(fd[0],&recievedmessage,sizeof(char[100]))==-1)
                perror("Error in Reading process\n");
            printf("This is the child , PID: %d\n",getpid());
            printf("message recieved:\n");
            puts(recievedmessage);
            close(fd[0]);
        }
        else
        {
            //Parent process
            close(fd[0]);
            char messagetosend[100];
            printf("Welcome to the parent, PID: %d\n",getpid());
            printf("Enter the message you wish to send to the Child:\n");
            scanf("%[^\n]%*c",messagetosend);
            if(write(fd[1],&messagetosend,sizeof(char[100]))==-1)
                perror("Error in writing process\n");
            close(fd[1]);
        }
        return 0;
}