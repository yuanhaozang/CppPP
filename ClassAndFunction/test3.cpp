#include <iostream>
using namespace std;

class A
{
    public:
        virtual void show()
        {
            cout<<"A::show() "<<a<<endl;
        }
        int a;
};

class B : public A
{
    public:
    /*
        显式地调用自己类中的 "由A类继承过来的show()函数" ，
        像这种直接显式指出某个类的某个函数时, 编译器处理方式是这样的: 
        首先在自己类中找有没有A::show(),如果找到,调用.不在继续在A类中找，如果找不到,则在显式指出的那个类中(即A类)调用那个函数. 
        这里当然是在B类中可以找到A::show() ，因为基类中指出了这个函数是virtual函数.
    */
        void show()
        {
            A::show();
            cout<<"B::show() "<<b<<endl;
        }
        int b;
};
int main()
{
    A a;
    a.a=3;
    a.show();

    B b;
    b.b=10;
    b.show();
    b.A::show();



    return 0;
}