#include "dwrui.h"
#include "ui_dwrui.h"
#include "user.h"
#include "trie.h"
#include <cstring>
#include <QMessageBox>
extern User* user;
extern Trie* idTree[100005];
DWRUI::DWRUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DWRUI)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("存取款记录"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小

    int len = user -> getDWRecords() -> getLenth();
    table = new QTableWidget(len, 2, this);
    table -> setColumnWidth(0, 400);
    table -> setColumnWidth(1, 400);
    QStringList headerText;
    headerText<<"日期"<<"金额";
    table -> setHorizontalHeaderLabels(headerText);
    table -> move(230, 100);
    table -> resize(800, 500);

    int x = user -> getDWRecords() ->getHead();
    for (int i = 0; i < len; ++i) {
        int m = user -> getDWRecords() -> getRecordM(x);
        QString money = QString::number(user -> getDWRecords() -> getRecordM(x));
        table -> setItem(i, 1, new QTableWidgetItem(money));
        table -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(user -> getDWRecords() -> getRecordT(x))));
        x = x % 100005 + 1;
    }
}

DWRUI::~DWRUI()
{
    delete ui;
}


void DWRUI::on_exist_clicked()
{
    close();
}
