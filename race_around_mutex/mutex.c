#include<stdio.h>
#include <pthread.h>

// void *hello_thread(void *arg){

// printf("Hello Thread \n");
// }
// void *bye_thread(void *arg){

// printf("Bye Thread \n");
// }
int count=10;
pthread_mutex_t mutexCount;
pthread_mutexattr_t mutexCountAttr; 


 void *inc_thread(void *arg){
     while (1)
     {
     pthread_mutex_lock(&mutexCount);
count++;
printf("inc count%d\n", count);
pthread_mutex_unlock(&mutexCount);

}
 }

 void *dec_thread(void *arg){
     while (1)
     {
pthread_mutex_lock(&mutexCount);
count--;
printf("dec count %d\n", count);
pthread_mutex_unlock(&mutexCount);
}}

int main(int argc, char const *argv[])
{
    pthread_t incID;
    pthread_t decID;
    printf("Main Thread \n");

    pthread_mutex_init(&mutexCount,&mutexCountAttr);

    // intialise mutex
    // close mutex 
    pthread_create(&incID, NULL, inc_thread, NULL);
    pthread_join(incID, NULL);
    pthread_create(&decID, NULL, inc_thread, NULL);
    pthread_join(decID, NULL);
    pthread_mutex_destroy(&mutexCount);
    return 0;
}

