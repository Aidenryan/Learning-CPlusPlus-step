//
// Created by lcx on 2020/8/27.
//
#include <iostream>
using namespace std;

class complex
{
public:
    complex():real(0), imag(0){};
    complex(int a, int b):real(a), imag(b){}
    complex operator+(const complex &another)const ;//加号重载
    friend ostream& operator<<(ostream &os, const complex& c);
    ostream& operator <<(ostream &os);//一般不会这样写，<< 操作符只能写在全局，不能够写在成员函数中。否则调用的顺序会变饭，cl<<cout;

    void print_complex();
private:
    int real;
    int imag;
};

//输出加上引用的原因是 平常可以cout<<a<<b<<cendl; 说明cout<<a返回的还是cout ,所以为了可以连续输出，我们一般在函数返回值加上ostream&
ostream& operator<<(ostream &os, const complex& c)
{
    os<<c.real<<" + "<<c.imag<<"i"<<endl;
    return os;
}

ostream& complex::operator <<(ostream &os)
{
    os<<this->real<<" + "<<this->imag<<"i"<<endl;
    return os;
}

complex complex::operator+(const complex &another) const//这个const是希望函数中this指针不要修改成员变量
{
    complex c;
    c.real = this->real + another.real;
    c.imag = this->imag + another.imag;
    return c;
}
void complex::print_complex() {
    cout<<this->real<<" + "<<this->imag<<"i"<<endl;
}
int main()
{
    complex a(1,2);
    complex b(1,4);
    complex c = a + b;
    c.print_complex();
    cout<<c<<endl;//重载了左移操作符
    return 0;
}
