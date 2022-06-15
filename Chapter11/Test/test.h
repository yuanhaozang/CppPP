#ifndef TEST_H
#define TEST_H
class Test
{
    private:
        int num;
    
    public:
        Test(int a);
        Test();
        void print();
        Test operator + (const Test &a)const;
        Test operator - (const Test &a)const;
        Test operator * (int &a)const;
        Test operator / (const Test &a)const;  
        //Test operator * (int b, const Test &a);   error
        friend Test operator * (int &a, const Test &b);
        //friend void operator << (std::ostream &os, Test &t);
        friend std::ostream& operator << (std::ostream &os, Test &t);
};

#endif