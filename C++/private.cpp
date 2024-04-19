#include<iostream>
using namespace std;

/************************************私有成员变量***************************************/


class Box
{
private:
    int width;
public:
    void setWidth(int wid);
    int getWidth(void);
};

void Box::setWidth(int wid)
{
    width = wid;
}

int Box::getWidth(void)
{
    return width;
}


//私有的成员变量或函数在类的外部是不可访问的，甚至是不可查看的
//只有类和友元函数可以访问私有成员。
int main()
{
    Box box1;
    //box1.width = 10;  err 
    
    cout << "box1 width = " << box1.getWidth()  << " cm" <<endl;
    return 0;
}
