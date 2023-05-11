#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ERROR  -1
#define OK      0

int main(int argc,char *argv[])
{
    int fd1,fd2;
    char buffer[200];
    int len = 0;
    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0){
        perror("open first file failed!\n");
        return ERROR;
    }
    fd2 = open(argv[2], O_RDWR | O_CREAT |0666);
    if(fd1 < 0){
        perror("open second file failed!\n");
        return ERROR;
    }
    while(1){
        len = read(fd1,buffer,sizeof(buffer)-1);
        if(len < 0){
            perror("read first file failed!\n");
            return ERROR;
        }
        else if(len == 0) break;
        write(fd2,buffer,sizeof(buffer));
        


    }

    return 0;
}












