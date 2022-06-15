#include <iostream>
#include "test.h"
Test::Test()
{
    
}
Test::Test(int a, int b)
{
    num1 =a;
    num2 =b;
}

void Test::add()
{
    std::cout<<num1+num2<<std::endl;
}

const Test& Test::cmp(const Test &a) const
{
    if(a.num1 > num1) return a;
    return *this;   
}
Test::~Test()
{
    std::cout<<"Bye Test"<<std::endl;
}