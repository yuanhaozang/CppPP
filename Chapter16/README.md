### 智能指针模板类
```c++
    void demo1()
    {
        double *pd  = new double; //1
        *pd = 25.5; //2
        return ;    //3
    }
    /*
        1.为pd和double分配存储空间，保存地址
        2.将值赋值到动态内存中
        3.删除pd，值被保留在动态内存中
    */

    void demo2()
    {
        auto_ptr<double>ap(new double); //1
        *ap = 25.5;
        return ;
    }
    /*
        1.为ap和double分配空间，保存地址
        2.将值复制到动态内存中
        3.删除ap，ap的析构函数释放动态内存

    */

```

*   有关智能指针的注意事项
    ```c++
    auto_ptr<string> ps (new string("i reigned lonely as a cloud"));
    auto_ptr<string> vocation;
    vocation = ps;
    /*
        如果ps和vocation是常规指针，则两个指针指向同一个string对象。这是不能接受的，因为程序试图将删除同一个对象两次，一次是ps过期，一次是vocation过期。要避免这种问题方法有很多种。
        *   定义赋值运算符，使之执行深拷贝。这样两个指针指向不同的对象，其中一个对象是另一个对象的副本。
        *   建立所有权概念，对于特定的对象，只能有一个智能指针可拥有它，这样只有拥有对象的智能指针的构造函数会删除该对象。然后，让赋值操作转让所有权。这就是用于auto_ptr和unique_ptr的策略，但后者更加严格
        *   创建智能更高的指针，跟踪引用特定对象的智能指针数。这称为引用计数。例如，赋值时，技术加1，而指针过期时，计数减1.仅当最后一个指针过期时，才调用delete。这是shared_otr采用的策略。

    */


    /*
        fowl.cpp
        
    */

    ```
