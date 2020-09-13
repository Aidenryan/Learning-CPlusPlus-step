//
// Created by lcx on 2020/8/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数组指针作为函数参数
void print_array( int (*p)[4])
{
    int i, j;
    for(i = 0; i< 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }


}
int main()
{
     /*
     a[][2] = { 1， 2， 2， 3， 4, 5 }；
     二维数组数组名:第0行首地址
     a+i:第i行首地址
     要想把首地址转化为首元素地址，加*: *(a+i)
     要想得到某个元素地址，加偏移量: *(a+i)+0，*(a+i)+1，*(a+i)+j => &a[i][0] &a[i]+1，&a[i][j]
     要想得到某个元素的值，是这个元素的地址基础上加*
     *(*(a+i)+j)=> *&a[i][j] => a[i][j]
      *
      *
      a :代表第0行首地址
     a+i  => &a[i]:代表第i行首地址
    *(a+i) => a[i] :代表第i行首元素地址
    *(a+i)+j => &a[i][j]:第i行第j列元素的地址
    *(*(a+i)+j => a[i][j]第i行第j列元素的值

     */


    int a[][4]= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //3个a[4]的一维数组
    //定义数组指针变量
    //指向一维数组的整个数组首地址
    int(*p)[4];
    //p = &a;//整个二维数组首地址
    p = a;//第0行首地址

    print_array(a);
    int t[10];
    //测一维数组长度:sizeof()首行首元素地址
    printf("sizeof(t)= %d sizeof(&t)=%d\n", sizeof(t), sizeof(&t));
    int a1[2][10];
    printf("sizeof(a1[0])=%d sizeof(&a[0])=%d\n",sizeof(a1[0]),sizeof(&a1[0]));


    return  0;
}
