### �������
```c++
//������
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
    //��������
    Test a;     //����Ĭ�Ϲ��캯��
    Test2 b;    //error����������й��캯���������������ִ��Ĭ�Ϲ��캯������Ҫ�Լ�����
    Test2 b(5); //
}
```

### thisָ��
```c++
    Test2 a(4);
    Test2 b(2);
    Test2 c= b.cmp(a); 
    //�ο�testĿ¼
```