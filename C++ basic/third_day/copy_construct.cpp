//
// Created by lcx on 2020/8/26.
//
#include <iostream>
#include <string.h>
using namespace std;

class A
{
private:
    int m_a;
public:
    A(int a)
    {
        m_a = a;
    }
};

class B
{
public:
    //构造函数初始化列表
    B(int b, A &a, A &aa):m_b(b), m_ba1(a),m_ba2(aa){}//调用A的拷贝构造
    //构造对象成员的顺序跟初始化列表的顺序无关，而是跟成员对象的定义顺序有关
    B(int b, int a, int aa):m_b(b), m_ba1(a),m_ba2(aa){}//调用A的含参构造

    //常量的初始化一定要放在初始化列表
//    B(int b, int a, int aa, const int m):m_ba1(a),m_ba2(aa),m_m(m)
//    {
//        m_b = b;
//    }

    //静态成员变量，必须初始化，而且是在类外，它属于整个类，所有的对象都共享这些静态成员变量
    //static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放，在定义类时候就分配了空间，而不是创建对象时候
    static int j;

    //对于静态私有还是需要定义函数进行访问，而且是静态静态成员函数。初始化仍在类外
    static void get_k( int k )
    {
        m_k = k;
    }
private:
    int m_b;
    A m_ba1;
    A m_ba2;
    static int m_k;
    //const int m_m;1
};

int B::j = 100;
int B::m_k = 10;
/*
 * malloc 和 new
 * malloc free是函数，标准库, stdlib.h
 * new在堆上初始化一个对象的时候，会触发对象的构造函数。malloc不能
 * free并不能触发一个对象的析构函数。delete 可以。这样可以保证由对象创建的堆空间得以通过析构函数释放
 * */

int main()
{
    //A *t = (A*)malloc(sizeof(A)); //无法直接赋值，需要通过别的函数访问私有变量

    A *t = new A(1);//可以通过有参构造

    //对于公有,可以直接通过类名访问。包括静态成员函数
    B::j = 10;
    B::get_k(1000);
    return 0;
}
/*
1.static成员变量实现了同类对象间信息共亨。
2.static成员类外存储,求类大小,并不包含在内。
3,static成员是命名空间属于类的全局变量,存储在data区。
4.static成员只在类外初始化。
5,可以通过类名访问(无对象生成时亦可),也可以通过对象访问。
*/