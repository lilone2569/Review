#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

//两个终端之间的正常聊天，需要提前通过mkfifo创建两个管道 有名管道A aa  bb
int main(int argc,char *argv[])
{
  //1、打开管道文件 open
	int fd1=open(argv[1],O_RDWR);
	int fd2=open(argv[2],O_RDWR);
	if((fd1 == -1) || (fd2 == -1))
	{
		perror("file open failure\r\n");
		return 0;
	}

	//2、创建父子进程 fork
	pid_t pid=fork( );
	if(pid < 0)//创建失败
	{
		perror("processe create failure\r\n");
		return 0;
	}else if(pid == 0)//子进程 循环在管道1写入内容
	{
		char buf[20]={0};
		while(1)
		{
			//从终端获取写入的内容
			fgets(buf,sizeof(buf),stdin);
				
			//把获取到的内容写入到管道2里面
			write(fd1,buf,strlen(buf));
			if(strcmp("quit\n",buf) == 0)
			{
				break;
			}
			memset(buf,0,sizeof(buf));
		}
		exit(0);
	}else//父进程 循环读取管道2的内容
	{
		char buf[20]={0};
		while(1)
		{
			//读取管道2里面的内容
			read(fd2,buf,sizeof(buf));

			//读取到的内容显示到终端
			system("date");
			printf("终端1接受到信息:%s\r\n",buf);
			if(strcmp("quit\n",buf) == 0)
			{
				break;
			}
			memset(buf,0,sizeof(buf));
		}
		wait(NULL);
	}

	//3、关闭文件close
	if((close(fd1) == -1) || (close(fd2) == -1))
	{
		perror("file close failure\r\n");
		return 0;
	}

	return 0;
}
