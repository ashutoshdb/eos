#include <unistd.h>
#include<stdio.h>
#include<sys/types.h>
 #include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
#include<semaphore.h>         /* For O_* constants */
                /* For O_* constants */

sem_t s1;


int *count;
int main(int argc, char const *argv[])
{
    int smd;
      sem_init(&s1,0,1);
    // int num;
    smd = shm_open("/cdacshm", O_RDWR |O_CREAT,S_IRUSR |S_IWUSR); // "/name", flags, permissions
    ftruncate(smd,sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, smd,0); 
    // NULL is used when os give the ADD of the shared mem 2 sizeof mem length  3 protection rights 4 flags 5 mem descripter 
    // 6  offset from where we want to create mem sapce  position

    while (1)
    {
     sem_wait(&s1);
       printf("Count %d \n", *count);
       sem_post(&s1);
    }
    

  sem_destroy(&s1);
    return 0;
}
