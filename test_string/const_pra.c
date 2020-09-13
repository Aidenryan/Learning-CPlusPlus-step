//
// Created by lcx on 2020/8/19.
//c语言中 const的用法
//
#include <stdio.h>

typedef struct
{
    int a;
    int b;
}mystruct;

void fun( mystruct* p)
{
    //指针可以改变
    p = NULL;
    //指针指向的内存也可以改变
    p->a = 10;
}

void fun1( mystruct* const p)
{
    //p = NULL;//error
    //p->a = 10; //OK
}

void fun2( const mystruct*  p)
{
    //p = NULL;//OK
    //p->a = 10; //error
}

//p只读
void fun3( const mystruct* const p)
{
    mystruct temp;
    temp.a = p->a;
}

int main()
{
    //const修饰一个变量为只读
    const int a = 10;
    //a = 100; //error

    //指针变量，指针指向的内存，2个不同的概念
    char buff[] = "asdasfdsfa";

    //从左往右看，跳过类型，看修饰哪个字符
    //如果是 * ，说明指针指向的内存不能改变
    //如果是指针变量，说明指针的指向不能改变，指针的值不能改变
    const char * p = buff;//等价于 char const * p = buff;
    //p[1] = '2';//error,
    p = "adasda";//OK

    char* const p2 = buff;
    p2[1] = '3';
    //p2 = "ewdrwqd";//error

    //p3只读，指向不能变，指向的内存也不能变
    const char * const p3 = buff;
    return  0;
}




