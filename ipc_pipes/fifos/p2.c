#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>


int main(int argc, char const *argv[])
{
    int fd;
    unsigned char buff[16];
    fd =  open("desdifo", O_RDONLY);
    read(fd,buff,16);
    printf("read %s",buff);
    close(fd);

    return 0;
}
