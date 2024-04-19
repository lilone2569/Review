#include<iostream>

using namespace std;


/**************************new申请内存***************************/
int *fun1(void)
{
    int *p = new int(10);  //表示申请一块整形的地址，并且初始化为10
    return p;
}

void fun2(void)
{
    int *p = new int[10];
    for(int i = 0;i < 10;i++){
        p[i] = i+1;
        cout << p[i] <<endl;
    }
    delete[] p;   //释放数组内存的方式
    p = NULL;   //重要操作：数组内存释放后，地址需要指向空指针，以避免悬挂指针，悬挂指针是指指向已释放的内存的指针，继续使用悬挂指针可能导致不可预测的结果。
    cout << "数组释放内存后："<<endl;
    for(int i = 0;i < 10;i++){
        cout << p[i] <<endl;
    }

}

int main()
{
    /*示例1 基本语法*/
    int *p1 = fun1();
    cout << p1 <<endl;   //通过new申请的整形块的地址
    cout << *p1 <<endl; //位于此地址的数据
    delete p1;
    cout << "释放内存后" << endl;
    cout << p1 <<endl;   //从编译结果可以看到地址没变，数据被清空了
    //cout << *p1 <<endl;  //无数据

    /*示例2 开辟数组*/
    cout << "数组："<<endl;
    fun2();

    return 0;
}
