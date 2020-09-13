//
// Created by lcx on 2020/9/9.
//
#include <iostream>


using namespace std;

//仿函数
class Myprint
{
public:
    Myprint(){ mNum = 0;}
    void operator()(int val)
    {
        cout<<val<<endl;
        mNum++;
    }
    int mNum;
};
int main()
{
    //函数对象可以像普通函数一样调用
    //函数对象可以像普通函数那样接收参数
    //函数对象超出了函数的概念，函数对象可以保存函数调用的状态
    Myprint myprint;
    myprint(10);
    myprint(20);
    cout<<myprint.mNum<<endl;
    return 0;
}
