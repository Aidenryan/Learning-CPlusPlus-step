//
// Created by lcx on 2020/8/22.
//
//动态打造二维数组
//c提高第三天
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//测试函数，后面对其封装
int main_test()
{
    char *p0 = NULL;
    p0 = (char*)malloc(sizeof(char*)*10);
    strcpy(p0, "abc");

    //q[10]
    int* q = (int*)malloc(10* sizeof(int));//相当于q[10]

    //动态分配一个数组 char *buff[10]
    int n = 3;
    int i;
    char **buff = (char**)malloc(n * sizeof(char*));
    //为每个指针分配空间
    for(i = 0; i < n; i++)
    {
        buff[i] = (char*)malloc(20);
        char str[20];
        sprintf(str, "test%d%d", i, i);
        strcpy(buff[i], str);
    }

    //输出打印
    for(i = 0; i < n; i++)
    {
        printf("%s ", buff[i]);
    }
    printf("\n");

    //释放空间
    for(i = 0; i < n; i++)
    {
        free(buff[i]);
        buff[i] = NULL;

    }
    if(buff != NULL)
    {
        free(buff);
        buff =NULL;
    }
    return 0;
}

//分配内存
char** get_memory( int n)
{
    int i;
    char **buff = (char**)malloc(n * sizeof(char*));
    //为每个指针分配空间
    for(i = 0; i < n; i++)
    {
        buff[i] = (char*)malloc(20);
        char str[20];
        sprintf(str, "test%d%d", i, i);
        strcpy(buff[i], str);
    }
    return buff;
}

//打印数组
void print_array( char** buff, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%s ", buff[i]);
    }
    printf("\n");
}

//释放内存
void free_array( char** buff, int n )
{
    int i;
    for(i = 0; i < n; i++)
    {
        free(buff[i]);
        buff[i] = NULL;

    }
    if(buff != NULL)
    {
        free(buff);
        buff =NULL;
    }
}

int main()
{

    char **buff = NULL;
    int n = 3;
    buff = get_memory(n);

    print_array(buff, n);

    free_array(buff, n);
    buff = NULL;
    return 0;

}