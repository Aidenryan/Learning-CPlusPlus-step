//
// Created by lcx on 2020/8/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//值传递，形参的任何修改不会影响到实参
int getMem(char* p)
{
    p = (char*)malloc(sizeof(char)*20);
    strcpy(p, "jack");
    printf("%s\n", p);
}

//地址传递, 形参修改会影响到实参
int getMem2(char** p)
{
    char* temp = (char*)malloc(sizeof(char)*20);
    strcpy(temp, "jack");
    *p = temp;

    return 0;
}
void get_memory(char **p, int *p_len)
{
    //间接赋值是指针存在的最大意义
    *p = malloc(100);
    *p_len = 100;
}
int main()
{
    //输入：主调函数分配内存
    //输出：被调函数分配内存
    char * p = NULL;//没有分配内存
    int len = 0;
    get_memory(&p, &len);//想通过函数形参改变实参的值，必须通过地址传递
    int ret = 0;
    //ret = getMem(p);
    ret = getMem2(&p);
    if(ret != 0)
    {
        printf("getMem error: %d\n", ret);
        return  ret;
    }

    printf("output p is %s\n", p);
    free(p);
    return  0;
}

