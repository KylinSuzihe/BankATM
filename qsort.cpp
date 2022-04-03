#include "qsort.h"
#include <QDebug>
extern User* users[10000];
extern int userNum;
Qsort::Qsort()
{

}
void Qsort::qsort(int low, int high) {
    if (low >= high) return;
    int L = low, R = high;
    a[0] = a[low];
    int pivotkey = a[low].money;
    while (low < high) {
        while (low < high && a[high].money <= pivotkey) --high;
        a[low] = a[high];
        while (low < high && a[low].money >= pivotkey) ++low;
        a[high] = a[low];
    }
    a[low] = a[0];
    qsort(L, low - 1);
    qsort(low + 1, R);
}
void Qsort::init(string st, string et) {
    for (int i = 1; i <= userNum; ++i) {  // 会有野指针弹窗，条件改为 i < userNum 后无弹窗可进入
        if (!users[i]) {
            a[i].money = -1;
            continue;
        }
        a[i].id = users[i] -> getId();
        a[i].money = users[i] -> getDWRecords() -> search(st, et);
        qDebug() << QString::number(a[i].money);
    }
    qDebug() << "qsort init ";
    qsort(1, userNum);
}
Qsort::rank* Qsort::getUser(){
    return this -> a;
}
