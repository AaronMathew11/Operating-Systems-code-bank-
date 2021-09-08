#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    char s[100];
    int consonant[25],count=0,flag=0;
    printf("Enter the sentence: \n");
    scanf("%[^\n]%*c",s);
    pid_t pid=fork();
    if(pid<0)
        perror("Fork not successful");
    else if(pid==0)
    {
        //Child process
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]!='a' || s[i]!='e' || s[i]!='i' || s[i]!='o' || s[i]!='u')
            {
                consonant[(int)s[i]-97]++;
                count++;
            }
        }
        for(int i=0;i<count;i++)
            if(consonant[i]>1)
            {
            printf("Not satisfying the required conditions");
            flag=1;
            break;
            }
        if(flag==0)
        printf("Conditions satisfied");
    }
    else
    wait(NULL);
    return 0;
}