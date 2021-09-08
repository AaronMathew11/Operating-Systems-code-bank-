#include<stdio.h>
#include<pthread.h>

void* routine()
{
    printf("Test from threads\n");
    sleep(3);
    printf("Ending the thread\n");
}

int main(int argc, char *argv[])
{
    pthread__t t1,t2;   // all threads execute simultaniously
    if(pthread_create(&t1,NULL,&routine,NULL)!=0)
        printf("Error in Thread 1 creation");
    if(pthread_create(&t2,NULL,&routine,NULL)!=0)
        printf("Error in Thread 2 creation");
   if(pthread_join(t1,NULL)!=0)
        printf("Error in Join 1\n");
    if(pthread_join(t2,NULL)!=0)
        printf("Error in Join 2\n");
    return 0;
}