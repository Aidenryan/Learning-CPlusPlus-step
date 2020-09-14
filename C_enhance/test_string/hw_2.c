//
// Created by lcx on 2020/8/24.
//
/*
有一个字符串符合以下特征("abcde,facccd,eeee,aaaa,e3eeee,ssss,"）

写两个函数(API)，输出以下结果
第一个API（第二种内存模型:二维数组)
1)以逗号分隔字符串，形成二推数组，并把结果传出
2）把二维数组行数运算结果也传出来
int spitstring (const char *str，char，char buf[10][30]，int *count);

第二个API（第三种内存模型:动态生成二维内存)
1)以逗号分隔字符串，形成—个二级指针。
2)把—共拆分多少行字符串个数传出
int spitstring2(const char *str， char c, char **myp int *count);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//动态分配内存函数
char** get_memory(int n)
{
    int i = 0;
    char** p = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
    {
        p[i] = (char*)malloc(30);
    }

    return p;
}
int spitstring (const char *str, char c, char buf[10][30], int *count)
{
    char *p = str;
    int len = 0;
    char *ret = NULL;
    int cnt = 0;
    do{
        ret = strchr(p,c);
        if( ret != NULL)
        {
            len = ret - p;
            if(len > 0)
            {
                strncpy(buf[cnt], p, len);
                buf[cnt][len] = 0;
                cnt++;
            }
            p = ret + 1;
        }
        else
        {
            strcpy(buf[cnt], p);
            cnt++;
            break;
        }
    }while ( *p != 0);

    *count = cnt;
    return 0;
}

int spitstring2(const char *str, char c, char **myp, int *count)
{
    char *p = str;
    int len = 0;
    char *ret = NULL;
    int cnt = 0;
    do{
        ret = strchr(p,c);
        if( ret != NULL)
        {
            len = ret - p;
            if(len > 0)
            {
                strncpy(myp[cnt], p, len);
                myp[cnt][len] = 0;
                cnt++;
            }
            p = ret + 1;
        }
        else
        {
            strcpy(myp[cnt], p);
            cnt++;
            break;
        }
    }while ( *p != 0);

    *count = cnt;
    return 0;
}

int main()
{
    char *p = {"abcde,facccd,eeee,aaaa,e3eeee,ssss,"};//原始数据
    char buf[10][30];//二维数组
    int count;

    char **buf2 = get_memory(6);//动态生成二维内存
    int count2;

    spitstring(p, ',', buf, &count);

    spitstring2(p, ',', buf2, &count2);

    int i;
    for(i = 0; i < count; i++)
    {
        printf("%s\n", buf2[i]);
    }
    //system("pause");
    return 0;
}
