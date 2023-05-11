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


//实现父子进程相互发消息
int main(int argc,char *argv[])
{
    int pipefd1[2] = {0},pipefd2[2] = {0};
    int ret = pipe(pipefd1);
    if(ret == -1){
        perror("create first pipe failed\n");
        return ERROR;
    }
    ret = pipe(pipefd2);
    if(ret == -1){
        perror("create second pipe failed\n");
        return ERROR;
    }
    int pid = fork();
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        char wr_buf[50];
        char rx_buf[50];
        int ret;
        while(1){
            printf("father:\n请输入要发送给子进程的数据:");
            fgets(wr_buf,sizeof(wr_buf),stdin);
            ret = write(pipefd1[1],wr_buf,strlen(wr_buf));
            if(ret == -1){
                perror("father:write pipe failed\n");
                return ERROR;
            }
            memset(wr_buf,0,sizeof(wr_buf));
            ret = read(pipefd2[0],rx_buf,sizeof(rx_buf));
            if(ret < 0){
                perror("father:read from pipe failed\n");
                return 0;
            }
            printf("father received from son:%s\n",rx_buf);
            memset(rx_buf,0,sizeof(rx_buf));
        }
        wait(NULL);
    }
    else if(pid == 0){   //son
        char wr_buf[50];
        char rx_buf[50];
        int ret;
        while(1){
            ret = read(pipefd1[0],rx_buf,sizeof(rx_buf));
            if(ret < 0){
                perror("son:read from pipe failed\n");
                return 0;
            }
            printf("son received from father:%s\n",rx_buf);
            memset(rx_buf,0,sizeof(rx_buf));
            printf("son:\n请输入要发送给父进程的数据:");
            fgets(wr_buf,sizeof(wr_buf),stdin);
            ret = write(pipefd2[1],wr_buf,strlen(wr_buf));
            if(ret == -1){
                perror("son:write pipe failed\n");
                return ERROR;
            }
            memset(wr_buf,0,sizeof(wr_buf));
        }
        exit(0);
    }
    if(close(pipefd1[0]) == -1 || close(pipefd1[1]) == -1){
        perror("close pipefd1 failed");
        return 0;
    }
    if(close(pipefd2[0]) == -1 || close(pipefd2[1]) == -1){
        perror("close pipefd2 failed");
        return 0;
    }
    
    return 0;
}
