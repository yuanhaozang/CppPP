#include <iostream>
#include "func2.h"

void Fun2::print(void (*pf)())
{
    (*pf)();
}

