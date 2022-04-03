#ifndef DWRECORDS_H
#define DWRECORDS_H
#include <iostream>
#include <cstdlib>
using namespace std;

class DWRecords  //存取款记录
{
    static const int lenth = 100005;
    struct record{
        int money;
        string time;
    }record[lenth + 1];
    int head, tail;
    int sum[(lenth + 1) << 2];
private:

    void add(int, int, int, int, int);
    int find(int, int, int, int, int);
    int erfen(int, int, string);
public:
    DWRecords();
    void insert(int, string);
    int search(string, string);
    int getLenth();
    int getTail();
    int getHead();
    int getRecordM(int x);
    string getRecordT(int x);
};

#endif // DWRECORDS_H
