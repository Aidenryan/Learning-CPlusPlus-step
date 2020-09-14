#include <iostream>
//#include "test_template.h"
#include "test_template.cpp"//对于模板类，如果分文件写，则需要直接连接.cpp文件 连接.h会报错，因为找不到函数定义，
// 这个和c++的编译原理有关，一个文件我一个文件编译，但是类模板只会编译两次，声明时候一次，调用实例时候一次
using namespace std;
//函数模板
//template <class T>//或者
template <typename T>
void _swap( T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//类模板
//模板头和类头是一个整体，可以换行，但是中间不能有分号。
template <typename T>
class A
{
public:
    A(T a, T b);
    void show();
    static int a;//属于模板实例化出来的一个类型的类
private:
    T num;
    T id;
};

template <typename T>
A<T>::A(T a, T b)
{
    num = a;
    id = b;
}

template <typename T>
int A<T>::a =0;

template <typename T>
void A<T>::show() {
    cout<<num<<" "<<id<<endl;
}


int main()
{
    int a = 10;
    int b = 20;
    _swap(a, b);

    //类模板在实例化时必须显式地指明数据类型，编译器不能根据给定的数据推演出数据类型。
    A<int> c(2, 5);
    c.show();

    B<int> d(2, 5);
    d.show();


    return 0;
}