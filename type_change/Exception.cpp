//
// Created by lcx on 2020/9/7.
//
#include <iostream>

using namespace std;

void fun( int a, int b)
{
    if(b == 0)
        throw "there is a zero";
    a = a / b;
}
int main()
{
    try {
        fun(1,0);
    }
    catch (const char* e)
    {
        cout<<e<<endl;
    }

    return 0;
}
