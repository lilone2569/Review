#include <iostream>

using namespace std;

/**************************引用***********************/
/*
作用： 给变量起别名
语法：数据类型 &别名 = 原名
本质: 在C++中的实现是指针常量，例：int* const a == int &a
*/
int main()
{
    int a = 10,b = 20;
    int &c = a;  //创建引用，一旦引用初始化后不可更改
    //b = c; 
    //int &c;   //引用必须初始化  
    cout << c << endl;
    c = 30;
    cout << c << endl;

    
    return 0;
}
