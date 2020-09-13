//
// Created by lcx on 2020/8/23.
//一维数组的使用
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[] = {1, 2, 3, 4};//四个
    //int b[];//error, 定义时必须初始化

    int a1[100] = { 4, 5, 6};//没有赋值的都为0

    //sizeof()测量变量所占空间（变量所对应类型的空间）
    //sizeof(a)= 4*4  数组类型:由元素个数和元素类型对应int [4]
    //sizeof(a[0]） 首元素大小，每个元素4个字节
    int n = 0;
    n = sizeof( a ) / sizeof( a[0] );//n =4;

    int i ;
    for(i =0; i < n; i++)
    {
        //*(a+i) : a+i代表第i元素地址，*(a+i)指针指向的内存（取值）
        printf("%d ", a[i]);
        //printf("%d ", *(a+1));
    }

    //数组类型:由元素个数和元素类型对应
    //通过typedef 定义一个数组类型
    //有typedef是类型，没有是变量
    typedef int A[4];//代表数组类型
    //typedef int (A)[4];
    A b;//相当于int b[8]

    return  0;
}


