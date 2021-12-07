#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char cmd[16];
    int fd[2];
    pipe(fd);
    id = fork();
  // execl("path", "commands")
    if(0 == id){
        close(fd[1]);
        read(fd[0],&cmd,16);
        char cmd_path[]="/bin/";
        strcat(cmd_path,cmd);
        printf("%s\n", cmd_path);
        printf ("\nChild :Before exec.\n");
        execl(cmd_path, cmd_path, NULL);
    }
    else
    {
    close(fd[0]);
    printf("DESDShell$");
    scanf("%s",cmd);
    write(fd[1], &cmd,16);
    }
    return 0;
}
