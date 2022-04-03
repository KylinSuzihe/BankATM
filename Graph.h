#ifndef GRAPH_H
#define GRAPH_H

#include <QDebug>
#include "mainwindow.h"
#include <iostream>
using namespace std;

#define ADJLIST_INIT_SIZE 100  // 邻接表初始化大小
#define ADJLIST_INCREMENT 50  // 邻接表增量
#define NO_ENOUGH_MEMORY -1  // new申请动态存储空间失败返回值

// 邻接点节点(Adjacent Node)的定义
struct AdjNode {
    string recAccount;  // 转账的收款账户对应的数组下标
    int money;  //转账金额
    string time;  // 转账时间
    struct AdjNode* next;  // 指向下一个邻接点的指针
};
using AdjP = struct AdjNode*;  // 邻接点指针

// 图的定义
class Graph
{
public:
    AdjP* edgeList;  // 邻接表边表
    int capacity;  // 邻接表容量
    int length;  // 邻接表长度(当前有效边表节点/已注册账户个数)

    Graph();
    ~Graph();
    bool AddRecord(string rev, int money, string time);  // 添加转账记录

    int getLenth(int pos);
};

#endif // GRAPH_H
