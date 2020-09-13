#include <iostream>
#include <string>//封装了char*, 是一个char* 类型容器,或者说类

using namespace std;

int main()
{
    string s = "qwer";

    //区别:()方式如果访问越界，直接挂了
    //at方式访问越界抛异常out_of_range
    cout<<s.at(0)<<" "<<s[0]<<endl;

    return 0;
}