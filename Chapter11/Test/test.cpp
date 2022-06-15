#include <iostream>
#include "test.h"
using namespace std;
Test::Test()
{

}

Test::Test(int a)
{
    num = a;
}

void Test::print()
{
    cout<<num<<endl;
}
Test Test::operator + (const Test &a) const
{
    Test t;
    t.num = num + a.num;
    return t;
}

Test Test::operator * (int &a) const
{
    Test t;
    t.num = num * a;
    return t;
}

Test Test::operator - (const Test &a) const
{
    Test t;
    t.num = num - a.num;
    return t;
}

Test Test::operator / (const Test &a) const
{
    Test t;
    t.num = num / a.num;
    return t;
}

Test operator * (int &a, const Test &b)
{
    return b * a;   //use b.operator * (a);
}

/*
void operator << (std::ostream &os, Test &t)
{
    os <<"num = "<< t.num <<endl;
}
*/

ostream& operator << (ostream &os, Test &t)
{
    os << "num = "<<t.num;
    return os;
}
