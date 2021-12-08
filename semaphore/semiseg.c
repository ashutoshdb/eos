#include<stdio.h>
#include<strings.h>
#include<semaphore.h>
#include <pthread.h>

int a,b,sum;

sem_t s1,s2;

void *input_thread(void *arg){
    while (1)
    {
        sem_wait(&s1);
        scanf("%d", &a);
        scanf("%d", &b);
          sem_post(&s2);


    }
    
}

void *proc_thread(void *arg){
    while (1)
    {
         sem_wait(&s2);
        sum = a+b;
        printf("sum =%d", sum);
        sem_post(&s1);

    }
    
}
int main(int argc, char const *argv[])
{
    pthread_t inpID, procID;

    sem_init(&s1,0,1);
    sem_init(&s2,0,0);  
    pthread_create(&inpID, NULL, input_thread, NULL);
    pthread_create(&procID, NULL, proc_thread, NULL);
    pthread_join(inpID, NULL);
    pthread_join(procID, NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}
