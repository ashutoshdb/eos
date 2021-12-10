#include<stdio.h>
#include <pthread.h>
#include<semaphore.h>
/// binary


sem_t sem_count;
int arr1[2] = {1,2};
int arr2[2] = {1,2};
int arr3[2] = {1,2};
int arr4[2] = {1,2};

int * get_buffer(){
    sem_wait(&sem_count);
    return arr1;
}

int reecive_buff(){
    sem_post(&sem_count);
}



int main(int argc, char const *argv[])
{
    pthread_t helloID;
    pthread_t byeID;
    printf("Main Thread \n");
    // intialise mutex
    // close mutex 
    sem_init(&sem_count,0,4); 
    // second arguement is 0 if process is shared 
    pthread_create(&helloID, NULL, inc_thread, NULL);
    pthread_create(&byeID, NULL, dec_thread, NULL);
    pthread_join(byeID, NULL);
        pthread_join(helloID, NULL);
    sem_destroy(&sem_count);
    return 0;
}

