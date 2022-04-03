#ifndef QSORT_H
#define QSORT_H
#include <iostream>
#include <cstdio>
#include "user.h"

using namespace std;

class Qsort
{
private:
    void qsort(int, int);
public:
    Qsort();
    struct rank {
        string id;
        int money;
    }a[10000];
    void init(string, string);
    rank* getUser();
};

#endif // QSORT_H
