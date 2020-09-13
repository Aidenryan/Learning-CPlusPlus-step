//
// Created by lcx on 2020/8/19.
//
#include <stdlib.h>
#include <stdio.h>
//将字符串的单数和双数位单独取出来存放
//pra 字符串首地址   单数存放内存首地址  偶数存放首地址
int fun(const char* src, char* l, char*r)
{
    if(src == NULL || l == NULL || r == NULL)
    {
        return 0;
    }
    int i;
    for(i = 0; src[i] != 0; i++)
    {
        if(i % 2 ==0)
        {
            *r =src[i];
            r++;
        }
        else
        {
            *l = src[i];
            l++;
        }

    }
    r[i] = 0;
    l[i] = 0;
    return 1;
}

int main()
{
    char buff[] = "1a2s3d4f";
    char* r = (char*)malloc(sizeof(char)*20);
    char* l = (char*)malloc(sizeof(char)*20);
    int ret = fun(buff, l, r);
    if(ret == 0)
    {
        printf("error !");
        return 0;
    }
    else
    {
        printf("%s\n", l);
        printf("%s\n", r);
    }
    return  0;
}
