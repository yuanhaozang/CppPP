| **继承方式** |  **说明**   |
|  ----       |   ----      |
| public      | 基类的public和protected的成员被派生类继承后，保持原来的状态 |
| private     | 基类的public和protected的成员被派生类继承后，变成派生类的private成员|
| protected   | 基类的public和protected的成员被派生类继承后，变成派生类的protected成员 |

注：无论何种继承方式，基类的private成员都不能被派生类访问。从上面的表中可以看出，声明为public的方法和属性都可以被随意访问;声明为protected的方法和属性只能被类本身和子类访问;而声明为private的方法和属性只能被当前类的对象访问

1.友元函数必须在类中声明在类外定义，声明时须在返回类型前加上关键字friend。友元函数虽然不是类的成员函数，但是它可以访问类中的私有和保护类型的数据成员

2.虚函数在重新定义时，参数的个数和类型必须和基类中的虚函数完全一致，这一点和函数重载不同

3.#include<文件名>和#include "文件名"
* 文件包含的两种方式，第一种是用来包含由系统提供的并放到指定子目录中的头文件;第二种是用来包含由用户自己定义的放在当前目录或其它目录下的头文件或其它源文件


4.重载，覆盖和隐藏的区别

**函数的重载**是指C++允许存在多个同名的函数，按时各个函数的参数必须有区别:参数的个数不同或者参数的个数相同但类型不同

**函数的覆盖**是指派生类中存在重新定义的函数，其函数名，参数列表，返回值类型必须同父类中的被覆盖的函数完全一致，覆盖函数和被覆盖函数只有函数体不一样，当派生类对象调用子类中该同名函数时会自动调用子类中的覆盖版本，而不是父类中的被覆盖的版本，这种机制叫做覆盖。

**以上内容参考test.cpp**

**从成员函数的角度来讲述重载和覆盖的区别**

**成员函数被重载的特征**
| 相同的范围 | 函数名相同 | 参数不同 | virtual关键字可有可无 |
| ----      | ----      |  ----   |     ----              | 



**覆盖的特征**
| 不同的范围 | 函数名相同 | 参数相同 | 基类函数必须有virtual关键字 |
| ----      | ----      |  ----   |     ----                    |


**隐藏**是指派生类的函数屏蔽了与其同名的基类的函数，规则如下
* 如果派生类的函数与基类的函数同名，但是参数不同。此时不论有无virtual关键字，基类函数都将被隐藏
* 如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时基类函数也被隐藏
* 参考test2.cpp

test2.cpp中f()函数属于覆盖，g()和h()属于隐藏。**在覆盖中**，基类指针和派生类指针调用f()时，系统都是执行的派生类的函数f(),而非基类的f()。**在隐藏中**，派生类指针和基类指针都调用h()函数时，系统会进行区分，基类指针调用时，系统执行基类的h(),而派生类指针调用时，系统隐藏了基类的h(),执行派生类的h(),这就是“隐藏”的由来

**重载**：在同个space域同名的。参数必须不同

**覆盖**:同名字，同参数，有virtual。覆盖好理解比如show()函数，A派生了B，如果B中的show()覆盖了A中的show()，但B中仍然有两个show(),而不管是A类指针也好,B类对象调用也好,都只能调用B类自己的那个show();而从A类继承过来的show()函数真的就被覆盖了,没有了吗? 答案是不对的.这时可以在B类对象显示的调用A类继承过来的show();**参考test3.cpp**。

总结：通俗的讲B类中还是有两个show(),只是调用有A继承过来的show()只能通过显示的调用方法[类名::virtual 函数名] 而不管是基类A的指针(B b; A*p=&b p->show())还是派生类的对象(B b; b.show())，都只能调用B类的自己本身存在的show()函数

**隐藏hide**
* 同名同参无virtual，有virtual就是覆盖
* 同名不同参，不管有无virtual
* 参考test4.cpp

5.派生类和基类的关系
* 派生类对象可以调用基类中非private的方法。基类指针可以在不进行显示转换的情况下指向派生类对象，基类引用可以在不进行显示转换的情况下引用派生类对象。不过基类指针和引用只能调用基类的方法，通常C++要求引用和指针类型与赋给的类型匹配，但这一规则对继承来说是个例外。不过这种例外只是单向的，不可以将基类对象和地址赋给派生类引用和指针。

6.静态联编和动态联编
* 程序调用函数时，将执行那个代码块呢？编译器负责回答这个问题。将源代码中的函数调用解释为执行特定函数代码块被称为函数名联编。在C语言中这是简单的，因为每个函数名都对应一个不同的函数。然而C/C++编译器可以编译过程中完成这种联编。在编译过程中进行联编被称为静态联编/绑定，又称为早期联编/绑定。不过虚函数使这项工作变的更困难。因为使用哪个函数是不能在编译时确定的，因为编译器不知道用户选择那种类型的对象。所以，编译器必须生成能够在程序运行时选择正确的虚函数方法的代码，这被称为动态联编/绑定，又被称为晚期联编/绑定