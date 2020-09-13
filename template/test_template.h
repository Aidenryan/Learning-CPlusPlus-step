//
// Created by lcx on 2020/9/3.
//

#ifndef TEMPLATE_TEST_TEMPLATE_H
#define TEMPLATE_TEST_TEMPLATE_H

template <typename T>
class B
{
public:
    B(T a, T b);
    void show();
private:
    T num;
    T id;
};
#endif //TEMPLATE_TEST_TEMPLATE_H
