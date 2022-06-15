
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using namespace std;
/*
    记录会员的姓名以及是否有球桌

*/
class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;  //球桌

    public:
        TableTennisPlayer(const string &fn = "none",
                          const string &ln = "none",
                          bool ht = false);

        void Name()const;
        bool HasTable() const {return hasTable;}
        void ResetTable(bool v) { hasTable = v;} 
};

#endif
