//
// Created by lcx on 2020/8/27.
//
#include <iostream>
using namespace std;

//非特殊情况少用友元，它会破坏函数封装性
class A;
class C;
class B
{
public:
    void print( A& a);
private:
    int m_bb;
};

class A
{
public:
    A(int a, int b):m_a(a), m_b(b){}

    friend void printA(const A& a);

    friend void B::print( A& a);//将其他类的成员函数声明为友元函数

    void getC(const C& c );

private:
    int m_a;
    int m_b;
};

class C
{
public:
    friend class A;//将别的类作为自己的友元类
private:
    int m_cc;
};
void A::getC(const C& c )
{
    cout<<c.m_cc<<endl;
}

void B::print( A& a)
{
    cout<<a.m_a<<endl;
}

//将非成员函数声明为友元函数
void printA(const A& a)
{
    cout<<a.m_b<<" "<<a.m_a<<endl;
}

int main()
{
//    int a = 2;
//    const int &b = a;
//    a =3;
//    cout<<"a: "<<a<<endl;
//    cout<<"b: "<<b<<endl;
    return 0;
}
