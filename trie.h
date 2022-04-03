#ifndef TRIE_H
#define TRIE_H

// #include <string.h>
#include <QString>
class Trie
{
public:
    int id;  //id的数组下标, 只有id末尾的字符才为正值
    int num;  //访问次数
    int next[10];
    Trie();
    void Insert(QString str, int id);
    int Find(const QString str);
    bool Delete(QString str);
};

#endif // TRIE_H
