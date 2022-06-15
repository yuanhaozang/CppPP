### 友元
*   友元类
    *   什么时候希望一个类称为另外一个类的友元呢？假定需要编写一个模拟电视机和遥控器的简单程序。决定定义一个TV类和Romote类，分别表示电视机和遥控器。很明显这两个类之间应该存在着某种关系，is-a关系表示表示派生类是基类的一种，显然并不适用，has-a关系表示派生类包含基类的一些属性，显然也不适用。事实上，遥控器可以改变电视机的状态，这表明Romote类作为Tv类的一个友元
    ```c++
    //tv.h
    /*
        从tv.h中可以看到Remote只有set_chan()方法是直接访问Tv成员的，因此它需要作为友元的方法。确实可以选择仅让特定的类成员作为另一个类的友元，而不必让整个类成为友元，但这样做有点麻烦，必须小心排列各种声明的定义的顺序。
    */

    //例如如果要将set_chan()方法成为Tv类的友元的方法是，在Tv类声明中将其声明位友元
    class Tv
    {
        friend void Remote::set_chan(Tv &t, int c);
    };
    /*
        然而，要使编译器能够处理这条语句，它必须知道Remote的定义。否则他无法知道Remote是一个类，set_chan是这个类的方法。这意味着Remote哟啊在Tv的前面定义。Remote类的其他方法用到了Tv类的对象，这意味着Tv类的定义应该放到Remote类前面。避免这种循环依赖的方法是前向声明。为此，需要在remote定义前插入下面这条语句
    */
    class Tv;
    class Remote{};
    class Tv{};

    //不能像下面这样排列，因为编译器在Tv类的声明中看到Remote的一个方法被声明为Tv类的友元之前，应该先看到Remote类的声明和set_chan()方法的声明
    class Remote;
    class Tv{};
    class Remote{};

    ```

### RTTI
*   C++有三个支持RTTI的元素
    *   dynamic_cast运算符将使用一个指向基类的指针来生成一个指向派生类的指针，否则该运算符返回0-空指针
    *   typeid运算符返回一个指出对象的类型的值
    *   type_info结构存储了有关特定类型的信息
    *   只能将RTTI用于包含虚函数的类层次结构，原因在于只有对这种类层次结构，才能将派生类对象的地址赋给基类指针
    *   RTTI只适用于包含虚函数的类

*   dynamic_cast 运算符
```c++
/*
    dynamic_cast 运算符是最常用的RTTI组件，它不能回答"指针指向的是那类对象"，但是可以回答"是否可以安全的将对象的地址赋给特定类型的指针"的问题
*/
class Grand(){};
class Superb:public Grand{};
class Magnificent:public Superb{};

Grand *pg = new Grand;
Grand *ps = new Superb;
Grand *pm = new Magnificent;

Magnificent *p1 = (Magnificent *)pm;    //安全
Magnificent *p2 = (Magnificent *)pg;    //不安全
Superb *p3 = (Magnificent *)pm;         //安全

//指针pg的类型是否可以安全的转换为Superb* 如果可以返回返回对象的地址，否则返回NULL
Superb *pm = dynamic_cast<Superb *>(pg);

//rtti1.cpp
for(int i=0;i<5;i++)
{
    pg = GetOne();
    pg->Speak();
    if(ps = dynamic_cast<Superb *>(pg)) ps->Say();
}
//GetOne()函数可以使pg指向三个随机对象的一种，但是只有Speak类和它的派生类有Say方法，所以可以用dynamic_cast判断是否可以将pg指向的对象转换为Superb类型来判读能否调用Say方法

```


### 类型转换运算符
*   dynamic_cast
    *   该运算符的作用是，使得能够在类层次结构中进行向上转换(由于is-a关系，这样的转换使安全的)，不允许其他转换
*   const_cast
    *   该运算符用于执行只有一种用途的类型转换，即改变值为const或volatile
    ```c++
        High bar;
        const High *pbar = &bar;
        High *pb = const_cast<High *>(pbar);
        /*
            *pb 成为一个可用于修改bar对象值的指针，删除了const标签。
            提供该运算符的原因是，有时候需要这样一个值，它在大多数时候是常量，而有时候又可以修改的。在这种情况下把变量声明为const，并在需要修改的时候用这个运算符
            const_cast 不是万能的。它可以修改指向一个值的指针，但修改const的结果是不确定的，参考constcast.cpp
        */ 
    ```
*   static_cast
    ```c++
        static_cast<a>(b);
        //仅当a可以被隐式转换为b所属的类型或b可以被隐式转换为a所属的类型时，才合法。假设High是Low的基类，Pond是一个无关的类
        High bar;
        Low blow;

        High *pb = static_cast<High *>(&blow);  //合法
        Low  *pl = static_cast<Low *>(&bar);    //合法
        Pond *pmer = static_cast<Pond *>(&blow);//不合法

    ```
*   reinterpret_cast

