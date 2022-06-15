#include <iostream>
#include "mytime0.cpp"
using namespace std;

int main()
{
    Time planning;
    Time codeing(2,40);
    Time fixing(5,55);
    Time total;

    cout<<"planning time = ";
    planning.show();
    cout<<endl;
    
    cout<<"codeing time = ";
    codeing.show();
    cout<<endl;

    cout<<"fixing time = ";
    fixing.show();
    cout<<endl;

    total = codeing.Sum(fixing);
    cout<<"codeing.Sum(fixing) = ";
    

    return 0;
}