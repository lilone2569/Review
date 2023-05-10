#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//编写带参数的main，实现简易的计算器的功能，能够实现加减乘除。
int main(int argc,char *argv[])
{
	int a=atoi(argv[1]);//把字符串转换成数字
	int b=atoi(argv[3]);
	
	switch(*argv[2])
	{
		case '+':printf("%d + %d = %d\r\n",a,b,a+b);break;
		case '-':printf("%d - %d = %d\r\n",a,b,a-b);break;
		case '*':printf("%d * %d = %d\r\n",a,b,a*b);break;
		case '/':printf("%d / %d = %d\r\n",a,b,a/b);break;
	}
	
	return 0;
}
