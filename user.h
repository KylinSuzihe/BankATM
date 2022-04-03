#ifndef USER_H
#define USER_H

#include <iostream>
#include "dwrecords.h"

using namespace std;

class User
{
private:
    string id;
    int money;
    string password;
    DWRecords *dwrecords;

public:
    User();
    User(string, string);
    static int getNum();
    static int getEmpty();
    int getMoney();
    string getId();
    string getPassword();
    void setId(string);
    void setPassword(string);
    void setMoney(int);
    void setDerecords(int, string);
    int getDerecords(string, string);
    void saveMoney(int,string);
    bool withdrawalMoney(int,string);
    DWRecords* getDWRecords();
};

#endif // USER_H
