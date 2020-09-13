//
// Created by lcx on 2020/8/25.
//
#include <iostream>
#include <string.h>
using namespace std;

/*
 * 1、引用没有定义，是一种关系型声明。声明它和原有某一变量(实体)的关系。故而类型与原类型保持一致，且不分配内存。与被引用的变量有相同的地址。
 * 2、声明的时候必须初始化，一经声明，不可变更。
 * 3、可对引用，再次引用。多次引用的结果，是某一变量具有多个别名。
 * 4、&符号前有数据类型时，是引用。其它皆为取地址
 */


struct A
{
    int *a;
};

struct B
{
    int &a;
};

struct stu
{
    int id;
    char name[20];
};

int modify( int &a)//当我们将引用作为函数参数传递的时候，编译器，会替我们将实参，取地址给引用,int &a = main: :&a
{
    a = 200;//对一个引用操作赋值的时候，编译器提我们隐藏*操作
    //如果我们在去研究引用的时候，你可以将引用当做一个常指针去研究
    //当你在使用引用编程的时候，你就把引用理解为变量的别名就可以了。

}

/*引用作为函数返回值，不要返回局部变量的引用
int& test1()
{
    int a = 10;

    return a;
}
*/
//变成静态变量就安全了
int &test2()
{
    static int a = 10;
    return a;
}

//指针引用
int get_data( stu* &tp)
{
    tp = (stu*)malloc(sizeof(stu));
    tp->id = 10;
    strcpy(tp->name, "lcx");

}
void free_data(stu* &tp)
{
    free(tp);
    tp = NULL;
}
int main()
{
    int a = 10;
    int b = 30;
    int &re = a; //int &使用引用数据类型，re就是a的别名

    re = 20;
    cout<<"a = "<<a<<endl;

    re = b;//不能让re成为b的引用，这里相当于 a = b;
    cout<<"a = "<<a<<endl;
    re =50;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    //int &re2;//引用一定要初始化

    cout<<"size of A is "<< sizeof(A)<<endl;//引用所占大小和指针是一样的
    cout<<"size of B is "<< sizeof(B)<<endl;

    int &re3 = a;//常量要初始化，引用也要初始化，引用可能是一刚常量。

    int * const p = &a;//综上，引用可能是常指针

/*
 * 不安全
    int &m = test1();
    cout<<"m is "<<m<<endl;
    cout<<"m is "<<m<<endl;
*/

    int &m = test2();
    cout<<"m is "<<m<<endl;
    cout<<"m is "<<m<<endl;

    //引用如果当函数返回值的话，函数可以当左值。
    test2() = 1000;

    stu* st ;
    get_data(st);
    cout<<"Id is "<<st->id<<" Name is "<<st->name<<endl;

    const int c = 10;
    const int &rec = c;//如果想对一个常量进行引用，必须是一个const引用

    return 0;
}