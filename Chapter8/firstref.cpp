#include <iostream>

using namespace std;

int main()
{
    int rats=101;
    int& rodents=rats;  //rodents��������int&
    cout<<"rats = "<<rats<<endl;
    cout<<"rodents = "<<rodents<<endl;
    rats++;
    cout<<"rats = "<<rats<<endl;
    cout<<"rodents = "<<rodents<<endl;

    cout<<"rats address = "<<&rats<<endl;
    cout<<"rodents address = "<<&rodents<<endl;


    //��ָ�븳ֵ������
    int *pt=&rats;
    int& tmp=*pt;
    cout<<"*pt = "<<*pt<<endl;
    cout<<"tmp="<<tmp<<endl;
    int num2=200;
    pt=&num2;
    cout<<"*pt = "<<*pt<<endl;
    cout<<"tmp="<<tmp<<endl;    //tmp��ֵ��Ȼ��rats��ֵ
    return 0;
}