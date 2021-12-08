#include<stdio.h>
#include <pthread.h>

int count;
pthread_mutex_t mutexCount;
pthread_mutexattr_t mutexCountAttr; // to set the type of mutex we intilase the attribute

 void *square(){
     while (1)
     {
     pthread_mutex_lock(&mutexCount);
     count = count*count;
     }
 }

 void *inc_thread(void *arg){
     while (1)
     {
     pthread_mutex_lock(&mutexCount);
     count++;
// deadlock condition because two lock is called one bye square and other is inc
printf(" inc count %d\n", count);
pthread_mutex_unlock(&mutexCount);

}
 }

 void *dec_thread(void *arg){
     while (1)
     {
pthread_mutex_lock(&mutexCount);
count--;
  square();
printf(" dec count %d  \n", count);
pthread_mutex_unlock(&mutexCount);
}}

int main(int argc, char const *argv[])
{
    pthread_t helloID;
    pthread_t byeID;
    printf("Main Thread \n");
   pthread_mutexattr_init(&mutexCountAttr); // intailise default futex then change type
   pthread_mutexattr_settype(&mutexCountAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexCount,&mutexCountAttr);

    // intialise mutex
    // close mutex 
    pthread_create(&helloID, NULL, inc_thread, NULL);
    pthread_join(helloID, NULL);
    pthread_create(&byeID, NULL, inc_thread, NULL);
    pthread_join(byeID, NULL);
    pthread_mutex_destroy(&mutexCount);

    return 0;
}

