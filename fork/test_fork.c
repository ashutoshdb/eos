       #include <sys/types.h>
       #include <unistd.h>
       #include<stdio.h>

int main(int argc, char const *argv[])
{
    pid_t num;

    printf("Before Fork \n\n");
    printf("PID : %d \n", getpid());
    printf("PPID : %d\n", getppid());
    num = fork();
     printf("After Fork \n\n");
    if(0==num){
    printf("Child PID : %d\n", getpid());
    printf("Child PPID : %d\n", getppid());
    }
    else{
    printf("Parent PID : %d\n", getpid());
    printf("parent PPID : %d\n", getppid());

    }

    return 0;
}
