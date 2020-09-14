#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int trimspace( char* input, char* output)
{
    int start = 0;
    int end = strlen(input) - 1;

    while(input[start] == ' ')
        start++;
    while(input[end] == ' ')
        end--;

    int len = end - start + 1;
    //printf("%d\n", len);
    int i;

    for(i = 0; i < len ; i++)
    {
        output[i] = input[start];
//        int j;
//        for(j = 0; output[j] != 0; j++)
//        {
//            printf("%d: %c  ", j, output[j]);
//        }
//        printf("\n");
        start++;
    }
    //output[i] = 0;
    return 0;

}
int main()
{
    char buff[] = " abcdef ";
    int i;
    for(i =0; i< strlen(buff); i++)
    {
        printf("%c", buff[i]);
    }
    printf("\n");

    char *dst= (char*)malloc(sizeof(char)*100);
    trimspace(buff, dst);
    int n = strlen(dst);
    //printf("%d\n", n);
    for(i =0; i< n; i++)
    {
        printf("%c", dst[i]);
    }

    return 0;
}
