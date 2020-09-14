#include <iostream>
#include <string.h>
using namespace std;

class test
{
/*
会有默认的无参构造函数:
    -->当没有任何***显示的构造函数（显示的无参构，显示有参，显示拷贝构造）***的时候，默认无参构造函数就会出现
会有默认的拷贝构造函数:
    -->当没有**显示的拷贝构造***的函数，默认的拷贝构造就会出现。
会有默认的析构函数
    --〉当没有***显示的析构函数*者的时候，默认的析构函数就会出现。
*/
public:
    //显式提供一个有参数的构造函数，默认的构造函数就不复存在
    test(int x, int y)//含参构造函数
    {
        m_x = x;
        m_y = y;
    }
    test()//无参构造函数
    {
        m_x = 1;
        m_y = 1;
    }

    test(int x)//重载
    {
        m_x = x;
        m_y = 10;
    }

    //析构函数和构造函数都没有返回值，析构函数没有形参，不存在重载
    //析构函数调用的顺序，跟构造相反，谁先构造的，谁后析构。
    ~test(){}

    //拷贝构造函数，显示的。如果没有显示，便会调用默认拷贝构造函数
    test( const test &another)
    {
        m_x = another.m_x;
        m_y = another.m_y;
    }

    // = 赋值操作符
    void operator=(const test &another)
    {
        m_x = another.m_x;
        m_y = another.m_y;
    }

private:
    int m_x;
    int m_y;
};

test fun()
{
    test t1(10,20);
    return t1;
}//匿名对象 = t1, 匿名对象拷贝构造

void test1()
{
    //返回一个匿名对象。当一个函数返回一个匿名对象的时候，函数外部没有任何
    //变量去接收它，这个匿名对象将不会再被使用，（找不到），编译会直接将个这个匿名对象回收掉，而不是等待整改函数执行完毕再回收.
    fun();

}
void test2()
{
    //并不会触发tl拷贝，而是将匿名对象转正t1，把这个匿名对象起了名字就叫t1，所以匿名对象相当于在函数结束时被析构
    test t1 = fun();
}

void test3()
{

    test t1;//t1已经被初始化，
    t1 = fun();//匿名对象会在赋值操作后，被立刻析构，
}

/*  深拷贝 浅拷贝问题*/
class A
{
public:
    A(int id, char *name)
    {
        m_id = id;
        int len = strlen(name);
        m_name = (char*)malloc(len+1);
        strcpy(m_name, name);
    }

    A( const A &another)
    {
        //m_name = another.m_name;//浅拷贝，会出现重复释放的问题
        //深拷贝
        int len = strlen(another.m_name);
        m_name = (char*)malloc(len+1);
        strcpy(m_name, another.m_name);
        m_id =  another.m_id;
    }

    ~A()
    {
        if(m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
    }
private:
    char *m_name;
    int m_id;
};

void funa()
{
    A a(1,"jkk");
    A b(a);

}
int main()
{
    funa();
    std::cout << "Hello, World!" << std::endl;
    test t1(10,20);

    // !!!构造函数是对象初始化的时候调用
    test t2(t1);//调用t2的拷贝构造函数，等价于 test t2 = t1;

    /*
    test t3;
    t3 = t1; //调用的不是t3拷贝构造函数，而是t3的赋值操作符函数
    */
    return 0;
}