### ���������
```c++
//�ο�TestĿ¼
class Test
{
    public:
        int operator + (const Test &a)const;
        int operator - (const Test &a)const;
        int operator * (int &a)const;
        int operator / (const Test &a)const;  
}
```

### ��Ԫ
*   ��Ԫ����
    *   �������������������ǳ�Ա����������ͨ��::��ʹ��
    *   ��Ȼ���ǳ�Ա���������Ǻͳ�Ա�����ķ���Ȩ����ͬ
    *   ��ʵ���书��ʱ����Ҫ�ں�������ǰ��friend
*   ��Ԫ��
*   ��Ԫ��Ա����

```c++
//��Ԫ�����ĳ���
//��TestĿ¼�µĴ���Ϊ��

Test a(2);
int num = 2;
Test c = a * num;   //right
//equal to a.operator * (num);

Test d = num * a; //error
//equal to Time operator * (int a, Time b)   not declare

```

