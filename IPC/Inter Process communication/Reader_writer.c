#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

sem_t x,y;
pthread_t tid;
pthread_t wthreads[100],rthreads[100];

int readercount=0;


void *reader(void *param)
{
    sem_wait(&x);
    readercount++;
    if(readercount==1)
        sem_wait(&y);
    sem_post(&y);
    printf("%d reader is inside\n",readercount);
    usleep(4);
    sem_wait(&x);
    readercount--;
    if(readercount==0)
        sem_post(&y);
    sem_post(&x);
    printf("%d Reader is leaving \n",readercount+1);
    return NULL;
    
}

void *writer(void *param)
{
    printf("Writer is trying to enter \n");
    sem_wait(&y);
    printf("writer has entered");
    sem_post(&y);
    printf("Writer is leaving \n");
    return NULL; 
}

int main(){
    int n2,i;
    scanf("%d",&n2);
    int n1[n2];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n2;i++){
        pthread_create(&wthreads[i],NULL,reader,NULL);
        pthread_create(&rthreads[i],NULL,writer,NULL);    
    }
    for(i=0;i<n2;i++){
        pthread_join(wthreads[i],NULL);
        pthread_join(rthreads[i],NULL);   
    }
}