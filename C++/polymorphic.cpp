#include <iostream>

using namespace std;
/************************************多态**********************************/

class Shape {
protected:
    int width,height;
public:
    Shape(int a = 0,int b = 0){
        width = a;
        height = b;
    }
    virtual int area(){    //在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
        cout << "Parent class area" <<endl;
        return 0;
    }
};


class Rectangle:public Shape{
public:
    Rectangle(int a = 0,int b = 0){

    }
    int area(){
        cout << "Rectangle class area" <<endl;
        return (width*height);
    }
};

class Triangle:public Shape{
public:
    Triangle(int a = 0,int b = 0){

    }
    int area(){
        cout << "Triangle class area" <<endl;
        return (width*height/2);
    }
};

//多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
/*
形成多态必须具备三个条件：

1、必须存在继承关系；

2、继承关系必须有同名虚函数（其中虚函数是在基类中使用关键字Virtual声明的函数，在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数）；

3、存在基类类型的指针或者引用，通过该指针或引用调用虚函数；
*/

int main()
{
    Shape *shape;
    Rectangle rectangle(1,2);
    Triangle triangle(3,4);

    shape  = &rectangle;
    shape->area();

    shape = &triangle;
    shape->area();

    return 0;
}
