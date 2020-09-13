//
// Created by lcx on 2020/9/8.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int test()
{
    /*

    deque双端数组，操作特点:在两端插入和删除效率都比较高，在指定位置插入，也会引起数据元素的移动，支持随机访问

    deque分段连续的内存空间

    stack容器规则:先进后出不能遍历不提供迭代器也不支持随机访问

    queue队列规则:先进先出不能遍历―不提供迭代器也不支持随机访问

    list容器非常常用ST中双向链表在任何位置插入和删除效率都比较好，因为插入和删除时候相对于数组来说，不需要移动元素
        缺点:不支持随机访问因为非莲续的内存空间，所以说为了保存结点和结点之间的前驱后继关系，需要额外的空间开销。
        自己提供了sort()方法，为什么? 因为不支持随机访问，如果使用算法提供的sort，效率会不稳定
        find(你要清楚，查我基础数据类型、查我对象、捷供回调(条件)

    set 容器注意是按照平衡二叉树写的，所以在插入数据时候已经排好序了，在查找或者排序时候，都会根据插入时候的排序依据来排序和查找

     map是以红黑树为底层实现的
*/

    //map容器模板参数，第一个参数key的类型，第二参数value类型
    map<int, int> my_map;

    //四种插入数据方式
    my_map.insert(10,10);

    my_map.insert( pair<int, int>(20, 20));

    my_map.insert( make_pair( 30, 30));

    //发现如果key不存在，创建pair插入到map容器中
    //如果发现key存在，那么会修改key对应的value
    my_map[40] = 40;//重要！！！

    //如果通过[]方式去访问map中一个不存在key,
    //那么map会将这个访问的key插入到map中,并且给value一个默认值


    return 0;

}

int main()
{

    return 0;
}