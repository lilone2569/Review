#include<iostream>

using namespace std;

/*******************************保护成员变量******************************/

class Box
{
protected:
    float width;
};

class SmallBox:Box{
public:
        void setSmallWidth(double wid);
        float getSmallWidth(void);
};

void SmallBox::setSmallWidth(double wid)
{
    width = wid;
}

float SmallBox::getSmallWidth( void )
{
    return width;
}

//protected修饰的成员变量或函数在类的外部是不可访问的，甚至是不可查看的
//只有类和友元函数可以访问私有成员。
//成员在派生类中是可以访问的
int mian()
{
    SmallBox box1;
    //box1.width = 10;   //err
    box1.setSmallWidth(10);
    cout << "box1 width = " << box1.getSmallWidth() << " cm" <<endl;


    return 0;
}
