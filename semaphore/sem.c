#include<stdio.h>
#include <pthread.h>
#include<semaphore.h>
/// binary


int count = 10;
sem_t sem_count;




 void *inc_thread(void *arg)
 {
     while (1)
     {
         sem_wait(&sem_count);
    count++;
    printf("inc count %d \n", count);
    sem_post(&sem_count);

    }
}

 void *dec_thread(void *arg)
 {
     while (1)
     {
sem_wait(&sem_count);
    count--;
    printf("dec count %d\n", count);
    sem_post(&sem_count);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t helloID;
    pthread_t byeID;
    printf("Main Thread \n");
    // intialise mutex
    // close mutex 
    sem_init(&sem_count,0,1); 
    // second arguement is 0 if process is shared 
    pthread_create(&helloID, NULL, inc_thread, NULL);
    pthread_join(helloID, NULL);
    pthread_create(&byeID, NULL, inc_thread, NULL);
    pthread_join(byeID, NULL);
    sem_destroy(&sem_count);
    return 0;
}

