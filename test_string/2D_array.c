//
// Created by lcx on 2020/8/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char a[][20])
{
    printf("a is %d, a+1 is %d\n",a, a+1);
    int i;
    for(i = 0; i < 3; i++)
    {
        printf("%s ", *(a+i));
    }
    printf("\n");
}

//错误的输出，因为a成为了指针类型，之前定义的是二维数组，指针类型的步长为8，不会和之前一样加一行的步长
//如果a之前定义的也是char**就是可以的，
//void print_array1(char** a)
//{
//    printf("a is %d, a+1 is %d\n",a, a+1);
//    int i;
//    for(i = 0; i < 3; i++)
//    {
//        printf("%s\n", *(a+i));
//    }
//}

//对二维数组进行排序
void sort_array(char a[][20], int n)
{
    int i,j;
    char temp[20];
    for(i = 0; i < n-1; i++)
    {
        for( j = i+1; j < n; j++)
        {
            if(strcmp(a[i], a[j])>0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }

    }
}

int main()
{
    //对于2维数数组，不写第一个[]有条件，必须初始化
    //a代表首行地址，首行地址和首行首元素地址有区别，但是值是一样的
    //区别：步长不一样。
    char a[3][20] = {"123","abc","456"};
    printf("a is %d, a+1 is %d\n", a, a+1);
    int n = sizeof(a)/ sizeof(a[0]);
    int b[20];
    printf("&b is %d, &b+1 is %d\n", &b, &b+1);

    //排序前
    print_array(a);
    //print_array1(a);

    sort_array(a, n);

    //排序后
    print_array(a);
    return 0;
}
