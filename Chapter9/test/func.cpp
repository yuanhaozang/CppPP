#include "func.h"
#include "func2.h"
#include <iostream>
void Fun::print()
{
    std::cout<<"Fun::printf()"<<std::endl;   
}

void Fun::test()
{
    Fun2 t;
    t.print(print);
    //std::cout<<"AAA"<<std::endl;
}