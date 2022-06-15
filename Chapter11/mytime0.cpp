#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hourse=minutes=0;
}

Time::Time(int h,int m)
{
    hourse=h;
    minutes=m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hourse  += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hourse += h;
}

void Time::Reset(int h,int m)
{
    minutes = m;
    hourse  = h;
}

Time Time::Sum(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hourse  = hourse  + t.hourse + sum.minutes/60;
    sum.minutes = sum.minutes % 60;

    return sum;
} 

void Time::show() const
{
    std::cout<<hourse<<" hourse "<<minutes<<" minutes "<<std::endl;
}