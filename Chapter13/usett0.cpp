#include <iostream>
#include "tabtenn0.h"
using namespace std;

int main()
{
    TableTennisPlayer player1("��", "��", true);
    TableTennisPlayer player2("��", "��", false);

    player1.Name();
    if(player1.HasTable())
    {
        cout<<": has a table\n";
    }
    else
    {
        cout<<": hasn't a table\n";
    }

    player2.Name();
    if(player2.HasTable())
    {
        cout<<": has a table\n";
    }
    else
    {
        cout<<": hasn't a table\n";
    }



    return 0;
}