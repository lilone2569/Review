#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



//1.int open(const char *pathname, int flags);
//flags:O_RDONLY, O_WRONLY, or O_RDWR
//O_CREAT(文件如果不存在就创建),O_APPEND(以追加的方式打开文档，打开文件之后光标会在文件末尾) andO_TRUNC(以删除写的方式打开文档，文档里面的内容会被清除).
//return:返回一个文件描述符fd

//2.ssize_t write(int fd, const void *buf, size_t count);


//3.ssize_t read(int fd, void *buf, size_t count);

//4.int close(int fd);

//5.off_t lseek(int fd, off_t offset, int whence); //用于调整文件读写得位置
//offset:相对偏移量
//whence:偏移基点，SEEK_SET(从起始位置偏移)、SEEK_CUR(当前位置)、SEEK_END(文件结尾)
/*
例：
第一种：将文件的读写位置调整到开始位置后第5个字节
lseek(fd,5,SEEK_SET);
第二种：将文件的读写位置调整文件末尾
lseek(fd,0,SEEK_END);
第三种：将文件的读写位置调整到当前位置的前两个字节
lseek(fd,-2,SEEK_CUR)
*/

/*
标准输入0   stdin  从键盘获得输入 /proc/self/fd/0 
标准输出1   stdout 输出到屏幕（即控制台） /proc/self/fd/1 
错误输出2   stderr 输出到屏幕（即控制台） /proc/self/fd/2 
*/

int main(int argc,char *argv[])
{
	


	return 0;
}
