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
    int fd,len = 0;
    
    if(argc < 2){  
        perror("Usage:my_cat filename ....\n");
        return ERROR;
    }
    for(int i = 1;i < argc;i++){   //可以cat多个文件
        fd = open(argv[i],O_RDONLY);
        if(fd == -1){
            perror("open file failed\n");
            return ERROR;
        }
        char buf[64];    //为了防止内存浪费需要，每次只读64个字符
        while(1){  //每次读64字符直到读得字符为0即退出
            len = read(fd,buf,sizeof(buf)-1);
            if(len == -1){ 
                perror("read file failed\n");
                return ERROR;
            }
            else if(len == 0) break;  //读不到数据则说明没有字符则跳出循环
            len = write(1,buf,strlen(buf));  //标准输出stdout：1
            if(len == -1){
                perror("write file failed");
                return ERROR;
            }
            memset(buf,0,sizeof(buf));  //下一个文件用之前清空缓存
            printf("\n");
        }
        close(fd);
    }
    
    

    return 0;
}












