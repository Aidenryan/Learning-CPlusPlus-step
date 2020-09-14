//
// Created by lcx on 2020/8/24.
//还有一点bug,不知道为什么会在输出前面出现别的字符
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
原字符串 src:
生成的或需要填充的字符串 dst:
sub: 需要查找的子字符串
new_sub:提换的新子字符串
return : 0成功 -1失败
int replaceSubstr(/* in * / char *src，/* out * / char** dst, * in * / char *sub,/* in * / char *new_sub);
*/

int replaceSubstr(char *src, char **dst, char *sub, char *new_sub)
{
    char * p = src;
    char *ret = NULL;
    //char *temp = (char*)malloc(200);
    char temp[500];
    do{
        ret = strstr(p, sub);
        if(ret != NULL)
        {
            int n = ret - p;
            if( n > 0) {
                strncat(temp, p, n);
            }
            strncat(temp, new_sub, strlen(new_sub));

            p = ret + strlen(sub);
        }
        else
        {
            strcat(temp, p);
            break;
        }

    }while( *p != 0);

    char *buff = (char*)malloc(strlen(temp)+1);
    strcpy(buff, temp);

    *dst = buff;

    //*dst = temp;
    return 0;
}
int main()
{
    char *p = {"abcd1111abcd2222abcdqqqqq"};

    char *out = NULL;
    char * sub = "abcd";
    char * new_sub = "FFFF";
    replaceSubstr(p, &out, sub, new_sub);

    printf("%s\n", out);
    return 0;
}
