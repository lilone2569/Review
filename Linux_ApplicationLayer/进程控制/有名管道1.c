#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define ERROR  -1
#define OK      0


//通过有名管道实现父进程给子进程发送消息
int main(int argc,char *argv[])
{
    int ret;
    ret = mkfifo(argv[1],0666);   //创建管道
    if(ret == -1){
        perror("creat fifo failed\n");
        return ERROR;
    }
    int fd = open(argv[1],O_RDWR);   //将管道打开
    if(fd == -1){
        perror("open fifo failed\n");
        return ERROR;
    }
    int pid = fork();   //创建子进程
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        char buf[50];
        while(1){
            printf("请输入要往管道写入的数据：");
            fgets(buf, sizeof(buf),stdin);
            ret = write(fd,buf,strlen(buf));   //往管道写入数据
            if(ret == -1){
                perror("father:\nwrite failed\n");
                return ERROR;
            }
            memset(buf,0,sizeof(buf));
        }
        wait(NULL);
    }
    else if(pid == 0){   //son
        char buf[50];
        while(1){
            ret = read(fd,buf,sizeof(buf));  //从管道读取数据
            if(ret == -1){
                perror("son:\nread fifo failed\n");
                return ERROR;
            }
            printf("son:\n从管道接受到的数据:%s\n",buf);
            memset(buf,0,sizeof(buf));
        }
        exit(0);
    }
    if(close(fd) == -1){
        perror("close fifo failed\n");
        return ERROR;
    }
    return 0;
}
