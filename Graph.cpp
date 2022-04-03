#include "Graph.h"

extern User* user;
extern User* users[10000];
extern Trie* idTree[100005];

// 构造函数
Graph::Graph()
{
    edgeList = new AdjP[ADJLIST_INIT_SIZE];
    if(edgeList == nullptr) {  //建立边表失败
        //QDebug() << "边表建立失败!" << endl;
        exit(NO_ENOUGH_MEMORY);
    }
    for(int i = 0; i < ADJLIST_INIT_SIZE; i++)
        edgeList[i] = nullptr;
    capacity = ADJLIST_INIT_SIZE;  // 初始化邻接表容量
    length = 0;  //初始化邻接表长度
}

// 析构函数
Graph::~Graph()
{
    delete[] edgeList;  //释放动态存储空间
}

// 添加转账记录
bool Graph::AddRecord(string rev, int money, string time)
{
    int pos = idTree[0]->Find(QString::fromStdString((user->getId())));
    if(length >= capacity)
        QMessageBox::information(NULL, "Tips", "邻接表已满，不能保存新用户的转账信息!");
    
    if(edgeList[pos] == nullptr) {
        edgeList[pos] = new AdjNode;
        length++;
        edgeList[pos]->recAccount = rev;
        edgeList[pos]->money = money;
        edgeList[pos]->time = time;
        edgeList[pos]->next = nullptr;
        return true;
    } else {
        AdjP p = edgeList[pos];
        while( p->next != nullptr)
            p = p->next;
        p->next = new AdjNode;
        length++;
        p->next->recAccount = rev;
        p->next->money = money;
        p->next->time = time;
        p->next->next = nullptr;
        return true;
    }
    return false;
}

int Graph::getLenth(int pos)
{
    int count = 1;
    AdjP p = edgeList[pos];
    if(p == nullptr)
        return 0;
    while(p->next != nullptr) {
        p = p->next;
        ++count;
    }
    return count;
}
