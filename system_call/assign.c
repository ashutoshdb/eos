#include<stdio.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>



// ./rojbin source.txt dest.txt
int main(int argc, char const *argv[])
{
    int fdr, fdw;
    char buffer[50];
    fdr = open(argv[1], O_RDONLY);
    fdw = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(-1 == fdr | -1 == fdw){
           perror("Error \n:");
           exit(EXIT_FAILURE);

    }
    read(fdr,buffer,50);
    write(fdw, buffer,strlen(buffer));
    return 0;
}
