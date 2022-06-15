#include <iostream>
#include "test.h"
using namespace std;


int main()
{
    Test a;
    a.add();

    Test b(1,2);
    b.add();

    a = Test(2,3);
    a.add();

    b = Test(3,4);
    b.add();

    Test c = a.cmp(b);
    
    c.add();

    return 0;
}