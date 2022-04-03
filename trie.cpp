#include "trie.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

extern Trie* idTree[100005];
extern int cnt;

Trie::Trie()
{
    id = -1;  // 数组下标（null=-1）
    num = 0;  // 占用次数
    for(int i = 0; i < 10; i++)
    {
        next[i] = -1;  // 指向下一个结点的位置（NULL=-1）
    }
}

void Trie::Insert(QString str, int id)
{
    QByteArray sa = str.toLatin1();
    char* s = sa.data();
    int len = str.size();
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        int n = s[i] - '0';

//        QString sn = QString::number(idTree[j]->next[n]);
//        QMessageBox::information(NULL, "Tips", sn);

        if(idTree[j]->next[n] == -1)
        {
            idTree[++cnt] = new Trie();
            idTree[j]->next[n] = cnt;
        }
        idTree[j]->num++;
        j = idTree[j]->next[n];
    }
    idTree[j]->id = id;

}

int Trie::Find(const QString str)
{
    QByteArray sa = str.toLatin1();
    char* s = sa.data();
    int len = str.size();
    int j = 0;

    for(int i = 0; i < len; i++)
    {
        int n = s[i] - '0';
        if(idTree[j]->next[n] == -1) return -1;  // 没找到
        j = idTree[j]->next[n];
    }
    if(idTree[j]->id >= 0)
        return idTree[j]->id;  //到达最后一层找到目标id
    return -1;
}

bool Trie::Delete(QString str)
{
    QByteArray sa = str.toLatin1();
    char* s = sa.data();
    int len = str.size();
    int j = 0;

    for(int i = 0; i < len; i++)
    {
        int n = s[i] - '0';
        if(idTree[j]->next[n] == -1)
        {
            idTree[j]->num = 0;
            return false;  // 没找到
        }
        if(idTree[(idTree[j]->next[n])]->num == 1)
        {
            delete idTree[(idTree[j]->next[n])];
            idTree[j]->next[n] = -1;
            idTree[j]->num--;
            return true;
        }
        if(idTree[j]->num > 1) idTree[j]->num--;
        j = idTree[j]->next[n];
    }
    return false;
}
