#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define t 100
sem_t room;
sem_t stick[t];

void philosopher(void);
void eat(int);
int n;

void *philosopher(void * num)
  {
      int phil =(int) num;
      printf("\nPhilosspher %d has entered room",phil);
      sem_wait(&stick[phil]);
      sem_wait(&stick[(phil+1)%n]);
      eat(phil);
      sleep(2);
      printf("\nPhilosopher %d has finished eating" ,phil);
      sem_post(&stick[(phil+1)%n]);
      sem_post(&stick[phil]);
      sem_post(&room);  
  }
    void eat(int phil)
    {
        printf("\nPhilosopher %d is eating ",phil);
        
    }

int main(){
    
    scanf("%d",&n);
    int i,a[n];
    pthread_t tid[n];
    
    sem_init(&room,0,n-1);
    for(i=0;i<n;i++){
        sem_init(&stick[i],0,1);
    
    }
    for(i=0;i<n;i++){
        a[i]=i;
        pthread_create(&tid[i],NULL,philosopher,(void*)&a[i]);
    }
    for(i=0;i<n;i++)
        pthread_join(tid[i],NULL);
} 
    
  