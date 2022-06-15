#include <iostream>
using namespace std;

class Base
{
    public:
        void g(float x)
        {
            cout<<"Base::g(float) "<<x<<endl;
        }

        void h(float x)
        {
            cout<<"Base::h(float) "<<x<<endl;
        }

        virtual void f(float x)
        {
            cout<<"Base::f(float) "<<x<<endl;
        }

};

class Derived : public Base
{
    public:
        virtual void f(float x)
        {
            cout<<"Derived::f(float) "<<x<<endl;
        }

        void g(int x)
        {
            cout<<"Derived::g(int) "<<x<<endl;
        }

        void h(float x)
        {
            cout<<"Derived::h(float) "<<x<<endl;
        }
};

int main()
{
    Derived d;
    Base *pb=&d;    //基类指针

    Derived *pd=&d; //派生类指针
    pb->f(float(3.14));
    pd->f(float(3.14));

    pb->g(float(3.14));
    pd->g(11);

    pb->h(float(3.14));
    pd->h(float(3.14));

    return 0;
}