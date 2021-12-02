   #include <unistd.h>
   #include<stdio.h>
  #include <sys/types.h>

   int main(int argc, char const *argv[])
   {
       pid_t id;   
       int fd[2];
       unsigned char buff[16];
       pipe(fd);    
       //fd[0] read fd[1] write
       id = fork();
        if(0 ==id){
            close(fd[1]);
            printf("Child ");
            read(fd[0], buff ,16);
            printf("Read %s \n",buff);
        }
        else{
            close(fd[0]);
            printf("Parent Writing data \n");
            write(fd[1], "DESD\n", 5);
        }
       
       
        return 0;
   }
   