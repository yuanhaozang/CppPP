#include <iostream>
using namespace std;
template <typename T>
void Swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b= tmp;
}

template <typename T>
void Swap(T *a, T *b, int n)
{
    T tmp;
    for(int i=0;i<n;i++)
    {
        tmp  = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}
int main()
{
    int num1 = 10;
    int num2 = 20;
    Swap(num1,num2);
    cout<<"num1= "<<num1<<" num2="<<num2<<endl;


    int a[10]={1,2,3,4,5,6,7,8,9};
    int b[10]={11,12,13,14,15,16,17,18,19};

    Swap(a,b,5);
    for(int i=0;i<5;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
        cout<<"b["<<i<<"]="<<b[i]<<endl;
    }


    return 0;
}