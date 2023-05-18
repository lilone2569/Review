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


//实现子进程往申请到的共享内存中写入数据，父进程打印出来
int main(int argc,char *argv[])
{
    struct shmid_ds *ds;
    key_t key = ftok("./1.txt",0xff);   //获取key值
    if(key == -1){
        perror("get key failed!");
        return ERROR;
    }
    printf("key=0x%x\n",key);
    int shmid = shmget(key,4096,IPC_CREAT | 0666);   //共享内存的基本单位是页，大小是4K，并且向上取整数。
    if(shmid == -1){
        perror("shmget failed!");
        return ERROR;
    }
    printf("shmid=%d\n",shmid);
    char *p = shmat(shmid,NULL,0);    //将内存地址映射到本进程的地址空间



    int pid = fork();   //创建进程
    if(pid == -1){
        perror("create process failed\n");
        return ERROR;
    }
    else if(pid > 0){   //father
        while(*p == '\0');
        printf("receive:%s\n",p);
        
    
        wait(NULL);
    }
    else if(pid == 0){   //son
        printf("请输入要写入共享内存的数据：");
        fgets(p,50,stdin);
        exit(0);
    }
    if(shmdt(p) == -1){    //取消内存映射
        perror("shmdt failed!");
        return ERROR;
    }
    if(shmctl(shmid,IPC_RMID,ds) == -1){  //删除共享内存映射
        perror(" remove share memory failed\n");
        return ERROR;
    }
    return 0;
}
