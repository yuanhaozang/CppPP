#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    Test *test1 ; 
    cout<<"test1"<<endl;
    //test1->print();

    Test *test2 = test1;
    cout<<"test2"<<endl;
    //test2->print();

    Test *test3 = new Test();
    cout<<"test3"<<endl;
    test3->print();

    Test *test4 = new Test;
    cout<<"test4"<<endl;
    test4->print();

    Test *test5 = new Test(3);
    cout<<"test5"<<endl;
    test5->print();

    Test arr[1];
    arr[0] = Test(33);

    Test *test6 = &arr[0];
    cout<<"test6"<<endl;
    test6->print();


    return 0;
}