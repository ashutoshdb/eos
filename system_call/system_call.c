#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>


int main()
{
    int fd;
    fd = open("desd.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); 
    if(-1 == fd){
        perror("Error \n:");
        exit(EXIT_FAILURE);
    }
    printf("sddad");
    write(fd, "DESD", 4);
    close(fd);

    return 0;

}