### 派生类
*   派生类对象存储了基类的数据成员
*   派生类对象可以使用基类的方法
*   派生类需要自己的构造函数
*   派生类可以根据需要添加额外的数据成员和成员函数
*   派生类构造函数：访问权限的考虑
    *   派生类不能直接访问基类的私有成员，必须通过基类的方法访问。
    *   派生类创建对象时，程序首先创建基类对象。
    *   ```c++
        //例如tabtenn1.cpp
        /*
            :TableTennisPlayer(fn,ln,ht)是成员初始化列表。他是可执行的代码，调用TableTennisPlayer构造函数。例如：
            RatedPlayer rplayer1(1140,"Mallory","Duck",true)
            则 RatePlayer 构造函数把实参"Mallory"、"Duck"、true赋给形参fn、ln、ht，然后将这些参数作为实参传递给TableTennisPlayer 构造函数，后者创建一个嵌套TableTennisPlayer对象，并将数据存储到该对象中。然后程序进入RatePlayer 构造函数体，完成RatePlayer对象的创建，并将参数r的值赋给rating


        */
        RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
                         const string &ln, bool ht):TableTennisPlayer(fn,ln,ht)
        {
            rating = r;
        }


        /*
            如果省略成员初始化列表，情况会如何呢？

            必须首先创建基类对象，如果不调用基类构造函数，程序将使用默认的基类构造函数，因此上面代码和下面代码等效

            除非使用默认构造函数，否则应显示调用正确的基类构造函数。

        */
        RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
                            const string &ln, bool ht)
        {
            rating = r;
        }

        /*
            下面这个构造函数，由于tp的类型的TableTennisPlayer &，因此将调用基类的复制构造函数。基类没有定义的话，编译器会自动生成一个。在这种情况下执行成员复制的隐式复制构造函数是合适的，因为这个类没有使用动态内存分配。(复制构造函数可以参考12章)


        */

        RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp):TableTennisPlayer(tp),rating(r)
        {

        } 

        ```
    *   派生类构造函数的要点如下
        *   首先创建基类对象
        *   派生类构造函数应通过成员初始化列表将基类信息传给基类构造函数
        *   派生类构造函数应初始化派生类新增的数据成员
    *   派生类与基类之间的关系
        *   派生类可以使用基类的方法，前提是方法不是私有的
        *   基类指针可以在不进行显示类型转换的情况下指向派生类对象；基类引用可以在不进行显示类型转换的情况下引用派生类对象,然而基类指针或者引用只能用于调用基类方法。通常c++要求引用和指针的类型与赋给的类型匹配，但这一规则对继承来说是例外。然而，这种例外是单向的，不可以将基类对象和地址赋给派生类引用和指针
        ```c++
            RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
            TableTennisPlayer &rt = rplayer;
            TableTennisPlayer *pt = &rplayer;

            rt.Name();
            pt->Name();

        ```
        *   上述规则是有道理的，例如，如果允许基类引用隐式地引用派生类对象，则可以使用基类引用为派生类对象调用基类的方法。因为派生类继承了基类的方法，所以这样做不会出现问题。如果可以将基类对象赋给派生类引用，将发生什么情况？派生类引用能够为基类对象调用派生类方法，这样做将出现问题。例如，将RatedPlayer::Rating()方法用于TableTennisPlayer对象是没有意义的，因为TableTennisPlayer对象没有rating成员。如果将基类引用和指针可以指向派生类对象，将出现一些有趣的结果。其中之一就是基类引用定义的函数或指针参数可用于基类对象或派生类对象。例如：
        ```c++

            void show(const TableTennisPlayer &rt)
            {
                cout<<"Name: ";
                rt.Name();
                cout<<"\nTable: ";
                if(rt.HasTable())
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }
            void wohs(const TableTennisPlayer *pt)
            {

            } 

            TableTennisPlayer player1("Tara", "Boomdea", false);
            RatedPlayer rPlayer1(1140, "Mallory", "Duck", false);
            show(player);
            show(rpalyer1);

            wohs(&player);
            wohs(&rplayer);

        ```
        *   引用兼容性属性也让你能够将基类对象初始化为派生类对象，尽管不那么直接。假设有这样的代码
        ```c++
            RatedPlayer rPlayer1(1140, "Mallory", "Duck", false);

             TableTennisPlayer player1(rPlayer1);

             //要初始化palyer1，匹配的构造函数的原型如下
             TableTennisPlayer(const RatedPlayer &);

             //类定义中没有这样的构造函数，但是存在隐式复制构造函数如下，形参是基类引用，因此它可以引用派生类。这样palyer1初始化为rplayer1时，将要使用改构造函数
                TableTennisPlayer(const TableTennisPlayer &);  
            //同样，也可以将派生类对象赋给基类对象，这种情况下，程序将使用隐式重载运算符
            TableTennisPlayer & operator =(cosnt TableTennisPlayer &)const;
            player1 = rplayer1;

        ```
### 静态联编和动态联编
程序调用函数时，将使用哪个可执行的代码块呢？编译器负责回答这个问题。将源代码中的函数调用解释为执行特定的函数代码块被称为函数名联编。在C语言中，这非常简单，因为每个函数名都对应一个不同的函数。在C++中，由于函数重载的缘故，这项任务更复杂。编译器必须查看函数参数以及函数名才能确定使用哪个函数。然而，C/C++编译器可以在编译过程完成这种联编。在编译过程中进行联编是静态联编，又称为早期联编。然而，虚函数使这项工作变得更困难。使用哪一个函数是不能在编译时确定的，因为编译器不知道用户选择那个类型的对象。所以编译器必须生成能够在程序运行时选择正确的虚方法的代码，这被称为动态联编，或晚期联编

*   指针和引用类型的兼容
    *   在C++中，动态联编与通过指针和引用调用方法相关，从某种程度上来说这是由继承控制的。
    ```c++
        //通常C++不允许将一种类型的地址赋给另一种类型的指针，也不允许一种类型的引用指向类一种类型
        double  x = 2.5;
        int *p = &x;    //error
        long &x1 = x;   //error

        //然而，指向基类的引用或者指针可以引用派生类对象，而不必进行显式类型转换。
        BrassPlus dilly("AAA",123,123);
        Brass *pb = &dially;    //ok
        Brass &rb = dially;     //ok
    ```
    *   将派生类引用或指针转换为基类引用或者指针被称为向上强制转换，这是公有继承不需要显示类型转换。
    *   相反的将基类指针或引用转换为派生类指针或引用称为向下强制转换。如果不使用显示类型转换，则向下强制转换是不允许的。原因使is-a关系使不可逆的。派生类可以新增数据成员，因此使用这些数据成员的类成员函数不能应用于基类。
    ```c++
        void fr(Brass &rb); //use rb.ViewAcct()
        void fp(Brass *pb); //use pb->ViewAcct()
        void fv(Brass b);   //use b.ViewAcct()
        Brass b("Billy", 12, 23);
        BrassPlus bp("qe", 23, 34);
        fr(b); //Brass::View
        fr(bp) //BrassPlus::View
        fp(b);  //Brass::View
        fp(bp); //BrassPlus::View
        fv(b);  //Brass::View
        fv(bp); //Brass::View
        //按值传递导致只将BrassPlus对象的Brass部分传递给函数fv()。但是随引用和指针的隐式向上类型转换导致函数fr()和fp()分别为Brass对象和BrassPlus对象
    ```
    *   隐式向上强制转换使基类指针或引用可以指向基类对象或派生类对象，因此需要使用动态联编，C++使用需成员函数满足这种要求

*   虚成员函数和动态联编
    *   先来回顾下使用指针或引用调用方法的过程
    ```c++
        BrassPlus aa;
        Brass * bp;
        bp = aa;
        bp->ViewAcct(); 
    ```
    *   如果在基类里没有把ViewAcct()声明为虚的，则bp->ViewAcct()将根据指针类型(Brass *)调用Brass::ViewAcct()。指针类型在编译时已知，因此编译器在编译时，可以将ViewAcct()关联到Brass::ViewAcct()。总之编译器对非虚方法使用静态联编
    *   然而，如果在基类中声明为虚的，则则bp->ViewAcct()将根据对象类型(BrassPlus *)调用BrassPlus::ViewAcct()。在这个例子中，对象为BrassPlus，但通常只有在运行程序时才能确定对象类型。所以编译器生成的代码将在程序执行时，根据对象类型将ViewAcct()关联到基类的继承类的这个方法。总之，编译器对虚函数使用动态联编。

    *   为什么有两种类型的联编以及为什么默认为静态联编
        *   效率。  为了使程序能够在运行阶段进行决策，必须采用一些方法来跟踪基类指针或引用指向的对象类型，这增加了额外的处理开销。如果类不会作为基类就不需要动态联编。同样如果派生类不重定义基类的任何方法，也不需要动态联编。
        
        *   概念模型。  在设计类时，可能包含一些不在派生类重定义的成员函数。

    *   虚函数工作原理
        *   通常，编译器处理虚函数的方法是：给每个对象添加一个隐藏成员。隐藏成员中保存了一个指向函数地址数组的指针。这个数组称为虚函数表。虚函数表中存储了为类对象进行声明的虚函数地址。例如，基类对象包含一个指针，该指针指向基类中所有虚函数的地址表。派生类对象将包含一个指向独立地址表的指针。如果派生类提供了虚函数的新定义，改虚函数表将保存新函数的地址；如果派生类没有重定义虚函数，该虚函数表将保存函数原始版本的地址。如果派生类定义了新的虚函数，则该函数的地址也将被添加到虚函数表中。

### 继承和动态内存分配
