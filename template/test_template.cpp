//
// Created by lcx on 2020/9/3.
//
#include "test_template.h"
#include <iostream>
using namespace std;
template <typename T>
B<T>::B(T a, T b)
{
    num = a;
    id = b;
}

template <typename T>
void B<T>::show() {
    cout<<num<<" "<<id<<endl;
}
