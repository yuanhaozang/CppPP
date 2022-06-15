#include <iostream>
using namespace std;
int arr[]={1,2,3,4,5};
int sum_arr(int arr[],int n);
int main()
{
    cout<<"arr="<<arr<<endl;
    cout<<"数组大小:"<<sizeof(arr)<<endl;
    cout<<sizeof(arr[0])<<endl;
    int *p=NULL;
    cout<<sizeof(p)<<endl;
    int sum=sum_arr(arr,5);

    cout<<"sum="<<sum<<endl;

    return 0;
}
int sum_arr(int arr[],int n)
{
    cout<<"sum_arr begin\n";
    cout<<"arr="<<arr<<endl;
    cout<<"sizeof(arr)="<<sizeof(arr)<<endl;
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=*(arr+i);
    }
    cout<<"sum_arr end\n";
    return total;
}