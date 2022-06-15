#include <iostream>
using namespace std;

class A
{
    public:
        void show(){}
        void rose(int a){}
};

class B : public A
{
    public:
        void show(){}
        void rose(int a , int b){}
};

int main()
{
    A*p=new B;
    p->show();
    p->rose(3);
    //p->rose(3,5); error

    B b;
    b.show();
    b.rose(3,5);
    //b.rose(3); error



    return 0;
}