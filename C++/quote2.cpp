#include <iostream>

using namespace std;

/***************************引用做函数参数****************************/
void Myswap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


/***************************引用做函数返回值***************************/
//注意： 不能返回局部变量的值
//      不能返回函数内部new分配的内存的引用
int& fun1()
{
    static int c = 30;
    return c;
}


/**************常量引用*******************/
//作用：用于修饰形参，防止误操作
void showValue(const int &a)
{
    cout << "常量引用  value = " << a <<endl;
}


int main()
{
    int a = 10,b = 20;

    Myswap(a,b);   /*通过引用传递参数，形参可以修饰实参*/
    cout << "引用做函数参数 a = " << a << " b = " << b <<endl;


    int &c = fun1();   
    cout << "引用做返回值 C = "<< c <<endl;
    fun1() = 100;   //引用做函数返回值,函数调用可以作为左值
    cout << "函数调用作为左值 C = "<< c <<endl;


    const int &d = 1000; //引用必须得引用一块合法的内存
    showValue(d);

    return 0;
}
