#ifndef TEST_H
#define TEST_H

class Test
{
    private:
        int num1,num2;

    public:
        Test();
        Test(int a, int b);
        void add();
        const Test& cmp(const Test& a) const;
        ~Test();
};

#endif