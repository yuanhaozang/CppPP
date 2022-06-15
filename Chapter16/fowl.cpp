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
        程序只输出AB，这是因为错误的使用了auto_ptr。原因是pwin = films[2] 语句将所有权从film[2]转换到pwin，
        这导致filmp[2]不在引用该字符串。在auto_ptr放弃该对象的所有权后，便可能使用它来访问该对象。当程序打印film[2]指向的字符串时，却发现这是个空指针。
        如果用shared_ptr代替auto_ptr，则程序正常运行
        这是因为pwin和film[2]指向同一个对象，而引用计数从1增加到2.在程序末尾，后声明的pwin首先调用其析构函数，该析构函数将引用计数降到1.然后，shared_ptr数组的成员被释放，
        对filmsp[2]调用析构函数时，将引用计数降到0，并释放以前分配的空间
        如果使用unique_ptr，它和auto_ptr一样也采用所有权模型。但使用unique_ptr时，程序不会等到运行阶段崩溃，而在编译阶段报错
        
    */

    auto_ptr<string>pwin;   //shared_ptr<string>pwin;
    pwin = films[2];
    cout<<"The nominees for best avian baseall film are\n";
    for(int i=0;i<5;i++)    cout<<*films[i]<<endl;
    cout<<"The winner is "<<*pwin<<"!\n";
    cin.get();

    return 0;
}