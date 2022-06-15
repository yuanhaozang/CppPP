### ��Ԫ
*   ��Ԫ��
    *   ʲôʱ��ϣ��һ�����Ϊ����һ�������Ԫ�أ��ٶ���Ҫ��дһ��ģ����ӻ���ң�����ļ򵥳��򡣾�������һ��TV���Romote�࣬�ֱ��ʾ���ӻ���ң��������������������֮��Ӧ�ô�����ĳ�ֹ�ϵ��is-a��ϵ��ʾ��ʾ�������ǻ����һ�֣���Ȼ�������ã�has-a��ϵ��ʾ��������������һЩ���ԣ���ȻҲ�����á���ʵ�ϣ�ң�������Ըı���ӻ���״̬�������Romote����ΪTv���һ����Ԫ
    ```c++
    //tv.h
    /*
        ��tv.h�п��Կ���Remoteֻ��set_chan()������ֱ�ӷ���Tv��Ա�ģ��������Ҫ��Ϊ��Ԫ�ķ�����ȷʵ����ѡ������ض������Ա��Ϊ��һ�������Ԫ�����������������Ϊ��Ԫ�����������е��鷳������С�����и��������Ķ����˳��
    */

    //�������Ҫ��set_chan()������ΪTv�����Ԫ�ķ����ǣ���Tv�������н�������λ��Ԫ
    class Tv
    {
        friend void Remote::set_chan(Tv &t, int c);
    };
    /*
        Ȼ����Ҫʹ�������ܹ�����������䣬������֪��Remote�Ķ��塣�������޷�֪��Remote��һ���࣬set_chan�������ķ���������ζ��RemoteӴ����Tv��ǰ�涨�塣Remote������������õ���Tv��Ķ�������ζ��Tv��Ķ���Ӧ�÷ŵ�Remote��ǰ�档��������ѭ�������ķ�����ǰ��������Ϊ�ˣ���Ҫ��remote����ǰ���������������
    */
    class Tv;
    class Remote{};
    class Tv{};

    //�����������������У���Ϊ��������Tv��������п���Remote��һ������������ΪTv�����Ԫ֮ǰ��Ӧ���ȿ���Remote���������set_chan()����������
    class Remote;
    class Tv{};
    class Remote{};

    ```

### RTTI
*   C++������֧��RTTI��Ԫ��
    *   dynamic_cast�������ʹ��һ��ָ������ָ��������һ��ָ���������ָ�룬��������������0-��ָ��
    *   typeid���������һ��ָ����������͵�ֵ
    *   type_info�ṹ�洢���й��ض����͵���Ϣ
    *   ֻ�ܽ�RTTI���ڰ����麯�������νṹ��ԭ������ֻ�ж��������νṹ�����ܽ����������ĵ�ַ��������ָ��
    *   RTTIֻ�����ڰ����麯������

*   dynamic_cast �����
```c++
/*
    dynamic_cast ���������õ�RTTI����������ܻش�"ָ��ָ������������"�����ǿ��Իش�"�Ƿ���԰�ȫ�Ľ�����ĵ�ַ�����ض����͵�ָ��"������
*/
class Grand(){};
class Superb:public Grand{};
class Magnificent:public Superb{};

Grand *pg = new Grand;
Grand *ps = new Superb;
Grand *pm = new Magnificent;

Magnificent *p1 = (Magnificent *)pm;    //��ȫ
Magnificent *p2 = (Magnificent *)pg;    //����ȫ
Superb *p3 = (Magnificent *)pm;         //��ȫ

//ָ��pg�������Ƿ���԰�ȫ��ת��ΪSuperb* ������Է��ط��ض���ĵ�ַ�����򷵻�NULL
Superb *pm = dynamic_cast<Superb *>(pg);

//rtti1.cpp
for(int i=0;i<5;i++)
{
    pg = GetOne();
    pg->Speak();
    if(ps = dynamic_cast<Superb *>(pg)) ps->Say();
}
//GetOne()��������ʹpgָ��������������һ�֣�����ֻ��Speak���������������Say���������Կ�����dynamic_cast�ж��Ƿ���Խ�pgָ��Ķ���ת��ΪSuperb�������ж��ܷ����Say����

```


### ����ת�������
*   dynamic_cast
    *   ��������������ǣ�ʹ���ܹ������νṹ�н�������ת��(����is-a��ϵ��������ת��ʹ��ȫ��)������������ת��
*   const_cast
    *   �����������ִ��ֻ��һ����;������ת�������ı�ֵΪconst��volatile
    ```c++
        High bar;
        const High *pbar = &bar;
        High *pb = const_cast<High *>(pbar);
        /*
            *pb ��Ϊһ���������޸�bar����ֵ��ָ�룬ɾ����const��ǩ��
            �ṩ���������ԭ���ǣ���ʱ����Ҫ����һ��ֵ�����ڴ����ʱ���ǳ���������ʱ���ֿ����޸ĵġ�����������°ѱ�������Ϊconst��������Ҫ�޸ĵ�ʱ������������
            const_cast �������ܵġ��������޸�ָ��һ��ֵ��ָ�룬���޸�const�Ľ���ǲ�ȷ���ģ��ο�constcast.cpp
        */ 
    ```
*   static_cast
    ```c++
        static_cast<a>(b);
        //����a���Ա���ʽת��Ϊb���������ͻ�b���Ա���ʽת��Ϊa����������ʱ���źϷ�������High��Low�Ļ��࣬Pond��һ���޹ص���
        High bar;
        Low blow;

        High *pb = static_cast<High *>(&blow);  //�Ϸ�
        Low  *pl = static_cast<Low *>(&bar);    //�Ϸ�
        Pond *pmer = static_cast<Pond *>(&blow);//���Ϸ�

    ```
*   reinterpret_cast

