#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>

   int main(int argc, char const *argv[])
   {   
       int num[2];
       int sum[1];
       pid_t id;   
       int fd_1[2];
       int fd_2[2];
       int buff[2];
       pipe(fd_1);
       pipe(fd_2);    
       //fd[0] read fd[1] write
       id = fork();
        if(0 ==id){
            close(fd_1[1]);
            close(fd_2[0]);
            printf("Child ");
            read(fd_1[0], num ,8);   




            sum[0] = num[0]+num[1];
            // printf("sum %d \n",sum[0]);
            write(fd_2[1],sum,4);
        }
        else{
            close(fd_1[0]);
            close(fd_2[1]);
            printf("Parent Writing data \n");
            printf("Enter 1st Numbers \n");
            scanf("%d",&num[0]);
            printf("Enter 2st Numbers \n");
            scanf("%d",&num[1]); 
            write(fd_1[1], num,8);



            read(fd_2[0], sum ,sizeof(sum));
            printf("sum of the two numbers retured by child process: %d",sum[0]);
        }
       
       
        return 0;
   }
   