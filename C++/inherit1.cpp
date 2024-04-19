#include<iostream>

using namespace std;

/**************************************** 继承 ******************************************/

//基类  父亲
class Animal
{
public:
    void eat(void){
        cout << "Animal eat" << endl;
    }
    void sleep(void){
        cout << "Animal sleep" << endl;
    }
};

//派生类  儿子继承自父亲
class Dog: public Animal{
public:
    void bark(){
        cout << "Dog bark" << endl;
    }
};




//任意一个类可以访问本类下public、protected、private修饰的成员
//派生类可以访问基类的public、protected成员，但是不能访问private的成员
//外部类只能访问public成员
int main()
{
    Dog dog1;
    dog1.bark();
    dog1.eat();  //派生类也可以访问基类

    return 0;
}
