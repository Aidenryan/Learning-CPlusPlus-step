//
// Created by lcx on 2020/8/20.
//指针数组
//
#include <stdlib.h>
#include <stdio.h>

void print_array1(char** p, int n)
{
    //printf("p is %d, p+1 is %d\n",p, p+1);//变成了指针
    int i ;
    for( i = 0; i < n; i++)
    {
        printf("%s ", p[i]);
    }
    printf("\n");

}

void print_array2(char* p[], int n)
{
    //printf("p is %d, p+1 is %d\n",p, p+1);
    int i ;
    for( i = 0; i < n; i++)
    {
        printf("%s ", p[i]);
    }
    printf("\n");

}

int main()
{
    char* p[] = { "qwe", "asd", "zxc"};
    //char** p = { "qwe", "asd", "zxc"}; //error 指针不能指向多个内存，上面那个是指针数组，这里是指针
    //printf("size of the point_array is %d", sizeof(p));
    //printf("\n%s", p[0]);

    print_array1(p, sizeof(p)/ sizeof(p[0]));
    print_array2(p, sizeof(p)/ sizeof(p[0]));
    return 0;
}



