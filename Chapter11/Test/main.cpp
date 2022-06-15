#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    Test a(4);
    Test b(2);
    Test c = a + b;
    c.print();

    int num=2;
    c = a * num; //a.operator * (num)
    c.print();

    c = num * a;//friend Time operator * (int &a, const Test&b) 
    c.print();

    c = a - b;
    c.print();

    c= a / b;
    c.print();

    //cout<<c;

    //cout<<"11"<<c<<"22"<<endl; error
    cout<<" qaq "<< c <<" qwq "<<endl;   
    //cout<< c << " qaq" << "qwq"<<endl; 
    return 0;
}