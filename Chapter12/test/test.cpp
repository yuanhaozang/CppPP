#include <iostream>
#include "test.h"

Test::Test()
{
    std::cout<<"default Test"<<std::endl;
    num = 0 ;
}

Test::Test(int a)
{
    num = a;
}

void Test::print()
{
    std::cout<<num<<std::endl;
}

Test::~Test()
{
    std::cout<<"bye"<<std::endl;
}