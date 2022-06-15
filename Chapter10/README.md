### 类与对象
```c++
//类声明
#include <iostream>
class Test
{
    public:
            int num;
    private:
            void func();

};

class Test2
{
    public:
            int num;
                Test2(int a);
                const Test2& cmp(Test2 &a) const
                {
                    if(a.num > num) return a;
                    return *this;
                } 
    private:
            void func();
};
int main()
{
    //对象声明
    Test a;     //调用默认构造函数
    Test2 b;    //error，如果类中有构造函数，则编译器不会执行默认构造函数，需要自己定义
    Test2 b(5); //
}
```

### this指针
```c++
    Test2 a(4);
    Test2 b(2);
    Test2 c= b.cmp(a); 
    //参考test目录
```