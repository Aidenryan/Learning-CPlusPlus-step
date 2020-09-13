//
// Created by lcx on 2020/8/25.
//简单一点点知识，c++从c的加强
//

#include <iostream>

using namespace std;

//c++对于全局变量的检错能力加强
int g_a;
//int g_a = 10;//报错

void test1()
{
    //定义一个变量，随用随定义

    for(int i = 0; i < 10; i++)
    {

    }
}
//对于三目运算符的增强
void test2()
{
    int a = 10;
    int b = 20;
    //在c++中，三目运算符可以当左值，c会报错
    (a < b) ? a : b = 50;
}

//对于const增强
void test3()
{
    //c++中a才是真正的常量，c中是假的可以通过指针改变。
    const int a = 10;
    //如果对一个常量取地址，编译器会临时开辟一个空间temp,让这个指针存放这个临时空间的地址
    int* p = (int*)&a;

    *p = 20;//这里并没有改变a,改变的是临时开辟的地址的值
    cout<<"a is "<<a<<endl;
    cout<<"p is "<<*p<<endl;

    //const 常量和 宏定义区别
    //宏定义在编译时把所有用到宏定义值的地方用宏定义常量替换。const常量可以看作是一个只读变量，需要指定类型，需要分配内存，有自己的作用域。
}

//对于枚举的增强
enum season{
    spr = 0,
    sum,
    sut,
    win

};
void test4()
{
   // season s = 0;//error
     season  s  = spr;

}
int main()
{
    bool flag = true;//一个字节
    //只要非0，都是其1
    flag = -10;
    cout<<flag<<endl;
    cout<<sizeof(flag)<<endl;
    return 0;
}