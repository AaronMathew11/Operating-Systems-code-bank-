#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid =fork(); // creates new process
    if(pid>0)
        sleep(50);  // Parent sleeps for 50 secs
    else
        exit(0);   // Child exits before the parent and becomes zombie
    return 0;
}