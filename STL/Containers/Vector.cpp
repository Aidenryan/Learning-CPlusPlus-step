//
// Created by lcx on 2020/9/8.
//
#include <iostream>
#include <vector>//动态数组，单口容器

using namespace std;

/*
    vector实现动态增长:
    当插入新元素的时候，如果空间不足，那么vector会重新申请更大的一块内存空间，
    将原空间数据拷贝到新空间，释放旧空间的数据，再把新元素插入新申请空间。
 */

void print_vector(const vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //两种遍历方法
    for(auto m:v)
        cout<<m<<" ";
    cout<<endl;
}
void test()
{
    //reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，不能引用容器内的元素.
    //resize是改变容器的大小，且在创建对象，因此，调用这个函数之后，就可以引用容器内的对象了.

    vector<int> v1, v2;
    v1.resize(2);//真实分配空间,在该容器尾部添加或删除一些元素，使容器达到指定的大小
    v2.reserve(2);//只是说允许你进入这么多元素，虚的
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    cout<<v2.size()<<" "<<v2.capacity()<<endl;
    v1.at(0) = 1;
    //v2.at(0) = 1;//抛出异常.reserve只是改变capaciy的值此时这些内存空间可能还是“野”的
    print_vector(v1);
    print_vector(v2);

}
int main()
{
    //四种构造函数初始化
    vector<int> v1;
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v2(arr, arr+ sizeof(arr)/ sizeof(int));
    vector<int> v3(v2.begin(), v2.end());
    vector<int> v4(v3);


    vector<int> v5 = v4;//重载等号赋值

    vector<int> v6(5,1);//五个1赋值


    //成员方法
    v1.assign(v6.begin(), v6.end());

    v1.swap(v4);//把v1和v4交换，把指向内存的指针进行交换，而不是内存数据交换

    //插入元素
    v1.insert(v1.begin()+2, 100);//vector 支持随机访问v1.begin()+2
    print_vector(v1);

    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    vector<int>(v1).swap(v1);//收缩空间
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    print_vector(v1);
    v1.reserve(100);//预留空间
    cout<<"*************test***********"<<endl;
    test();
    return 0;
}
