#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//1.int open(const char *pathname, int flags);
//flags:O_RDONLY, O_WRONLY, or O_RDWR
//O_CREAT,  O_DIRECTORY,  O_EXCL,  O_NOCTTY,  O_NOFOLLOW,  O_TMPFILE, andO_TRUNC.
//return:返回一个文件描述符fd

//2.ssize_t write(int fd, const void *buf, size_t count);


//3.ssize_t read(int fd, void *buf, size_t count);

//4.close(int fd);

int main(int argc,char *argv[])
{
	


	return 0;
}
