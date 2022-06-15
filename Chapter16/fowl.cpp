#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main()
{
    auto_ptr<string>films[5]=
    {
        auto_ptr<string>(new string("A")),
        auto_ptr<string>(new string("B")),
        auto_ptr<string>(new string("C")),
        auto_ptr<string>(new string("D")),
        auto_ptr<string>(new string("E"))
    };

    /*
        ����ֻ���AB��������Ϊ�����ʹ����auto_ptr��ԭ����pwin = films[2] ��佫����Ȩ��film[2]ת����pwin��
        �⵼��filmp[2]�������ø��ַ�������auto_ptr�����ö��������Ȩ�󣬱����ʹ���������ʸö��󡣵������ӡfilm[2]ָ����ַ���ʱ��ȴ�������Ǹ���ָ�롣
        �����shared_ptr����auto_ptr���������������
        ������Ϊpwin��film[2]ָ��ͬһ�����󣬶����ü�����1���ӵ�2.�ڳ���ĩβ����������pwin���ȵ������������������������������ü�������1.Ȼ��shared_ptr����ĳ�Ա���ͷţ�
        ��filmsp[2]������������ʱ�������ü�������0�����ͷ���ǰ����Ŀռ�
        ���ʹ��unique_ptr������auto_ptrһ��Ҳ��������Ȩģ�͡���ʹ��unique_ptrʱ�����򲻻�ȵ����н׶α��������ڱ���׶α���
        
    */

    auto_ptr<string>pwin;   //shared_ptr<string>pwin;
    pwin = films[2];
    cout<<"The nominees for best avian baseall film are\n";
    for(int i=0;i<5;i++)    cout<<*films[i]<<endl;
    cout<<"The winner is "<<*pwin<<"!\n";
    cin.get();

    return 0;
}