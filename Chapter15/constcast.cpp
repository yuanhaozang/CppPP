#include <iostream>
using std::cout;
using std::endl;

void change(const int *pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000;

    cout<<"pop1,pop2: "<<pop1<<", "<<pop2<<endl;
    change(&pop1, -103);
    change(&pop2, -103);

    cout<<"pop1, pop2: "<<pop1<<", "<<pop2<<endl;

    /*
        pop1的值改变，但pop2的值并没有改变，这是因为pop2是const类型是不允许改变的，仅当指针指向的值不是const类型是，const_cast才会改变值
    */
    return 0;
}

void change(const int *pt, int n)
{
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}