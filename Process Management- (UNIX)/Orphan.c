#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid= fork();

    if(pid>0)
        exit(0); //Parent process exits before child
    else if(pid==0)
        sleep(60);  //Child sleeps for 60 seconds

    return 0;

}