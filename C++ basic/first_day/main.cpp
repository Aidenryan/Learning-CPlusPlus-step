//关于命名空间的知识
#include <iostream>

#if 0
//方法二
using std::cout;

//方法三
using namespace std;
#endif

//自定义命名空间
namespace myspaceA
{
    int g_a = 10;
}

//命名空间的嵌套
namespace myspaceB
{
    namespace myspaceC
    {
        struct stu
        {
            int id;
            char name[20];
        };
    }
}
int main()
{
    //方法一
    std::cout << "Hello, World!" << std::endl;

    std::cout << myspaceA::g_a << std::endl;

    myspaceB::myspaceC::stu stu1;
    stu1.id =5;


    return 0;
}