#include "tfrui.h"
#include "ui_tfrui.h"
#include "Graph.h"
#include "trie.h"
#include <QMessageBox>
extern User* user;
extern Graph* tfRecord;
extern Trie* idTree[100005];

TFRUI::TFRUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TFRUI)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("转账记录"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小
    
    int pos = idTree[0]->Find(QString::fromStdString((user->getId())));
    int len = tfRecord->getLenth(pos);

    table = new QTableWidget(len, 3, this);
    table -> setColumnWidth(0, 300);
    table -> setColumnWidth(1, 300);
    table -> setColumnWidth(2, 300);
    QStringList headerText;
    headerText<<"日期"<<"接收人"<<"金额";
    table -> setHorizontalHeaderLabels(headerText);
    table -> move(230, 100);
    table -> resize(900, 500);

    AdjP p = tfRecord->edgeList[pos];
    if(p == nullptr) {
        //QMessageBox::information(NULL,"Tips","用户无记录");
        close();
    }
    else {
        if(p == nullptr) QMessageBox::information(NULL,"Tips","空指针");
        QString money = QString::number(p->money);
        table->setItem(0,2,new QTableWidgetItem(money));
        table->setItem(0,0,new QTableWidgetItem(QString::fromStdString(p->time)));
        table->setItem(0,1,new QTableWidgetItem(QString::fromStdString(p->recAccount)));
        int i = 1;
        while(p->next != nullptr && i < tfRecord->getLenth(pos)) {
            p = p->next;
            money = QString::number(p->money);
            table->setItem(i,2,new QTableWidgetItem(money));
            table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->time)));
            table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->recAccount)));
            i++;
        }
    }
}

TFRUI::~TFRUI()
{
    delete ui;
}

void TFRUI::on_exist_clicked()
{
    close();
}
