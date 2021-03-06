## 内联函数 
内联函数是C++为提高程序速度所做的一项改进。常规函数调用使程序跳到另一个地址(函数的地址)，并在函数结束时返回。内联函数则直接执行函数的代码块。不需要来回跳动。
这样做虽然运行速度会变快，但是内存的占用会变多，如果有10个不同的地方都调用同一个内联函数，那么内联函数就会有十个副本。

如果执行函数代码的时间比函数调用的时间还要长，那么节省的时间只占用很小一部分。如果函数代码执行的时间很短，则内联调用就可以节省很大一部分时间。
## 引用变量
引用是已定义的变量的别名，如果将twain作为clement变量的引用，则可以交替使用这两个变量

*   创建引用变量
```C++
//参考firstref.cpp


```

## 左值和右值
左值是可寻址的变量，有持久性。右值一般是不可寻址的常量，或在表达式求值过程中创建的无名临时对象，短暂性的。
左值和右值的主要区别之一是左值是可以被修改的，右值不能

## 左值引用和右值引用
左值引用:引用一个对象
右值引用:就是必须绑定到右值的引用，C++11中右值引用可以实现"移动语义"，通过&&获得右值引用
```C++
int x = 6;  //x是左值，6是右值
int &y = x; //左值引用，y引用x

int &z1 = x*6;  //error x*6 是右值
const int &z2 = x*6;    //正确，可以将const绑定到右值

int &&z3 = x*6; //右值引用
int &&z4 = x;   //error x是左值
``` 
## 为何要返回引用
传统返回机制和传递函数参数类似，计算return 后面的表达式，并将结果返回给调用函数。从概念上说，这个值是被复制到一个临时位置，而调用程序将使用这个值。如果返回引用，不会生成临时变量，直接使用引用的值。

* 返回引用需要注意的问题
    *   应该避免返回函数终止时不再存在的内存单元的引用。
    ```C++
    const int &add(int &a, int &b)
    {
        int c=a+b;
        return c;
    }
    ```
## 函数模板
```C++
/*
    声明
*/
template <typename T>
void Swap(T &a, T &b)
{
    T tmp;
    tmp = A;
    A = B;
    B = tmp;
}

/*
    重载
*/
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
```
## 编译器选择使用哪个函数版本
对于函数重载 、函数模板、函数模板重载，C++须在一个良好的策略来决定函数调用使用哪一个函数定义，尤其是有多个参数时。这个过程称为**重载解析**，它的运行过程如下
*   第一步：创建候选函数列表。其中包括与被调用函数的名称相同的函数和模板函数
*   第二步：使用候选函数列表创建可行函数列表。这些都是参数数目正确的函数，为了有一个隐式转换序列，其中包括实参类型与相应的形参类型完全匹配的情况。
*   第三步：确定是否有最佳的可行函数。如果有，则使用它，否则该函数调用出错。