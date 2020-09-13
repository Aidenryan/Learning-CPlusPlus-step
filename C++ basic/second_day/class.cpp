//
// Created by lcx on 2020/8/26.
//
#include <iostream>
#include "Circle.h"
using namespace std;

/*
struct和class矣键字区别
在用struct定义类时，所有成员的默认属性为public
在用class定义类时，所有成员的默认属性为private
*/
#if 0
class stu
{
public:

protected: //保护控制权限。在类的继承中跟private有区别，在单个类中，跟private是一模一样。

private:
};
#endif

int main()
{

    Circle roll;
    roll.set_r(3.1);
    float area = roll.get_area();
    cout<<" the circle area is "<<area<<endl;
    return 0;
}