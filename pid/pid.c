#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){


printf("ID :%d \n", getpid());
printf("Parent ID :%d \n", getppid());


}