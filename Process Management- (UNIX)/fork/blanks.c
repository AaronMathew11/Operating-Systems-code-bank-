#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<uinstd.h>
int main()
{
    char s[20];
    printf("Enter the string:\n")
    scanf("%[^\n]%*c",s);
    pid_t pid =fork();
    if(pid<0)
        perror("FORK FAILED");
    else if(pid==0)
    {
        //child process
        for(int i=0; s[i]!='\0';i++)
        {
            if(s[i]!=' ')
                printf("%c",s[i]);
            if(s[i]==' ' && s[i-1]!=' ')
                printf(" ");
        }
    }
    else
    wait(NULL);
    return 0;
}