#ifndef STOCK20_H_
#define STOCK20_H_

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
    Stock();
    Stock(const std::string &no , long n=0, double pr=0.0);
    void acquire(const std::string &co ,long n,double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show() const;
    const Stock & topVal(const Stock & s )const;//add
    ~Stock();
};
inline void Stock::set_tot(){
    total_val=share_val*shares;
}


#endif