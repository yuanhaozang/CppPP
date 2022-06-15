// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using namespace std;
#include "strngbad.h"

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{

    StringBad test3;
    StringBad test4("test4");
   
    callme1(test3);
    callme2(test4); //调用默认拷贝构造函数

    StringBad test1 = test3;

    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}