//
// Created by lcx on 2020/8/26.
//

#include "Circle.h"

void Circle::set_r(float r)
{
    m_r = r;
}

float Circle::get_area()
{
    m_area = m_r*m_r*3.14;
    return m_area;
}

bool Circle::cmp(Circle &another)
{
    if(m_r == another.m_r)//同类之间无私处
        return true;
    return false;
}