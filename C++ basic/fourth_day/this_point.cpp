//
// Created by lcx on 2020/8/27.
//
#include <iostream>
using namespace std;
class A
{
private:
    int m_a;
    int m_b;
    static int m_s;
public:
    A( int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    //this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。
    // 不过 this 这个形参是隐式的，它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中
    int get() const //(如果想指针指向的成员函数也不能改变，在成员函数后面加const，成员函数尾部出现const 修饰是this指针)
    {
        //this->m_a = 100;//可以的，因为this 不是 const A*类型
        //this++;//错误的,this指针是常指针，A* const
        return this->m_b;
    }

    //static成员函数，只能返回static成员变量
    //静态成员函数只能访问静态数据成员。原因:非静态成员函数,在调用时this指针被当作参数传进。而静态成员函数属于类,而不属于对象,没有this指针。
    static int get_s()
    {
        return m_s;
    }
    //返回函数本身
    A& add( const A& another)
    {
        this->m_a += another.m_a;
        this->m_b += another.m_b;
        return *this;//如果想返回一个对象的本身，在成员函数中，用*this返回
    }
};
int A::m_s = 0;
int main()
{
    return 0;
}
