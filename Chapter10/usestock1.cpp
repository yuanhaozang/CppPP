#include <iostream>
#include "stock10.h"
#include "stock10.cpp"
int main(){
    {
        using std::cout;
        cout<<"Using constructors to create new object\n";
        Stock Stock1("NanoSmart",12,20.0);
        Stock1.show();
        Stock Stock2=Stock("Boffo Objects",2,2.0);
        Stock2.show();

        cout<<"Assigning stock1 to stock2: \n";
        Stock2=Stock1;
        cout<<"Listing stock1 and stock2: \n";
        Stock1.show();
        Stock2.show();

        cout<<"Using a constructor to reset an object\n";
        Stock1=Stock("Nifty Foods",10,50.0);
        cout<<"Revised stock1: \n";
        Stock1.show();
        cout<<"Done\n";
    }


    return 0;
}