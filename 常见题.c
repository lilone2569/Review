1、判断 101 到 200 之间的素数。
//首先明白什么是素数，只能被1和本身整除的数，用循环遍历101-200之间的数，
//然后用101~200间的书整出2到该数前面一个数，比如是113，我们113整除2~112之间的数，
//只要这里的数整出都不等于0,则可以判断这个数是素数
void num(void)
{
    for(int i = 101;i < 201;i++){
        for(int j = 2;j < i;j++){
            if(i%j == 0) break;
        }
        if(j>=i){   //j>=i则说明没有能整除的数
            printf("%d ",i);
        }  
    }
}


2、打印出1-1000的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
void Nar_num(void){
    int ge,shi,bai;
    for(int i = 1;i <= 1000;i++){
        ge = i%10;
        shi = i/10%10;
        bai = i/100%10;
        if((ge*ge*ge + shi*shi*shi + bai*bai*bai) == i){
            printf("%d ",i);
        }
    }
}




3、有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
void Diff_num(void)
{
    int i,j,k,n = 0;;
    for(i = 1;i < 5;i++){
        for(j = 1;j < 5;j++){
            for(k = 1;k < 5;k++){
                if(i!=j&&i!=k&&j!=k){
                    printf("%d%d%d ",i,j,k);
                    n++
                }
                
            }
        }
    }
    printf("\n共%d个",n);
}

4、输出9*9口诀
void Multip(void)
{
    int i,j;
    for(i = 1;i<=9;i++){
        for(j = 1;j<=i;j++){
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}


5、古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
int Fibon1(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibon1(n - 1) + Fibon1(n - 2);
}
int main()
{
    for(int i=1;i<40;i++){
        printf("%d ",Fibon1(i));
    }
    return 0;
}


6、一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include<stdio.h>
int main()
{
    float h,s;
    h=s=100;
    h=h/2; //第一次反弹高度
    for(int i=2;i<=10;i++)
    {
        s=s+2*h;
        h=h/2;
    }
    printf("第10次落地时，共经过%f米，第10次反弹高%f米\n",s,h);
    return 0;
}

7、猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
void monkey()
{
    int i = 10,sum = 1;
    printf("第%d天=%d\n",i,sum);
    for(i = 9;i>0;i--){
        sum = (sum+1)*2;
        printf("第%d天=%d\n",i,sum);
    }
    printf("sum=%d\n",sum);
}


8、求1+2!+3!+...+20!的和。
void factor(int num)
{   
    int i = 1,a = 1,sum = 0;
    for(i = 1;i <= num;i++){
        a = a*i;
        sum = sum + a;
    }
    printf("%d的阶乘和=%d ",num,sum);
}

9、利用递归方法求5!。

#include <stdio.h>
 
int main()
{
    int i;
    int fact(int);
    for(i=0;i<6;i++){
        printf("%d!=%d\n",i,fact(i));
    }
}
int fact(int j)
{
    int sum;
    if(j==0){
        sum=1;
    } else {
        sum=j*fact(j-1);
    }
    return sum;
}


10、关键字static的作用是什么？
这个简单的问题很少有人能回答完全。在C语言中，关键字static有三个明显的作用：
1). 在函数体，一个被声明为静态的变量在这一函数被调用过程中维持其值不变。
2). 在模块内（但在函数体外），一个被声明为静态的变量可以被模块内所用函数访问，但不能被模块外其它函数访问。它是一个本地的全局变量。
3). 在模块内，一个被声明为静态的函数只可被这一模块内的其它函数调用。那就是，这个函数被限制在声明它的模块的本地范围内使用。（本地化数据和代码范围的好处和重要性）。


11、闰年判断
if(num%400 == 0 && num%100!=0  || num%400==0)

12、重写strlen
int my_strlen(const char *str)
{
    assert(str);
    const char *p = str;
    int cnt = 0;
    while(*p++!='\0'){
        cnt++;
    }
    return cnt;
}

13、重写strcpy
char *my_strcpy(char *str1,const char *str2)
{
    char *p1 = str1;
    const char*p2 = str2;
    while(*p2 != '\0' || *p1 != '\0'){
        *p1++ = *p2++;
    }
    return str1;
}


14、重写strcat
char *my_strcat(char *str1,const char *str2)
{
    char *p1 = str1;
    while(*++p1 != '\0');   //必须++p1,如果p1++的话会指向'\0'，就不会进入下面的循环
    //或者
    // while(*p1 != '\0')
    //     p1++;
        
    while((*(p1++) = *str2++) != '\0');
    return str1;
}




15、重写strcmp
int my_strcmp(const char *str1,const char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    while(*str1 != '\0' || *str2 != '\0'){
        if(*str1 > *str2){
            return 1;
        }
        else if(*str1 == *str2){
            str1++;
            str2++;
        }
        else return -1;
    }
    return 0;
}



16、C++中的“引用”与指针的区别是什么？
答 、1) 引用必须被初始化，指针不必。
2) 引用初始化以后不能被改变，指针可以改变所指的对象。
3) 不存在指向空值的引用，但是存在指向空值的指针。


17、.h头文件中的ifndef/define/endif 的作用？
答：防止该头文件被重复引用。

18、全局变量和局部变量在内存中是否有区别？如果有，是什么区别？
答 ：全局变量储存在静态数据区，局部变量在堆栈中。


19、队列和栈的区别？答：队列先进先出，栈后进先出

20、语句for( ；1 ；)有什么问题？它是什么意思？答 、和while(1)相同，无限循环。

21、程序的内存分配
答：一个由c/C++编译的程序占用的内存分为以下几个部分
1、栈区（stack）—由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
2、堆区（heap）—一般由程序员分配释放，若程序员不释放，程序结束时可能由OS回收。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表，呵呵。
3、全局区（静态区）（static）—全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。程序结束后由系统释放。
4、文字常量区—常量字符串就是放在这里的。程序结束后由系统释放。
5、程序代码区—存放函数体的二进制代码


22、什么是预编译,何时需要预编译?
答：预编译又称为预处理,是做些代码文本的替换工作。处理#开头的指令,比如拷贝#include包含的文件代码，#define宏定义的替换,条件编译等，就是为编译做的预备工作的阶段，主要处理#开始的预编译指令，预编译指令指示了在程序正式编译前就由编译器进行的操作，可以放在程序中的任何位置。
c编译系统在对程序进行通常的编译之前，先进行预处理。

23、关键字const是什么含意？
答： “const意味着常数”业余者。 “只读”正确的答案。
const int a; a是一个常整型数
int const a; a是一个常整型数
const int *a; a是一个指向常整型数的指针（也就是，整型数是不可修改的，但指针可以）。
int * const a; a是一个指向整型数的常指针（也就是说，指针指向的整型数是可以修改的，但指针是不可修改的）
int const * a const; a是一个指向常整型数的常指针（也就是说，指针指向的整型数是不可修改的，同时指针也是不可修改的）

24、分别写出BOOL,int,float,指针类型的变量a 与“零”的比较语句。
答：BOOL : if ( !a ) or if(a)
int : if ( a == 0)
float: if(x>-0.000001&&x<0.000001)
pointer : if ( a != NULL) or if(a == NULL) 

25、如何判断一段程序是由C 编译程序还是由C++编译程序编译的？
答：#ifdef __cplusplus
cout<<"c++";
#else
cout<<"c";
#endif

26、用变量a给出下面的定义
答：a) 一个整型数（An integer）
b) 一个指向整型数的指针（A pointer to an integer）
c) 一个指向指针的的指针，它指向的指针是指向一个整型数（A pointer to a pointer to an integer）
d) 一个有10个整型数的数组（An array of 10 integers）
e) 一个有10个指针的数组，该指针是指向一个整型数的（An array of 10 pointers to integers）
f) 一个指向有10个整型数数组的指针（A pointer to an array of 10 integers）
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数（A pointer to a function that takes an integer as an argument and returns an integer）
h) 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数（ An array of ten pointers to functions that take an integer
argument and return an integer ）
答案是：
a) int a; // An integer
b) int *a; // A pointer to an integer
c) int **a; // A pointer to a pointer to an integer
d) int a[10]; // An array of 10 integers
e) int *a[10]; // An array of 10 pointers to integers
f) int (*a)[10]; // A pointer to an array of 10 integers
g) int (*a)(int); // A pointer to a function a that takes an integer argument and returns an integer
h) int (*a[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer


27、写一个“标准”宏
答：交换两个参数值的宏定义为：. #define SWAP(a,b) {a=b-a;b=b-a;a=a+b}
输入两个参数，输出较小的一个：#define MIN(A,B) ((A) < (B))? (A) : (B))
表明1年中有多少秒（忽略闰年问题）：#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
#define DOUBLE(x) x+x 与 #define DOUBLE(x) （（x）+（x））
i = 5*DOUBLE(5)； i为30 i = 5*DOUBLE(5)； i为50

已知一个数组table，用一个宏定义，求出数据的元素个数
#define NTBL
#define NTBL (sizeof(table)/sizeof(table[0]))

28、下面的代码输出是什么，为什么？
void foo(void)
{
unsigned int a = 6;
int b = -20;
(a+b > 6) ? puts(“> 6″) : puts(“<= 6");
}
这个问题测试你是否懂得C语言中的整数自动转换原则，我发现有些开发者懂得极少这些东西。不管如何，这无符号整型问题的答案是输出是 ">6″。原因是当表达式中存在有符号类型和无符号类型时所有的操作数都自动转换为无符号类型。因此-20变成了一个非常大的正整数，所以该表达式计算出的结果大于6。这一点对于应当频繁用到无符号数据类型的嵌入式系统来说是丰常重要的。如果你答错了这个问题，你也就到了得不到这份工作的边缘。

29、单链表的建立，把’a'–’z’26个字母插入到链表中，并且倒叙，还要打印！
方法1：
typedef struct val
{   int date_1;
    struct val *next;
}*p;

void main(void)
{   char c;
    for(c=122;c>=97;c--)
    {   p.date=c;
        p=p->next;
    }
    p.next=NULL;
}

30、
main()
{
   int a[5]={1,2,3,4,5};
   int *ptr=(int *)(&a+1);
   printf("%d,%d",*(a+1),*(ptr-1));
}

答：2,5

31、交换两个变量的值，不使用第三个变量。即a=3,b=5,交换之后a=5,b=3;

a = a + b;
b = a - b;
a = a - b;


32、判断计算机的大小端

int num = 1;
char *p = (char *)&num;
if(*p==1)
    puts("小端");
else puts("大端");


33、//斐波那契数列

//输出第n个的值
//递归
int Fibon1(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibon1(n - 1) + Fibon1(n - 2);
}

//迭代法
int fib2(int m)
{
	if (m==1||m==2)
	return 1;
	int a=1,b=1,aw=0;
	while(m>=2)
	{
		aw=aw+a;
		a=b;
		b=aw;
		m=m-1;
	}
	return aw;
 }


//输出指定数量的斐波那契数列
void Fib(int num)
{
    int num1 = 1,num2 = 1,i,n,sum;
    for (i = 1; i <= num; ++i)
    {
        printf("%d, ", num1);
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
}


34、冒泡排序
//默认升序
void bublleSort(int arr[],int len)
{   
    int temp;
    for(int i = 0;i < len - 1;i++){
        for(int j = 0;j < len - 1 - i;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

35、//直接插入排序
//在有序的序列进行插入，长度逐渐增加
//第0个元素当作哨兵
void InsertSort(SqList *list){
    int i,j;
    for(i = 2;i < list->length;i++){
        if(list->r[i] < list->r[i-1]){   //前一个比当前小则进行比较
            list->r[0] = list->r[i];    //赋值给哨兵
            for(j = i - 1;list->r[j] > list->r[0];j--){  //前一个数跟哨兵做比较
                list->r[j + 1] = list->r[j]; 
            }
        }
        list->r[j+1] = list->r[0];  //因为j--，所以这里需要j+1
    }
}

//无哨兵
void insertion_sort(int arr[], int len){
    int i,j,temp;
    for (i=1;i<len;i++){
            temp = arr[i];
            for (j=i;j>0 && arr[j-1]>temp;j--)
                    arr[j] = arr[j-1];
            arr[j+1] = temp;
    }
}


36、//简单选择排序
void selection_sort(int arr[], int len)
{
    int i,j,temp;
        for (i = 0 ; i < len - 1 ; i++){
            int min = i;
            for (j = i + 1; j < len; j++)     //走訪未排序的元素
                if (arr[j] < arr[min]){//找到目前最小值
                    min = j;    //紀錄最小值
                    temp = arr[i];
                    arr[i] = arr[min];
                    arr[min] = temp;
                }           
        }
}

37、//希尔排序/缩小增量多遍插入排序
void shell_sort(int arr[], int len) {
        int gap, i, j;
        int temp;
        for (gap = len >> 1; gap > 0; gap >>= 1)  //右移一位相当于除以2
                for (i = gap; i < len; i++) {
                        temp = arr[i];
                        for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                                arr[j + gap] = arr[j];
                        arr[j + gap] = temp;
                }
}

38、-(i+1) = ~i;


39、韩信点兵：相传韩信才智过人，从不直接清点自己军队的人数，只要让士兵先后以三人一排、五人一排、七人一排地变换队形，而他每次只掠一眼队伍的排尾就知道总人数了。请输入3个非负整数a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7），输出总人数的最小值（或报告无解）。已知总人数不小于10，不超过100
int main(void)
{
    int i;
    int a,b,c;
    int k=0;
    scanf("%d%d%d",&a,&b,&c);
    for(i=10;i<=100;i++)
    {
    	if(i%3==a&&i%5==b&&i%7==c)
    	{
    		k=1;
    		printf("%d\n", i);
    		break;
		}
	}
	if(k==0)
	{
		printf("no\n");
	}
	return 0;
}

