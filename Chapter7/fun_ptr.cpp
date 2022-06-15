#include <iostream>
using namespace std;

double betsy(int);
double pam(int);
typedef double (*pf)(int);
void estimate(int lines , pf p);
int main()
{

    int code;
    cout<<"How many lines of code do you need?";
    cin>>code;
    cout<<"Here's Bestry's estimate:\n";
    estimate(code,betsy);
    cout<<"Here's Pam's estiamte:\n";
    estimate(code,pam);

    return 0;
}
double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int line , pf p)
{
    cout<<line<<" lines will take ";
    cout<<p(line)<<"hour(s)\n";
}