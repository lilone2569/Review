#include <iostream>

using namespace std;
/**************************************** 继承 ******************************************/



//基类1
class Shape{
public:
    void setWidth(int wid){
        width = wid;
    }
    void setHeight(int hgt){
        height = hgt;
    }
protected:
    int width;
    int height;
};

//基类2
class Cost{
public:
    int getCost(int area){
        return area * 100;    
    }
};

//派生类
class Rectangle:public Shape,public Cost{
public:
    int getArea(void){
        return width*height;
    }
};


/*公有继承:基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，
基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。*/
/*保护继承: 基类的公有和保护成员将成为派生类的保护成员。 */
/*私有继承: 基类的公有和保护成员将成为派生类的私有成员。*/

int main()
{
    int cost,area;
    Rectangle rec1;
    rec1.setHeight(5);  //派生类访问基类1的成员
    rec1.setWidth(6);
    area = rec1.getArea();
    cost = rec1.getCost(area); //派生类访问基类2的成员
    cout << "area = " << area << endl;
    cout << "cost = " << cost << endl;

    return 0;
}











