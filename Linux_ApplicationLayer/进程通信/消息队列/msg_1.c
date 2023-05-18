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


//使用消息队列实现两个终端互相发送消息
int main(int argc,char *argv[])
{
    
    int ret;
    key_t key = ftok("./2.txt",0xff);   //获取key值
    if(key == -1){
        perror("get key failed!");
        return ERROR;
    }
    int msgid = msgget(key,IPC_CREAT|0666);   //创建消息队列获取id号
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
        while(1){   //父进程专门往编号为1的消息队列发送消息
            printf("Please input message:");
            fgets(buf1.mtext,sizeof(buf1.mtext),stdin);
            printf("buf1.mtext=%s\n",buf1.mtext);
            ret = msgsnd(msgid,&buf1,strlen(buf1.mtext),0);
            if(ret == -1){
                perror("message send failed!\n");
                return ERROR;
            }
            if(strcmp(buf1.mtext,"quit\n") == 0) break;

            usleep(10);
            memset(buf1.mtext,0,sizeof(buf1.mtext));
        }
        wait(NULL);
    }
    else if(pid == 0){   //son    
        struct msgbuf buf2;
        while(1){    //子进程专门从编号为2的消息队列接受消息
            if(msgrcv(msgid,&buf2,sizeof(buf2.mtext),2,0) == -1){
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
