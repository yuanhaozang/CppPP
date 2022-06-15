### 运算符重载
```c++
//参考Test目录
class Test
{
    public:
        int operator + (const Test &a)const;
        int operator - (const Test &a)const;
        int operator * (int &a)const;
        int operator / (const Test &a)const;  
}
```

### 友元
*   友元函数
    *   在类中声明，但它不是成员函数，不能通过::来使用
    *   虽然不是成员函数，但是和成员函数的访问权限相同
    *   在实现其功能时，不要在函数类型前加friend
*   友元类
*   友元成员函数

```c++
//友元函数的出现
//以Test目录下的代码为例

Test a(2);
int num = 2;
Test c = a * num;   //right
//equal to a.operator * (num);

Test d = num * a; //error
//equal to Time operator * (int a, Time b)   not declare

```

