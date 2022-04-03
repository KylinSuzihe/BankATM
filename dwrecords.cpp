#include "dwrecords.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define lc u<<1//左儿子
#define rc u<<1|1//右儿子
#define mid (l+r)>>1//中点

void DWRecords::add(int u, int l, int r, int p, int x) {
    if (l > p || r < p) return;
    if (l == p && l == r) {
        sum[u] = x;
        return;
    }
    add(lc, l, mid, p, x), add(rc, (mid) + 1, r, p, x);
    sum[u] = sum[lc] + sum[rc];
}
int DWRecords::find(int u, int l, int r, int L, int R) {
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return sum[u];
    return find(lc, l, mid, L, R) + find(rc, (mid) + 1, r, L, R);
}
int DWRecords::erfen(int l, int r, string t) {
    int ans;
    while (l <= r) {
        string T = record[mid].time;
        if (T <= t) ans = (mid), l = (mid) + 1;
        else r = (mid) - 1;
    }
    return ans;
}

DWRecords::DWRecords() {
    head = 0; tail = 0;
    memset(record, 0, sizeof(record));
}
void DWRecords::insert(int x, string s) {
    tail = tail % lenth + 1;
    if (tail == head) head = head % lenth + 1;
    if (head == 0) head = 1;
    add(1, 1, lenth, tail, abs(x));
    record[tail].money = x;
    record[tail].time = s;
}
int DWRecords::search(string st, string et) {
    int L, R;
    if (head > tail) {
        if (st <= record[lenth - 1].time) {
            L = erfen(head, lenth - 1, st);
            while (record[L].time < st && L < lenth - 1) L++;
            if (et <= record[lenth - 1].time)
                R = erfen(head, lenth - 1, et);
            else R = erfen(1, tail, et);
        }
        else {
            L = erfen(1, tail, st);
            R = erfen(1, tail, et);
        }
    }
    else {
        L = erfen(head, tail, st);
        R = erfen(head, tail, et);
    }
    while (record[L - 1].time == st && L > head) L--;
    while (record[R + 1].time == et && R < tail) R++;
    if (L > R) return find(1, 1, lenth, L, lenth) + find(1, 1, lenth, 1, R);
    return find(1, 1, lenth, L, R);
}

int DWRecords::getLenth() {
    if (head < tail) return tail - head + 1;
    else if (head == tail) return 0;
    return lenth - head + 1 + tail;
}
int DWRecords::getTail() {
    return this -> tail;
}

int DWRecords::getHead() {
    return this -> head;
}

int DWRecords::getRecordM(int x) {
    return this -> record[x].money;
}
string DWRecords::getRecordT(int x) {
    return this -> record[x].time;
}
