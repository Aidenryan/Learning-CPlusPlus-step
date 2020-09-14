#include <iostream>

class complex
{
public:
    complex( int a, int b): m_real(a), m_img(b){};
    operator int () { return m_real;}//类型转换函数

private:
    int m_real;
    int m_img;
};
int main() {

    //const_cast 就是用来将 const/volatile 类型转换为非 const/volatile 类型
    int a =10;
    const int& b = a;
    int& c = const_cast<int&>(b);

    //static_cast常用的
    {
        //下面是正确的用法
        int m = 100;
        complex c(12, 23);
        long n = static_cast<long>(m);  //宽转换，没有信息丢失
        char ch = static_cast<char>(m);  //窄转换，可能会丢失信息
        int *p1 = static_cast<int*>( malloc(10 * sizeof(int)) );  //将void指针转换为具体类型指针
        void *p2 = static_cast<void*>(p1);  //将具体类型指针，转换为void指针
        int real= static_cast<int>(c);  //调用类型转换函数

        //下面的用法是错误的
        //float *p3 = static_cast<float*>(p1);  //不能在两个具体类型的指针之间进行转换
        //p3 = static_cast<float*>(0X2DF9);  //不能将整数转换为指针类型
    }

    //dynamic_cast  用于在类的继承层次之间进行类型转换,目前用的少 以后再来做笔记
    return 0;
}