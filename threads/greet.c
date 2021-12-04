#include<stdio.h>
#include <pthread.h>

// void *hello_thread(void *arg){

// printf("Hello Thread \n");
// }
// void *bye_thread(void *arg){

// printf("Bye Thread \n");
// }
 void *greet_thread(void *arg){

printf("%s Thread \n", arg);
}

int main(int argc, char const *argv[])
{
    pthread_t helloID;
    pthread_t byeID;
    printf("Main Thread \n");
    pthread_create(&helloID, NULL, greet_thread, "hello");
    pthread_join(helloID, NULL);
    pthread_create(&byeID, NULL, greet_thread, "Bye");
    pthread_join(byeID, NULL);
// 4 arguement takes the value to be passed by main thread to other thread
// 3 address of the function which is act as a thread
// 2 takes attributes
// 1 opaque data type it store the tread id in this variable 
// compile with -ptread library


    return 0;
}

