#ifndef FUNC2_H
#define FUNC2_H
#include <iostream>
typedef void (*callback)(); 
class Fun2
{
    public:
        void print(callback p);
};

#endif