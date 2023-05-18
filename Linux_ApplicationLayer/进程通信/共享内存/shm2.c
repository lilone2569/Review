#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define ERROR  -1
#define OK      0


//通过共享内存实现多人聊天室
int main(int argc,char *argv[])
{
    struct shmid_ds *ds;
    key_t key = ftok("./1.txt",0xff);   //获取key值
    if(key == -1){
        perror("get key failed!");
        return ERROR;
    }

    int shmid = shmget(key,4096,IPC_CREAT | 0666);   //共享内存的基本单位是页，大小是4K，并且向上取整数。
    if(shmid == -1){
        perror("shmget failed!");
        return ERROR;
    }

    char *p = shmat(shmid,NULL,0);    //将内存地址映射到本进程的地址空间

    char name[10] = {0};
    printf("please input your name:");
    scanf("%s",name);

    int pid = fork();   //创建进程
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        char buf[30];
        while(1){
            if(strncmp(name,p,strlen(name))){  //如果不是自己写的内容
                if(strcmp(p,buf)){  //如果有改写过
                    strcpy(buf,p);   //如果改写了，就把新内容复制过来
                    printf("%s\n",buf);
                }
            }else if(strcmp("quit\n\r\n",(p+strlen(name)+1)) == 0) break;
        }
        printf("father quit\n");
    
        wait(NULL);
    }
    else if(pid == 0){   //son
        char buf[25];
        while(1){
            fgets(buf,sizeof(buf),stdin);
            sprintf(p,"%s:%s\r\n",name,buf);    
            if(strcmp("quit\n",buf)==0) break;
            memset(buf,0,sizeof(buf));
        }
        printf("child quit\n");
        exit(0);
    }
    if(shmdt(p) == -1){    //取消内存映射
        perror("shmdt failed!");
        return ERROR;
    }
    if(shmctl(shmid,IPC_RMID,NULL) == -1){  //删除共享内存映射
        perror(" remove share memory failed\n");
        return ERROR;
    }
    return 0;
}
