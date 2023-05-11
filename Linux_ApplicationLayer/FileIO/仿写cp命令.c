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
    int len = 0,ret;
    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0){
        perror("open first file failed!\n");
        return ERROR;
    }
    fd2 = open(argv[2], O_RDWR | O_CREAT |O_TRUNC,0666); // 可读可写可创建—以覆盖的方式
    if(fd1 < 0){
        perror("open second file failed!\n");
        return ERROR;
    }
    while(1){
        len = read(fd1,buffer,sizeof(buffer)-1);
        if(len < 0){
            perror("read to buffer  failed!\n");
            return ERROR;
        }
        else if(len == 0) break;
        ret = write(fd2,buffer,strlen(buffer));
        if(ret == -1){
            perror("write to first file failed!\n");
            return ERROR;
        }
    }
    memset(buffer,0,sizeof(buffer));
    close(fd1);
    if(fd1 == -1){
        perror("close first file failed!\n");
        return ERROR;
    }
    close(fd2);
    if(fd2 == -1){
        perror("close second file failed!\n");
        return ERROR;
    }
    return 0;
}











