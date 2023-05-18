#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define ERROR  -1
#define OK      0


struct msgbuf {
    long mtype; /* message type, must be > 0 */
    char mtext[20]; /* message data */
};


//使用消息队列实现父进程发送消息，子进程接收消息
int main(int argc,char *argv[])
{
    
    int ret;
    key_t key = ftok("./2.txt",0xff);   //获取key值
    if(key == -1){
        perror("get key failed!");
        return ERROR;
    }
    int msgid = msgget(key,IPC_CREAT|0666);   //获取消息队列id号，需要添加可读写权限否则无法读写
    if(msgid == -1){
        perror("get msgid failed!");
        return ERROR;
    }


    int pid = fork();
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        struct msgbuf buf1;
        buf1.mtype = 1;
        while(1){
            printf("Please input message:");
            fgets(buf1.mtext,sizeof(buf1.mtext),stdin);
            printf("buf1.mtext=%s\n",buf1.mtext);
            ret = msgsnd(msgid,&buf1,strlen(buf1.mtext),0);   //发送消息到队列
            if(ret == -1){
                perror("message send failed!\n");
                return ERROR;
            }
            if(strcmp(buf1.mtext,"quit\n") == 0) break;   //输入quit则退出循环

            usleep(10);
            memset(buf1.mtext,0,sizeof(buf1.mtext));
        }
        wait(NULL);
    }
    else if(pid == 0){   //son
        struct msgbuf buf2;
        buf2.mtype = 1;
        while(1){
            if(msgrcv(msgid,&buf2,sizeof(buf2.mtext),1,0) == -1){   //接受消息队列的消息
                perror("message receive error!\n");
                return ERROR;
            }
            printf("rec:%s\n",buf2.mtext);
            if(strcmp(buf2.mtext,"quit\n") == 0) break;
            memset(buf2.mtext,0,sizeof(buf2.mtext));
        }
        exit(0);
    }

    return 0;
}
