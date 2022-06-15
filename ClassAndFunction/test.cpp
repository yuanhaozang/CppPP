/*
    此程序用于演示重载和覆盖

*/
#include <iostream>
using namespace std;

class Base
{
    public:
        void f(int x)
        { 
            cout<<"Base::f(int) "<<x<<endl;
        }
        void f(float x)
        { 
            cout<<"Base::f(float) "<<x<<endl;
        }
        virtual void g(void)
        { 
            cout<<"Base::g(void)"<<endl;
        }
};

class Derived : public Base
{
    public:
        virtual void g(void)
        {
            cout<<"Derived::g(void)"<<endl;
        }
};

int main()
{
    Derived d;
    Base *pb=&d;
    pb->f(11);
    pb->f((float)34.5);
    pb->g();

    return 0;
}