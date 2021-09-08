#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_CHILDREN 6

int main(int argc, char* argv[])
{
    for(int i=0;i<NUM_CHILDREN;i++)
    {
        pid_t pid =fork();
        if(pid<0)
        {
            perror("Fork Failed");
            exit(1);
        }
        if(pid==0)
        {
            //child process here
            char* args[]={'hello','from','the','child',NULL};
            execv('./child',args);
        }
    }
     // Parent Process here
     printf("Parent proecess is running\n");
     printf("Parent ID: %d",(int)getpid());
     for(int i=0;i<NUM_CHILDREN;i++)
        wait(NULL);
     return 0;
}
