#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERROR  -1
#define OK      0


//实现父进程写数据，子进程读数据
int main(int argc,char *argv[])
{
    int pipefd[2] = {0};
    int ret = pipe(pipefd);  //创建管道
    if(ret == -1){
        perror("create No name pipe failed\n");
        return ERROR;
    }
    int pid = fork();   //创建子进程
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        char buf[50];
        int ret;
        while(1){
            printf("请输入要写入管道的数据：");
            fgets(buf,sizeof(buf),stdin);
            ret = write(pipefd[1],buf,strlen(buf));    //将输入的数据写入管道
            if(ret == -1){
                perror("write pipe failed\n");
                return ERROR;
            }
            usleep(10);  //经过测试发现父进程跑完还是被父进程抢占所以短暂挂起一下
        }
        wait(NULL);
    }
    else if(pid == 0){   //son
        char buf[50];
        int ret;
        while(1){
            ret = read(pipefd[0],buf,sizeof(buf)-1);  //将管道的数据读到缓存区
            if(ret < 0){
                perror("read from pipe failed\n");
                return 0;
            }
            
            printf("从管道读到的数据：%s\n",buf);
        }
        exit(0);
    }

    return 0;
}
