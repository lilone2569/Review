#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//在一个文件中先写入内容再进行读取
int main(int argc,char *argv[])
{
	int fd=open(argv[1], O_RDWR | O_CREAT, 00666);
	if(fd == -1)
	{
		perror("file open failure\r\n");
		return 0;
	}
	printf("fd=%d\r\n",fd);

	//2、在打开的文档中写入内容write
	char buf[20]="hello";
	ssize_t len = write(fd, buf, strlen(buf));
	if(len == -1)
	{
		perror("file write failure\r\n");
		return 0;
	}
	printf("len = %ld\r\n",len);

	//3、把光标位置移动到文件初始位置 lseek
	lseek(fd, 0,SEEK_SET);
		
	//4、读取文件里面的内容read
	memset(buf,0,sizeof(buf));//清楚空间里面的内容
	len = read(fd, buf, sizeof(buf));
	if(len == -1)
	{
		perror("file write failure\r\n");
		return 0;
	}
	printf("len = %ld\r\n",len);
	printf("buf=%s\r\n",buf);

	//5、关闭文件 close
	if(close(fd) == -1)
	{
		perror("file close failure\r\n");
		return 0;
	}


	return 0;
}

