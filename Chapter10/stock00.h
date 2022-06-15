#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private:
    /* data */
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot();
public:
    Stock(/* args */);
    void acquire(const std::string &co ,long n,double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
    ~Stock();
};
inline void Stock::set_tot(){
    total_val=share_val*shares;
}


#endif