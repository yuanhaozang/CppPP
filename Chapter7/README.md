## 1.指针和const
```C++
//声明一个指向常量的指针
int age=20;
const int *pt=&age;
(*pt)++ //error 
++age;  //此时*pt也等于21

```
```C++
//将const变量的地址赋值给const指针
const int age2=20;
const int *pt2=&age2;
int *pt3=&age2  //error pt3会改变age2的值
(*pt2)++    //error
++age2      //error
int age3=20;
const int age4=20;
*pt3=age3;
*pt3=age4;

```
```C++
//将指针指向指针
int age=20;
int *pt=&age;
const int *pt2=pt;
cout<<"*pt2="<<*pt2<<endl;
cout<<"*pt="<<*pt<<endl;
cout<<"++(*pt)="<<++(*pt)<<endl;
cout<<"*pt2="<<*pt2<<endl;
int age2=30;
pt=&age2;
cout<<"*pt="<<*pt<<endl;
cout<<"*pt2="<<*pt2<<endl;  //此时*pt2等于21

const int **pt3;
pt3=&pt;    //error pt的值可以改变违背const
pt3=&pt2;   //虽然pt可以指向其它变量，但是并不会让pt2指向那个变量，所以pt3也就不会指向那个变量，但是++(*pt),影响pt2和pt3的值

```
## 2.函数指针
### 2.1获取函数的地址
*   获取函数地址的方法就是函数名。要将函数作为一个参数传递，必须传递函数名。

### 2.2声明函数指针
*   声明指针时必须指定指向的类型，所以，声明函数指针时，应该指定函数的类型，也就是函数的返回类型和函数的参数列表

```C++
//获取函数的地址
think();    //think就是函数的地址
process(think);//传递地址
process(think());//传递返回值

//声明函数指针
int add(int a);
int (*pt)(int a);

//typedef 简化

pt=add;
int num=add(3);
int num2=(*pt)(4);

void calc(int a , int (*pf)(int));
calc(4,add);
//参考fun_ptr.cpp
```



