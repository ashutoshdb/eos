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
    if(sem_count.__align == 4)
    {

    return arr1;
    }
    else if(sem_count.__align == 3)
    {
     
    return arr2;
    }
    else if(sem_count.__align == 2)
    {
      
    return arr3;
    }
    else if(sem_count.__align == 1)
    {
        
    return arr4;
    }
}

int reecive_buff(){
    sem_post(&sem_count);
}

 void *inc_thread(void *arg)
 {
    printf("thread %s \n", arg);
    sem_wait(&sem_count);
    printf("%ld \n",sem_count.__align);
    get_buffer();
    // sem_post(&sem_count);

}
 void *two_thread(void *arg)
 {
    printf("thread %s \n", arg);
    sem_wait(&sem_count);
    printf("%ld \n",sem_count.__align);
    get_buffer();
//    sem_post(&sem_count);

}
 void *three_thread(void *arg)
 {
    printf("thread %s \n", arg);
    sem_wait(&sem_count);
    printf("%ld \n",sem_count.__align);
    get_buffer();
    // sem_post(&sem_count);

}
 void *four_thread(void *arg)
 {
    printf("thread %s \n", arg);
    sem_wait(&sem_count);
    printf("%ld \n",sem_count.__align);
    get_buffer();
    // reecive_buff();

}
 void *five_thread(void *arg)
 {
    printf("thread %s \n", arg);
    sem_wait(&sem_count);
    printf("%ld \n",sem_count.__align);
    get_buffer();
    reecive_buff();

}

int main(int argc, char const *argv[])
{
    pthread_t helloID, x,y,z;
    pthread_t byeID;
    printf("Main Thread \n");
    // intialise mutex
    // close mutex 
    sem_init(&sem_count,0,4); 
    // second arguement is 0 if process is shared 
    pthread_create(&helloID, NULL, inc_thread, "first");
    pthread_create(&byeID, NULL, two_thread, "sec");
    pthread_create(&x, NULL, three_thread, "third");
    pthread_create(&y, NULL, four_thread, "four");
    pthread_create(&z, NULL, five_thread, "five");
    pthread_join(helloID, NULL);
    pthread_join(byeID, NULL);
    pthread_join(x, NULL);
    pthread_join(y, NULL);
    pthread_join(z, NULL);
    sem_destroy(&sem_count);
    return 0;
}

