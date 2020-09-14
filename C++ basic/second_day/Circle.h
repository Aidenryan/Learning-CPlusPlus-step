//
// Created by lcx on 2020/8/26.
//

#ifndef SECOND_DAY_CIRCLE_H
#define SECOND_DAY_CIRCLE_H


class Circle
{
public:
    void set_r(float r);
    float get_area();
    bool cmp(Circle &another);
private:
    float m_r;
    float m_area;
};


#endif //SECOND_DAY_CIRCLE_H
