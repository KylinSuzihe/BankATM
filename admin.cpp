#include "admin.h"
#include "ui_admin.h"
#include <QDateTimeEdit>
#include <QDebug>
extern int userNum;

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("银行账户流水排行榜"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小

    //int len = user -> getDWRecords() -> getLenth();
    table = new QTableWidget(userNum, 2, this);
    table -> setColumnWidth(0, 400);
    table -> setColumnWidth(1, 400);
    QStringList headerText;
    headerText<<"用户"<<"金额(净流水)";
    table -> setHorizontalHeaderLabels(headerText);
    table -> move(230, 100);
    table -> resize(800, 500);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_search_clicked()
{
    QString st = ui -> startTime -> text();
    QString et = ui -> endTime -> text();
    char* s = (char*)malloc(10);
    char* e = (char*)malloc(10);

    QByteArray b = st.toLatin1();
    strcpy(s, b);
    b = et.toLatin1();
    strcpy(e, b);

    Qsort *sort = new Qsort();
    sort -> init(s, e);

    for (int i = 0; i < userNum; ++i) {
        if (sort->a[i + 1].money == -1) continue;
        qDebug() << QString::fromStdString(sort ->a[i + 1].id);
        table -> setItem(i, 0, new QTableWidgetItem(QString::fromStdString(sort ->a[i + 1].id)));
        table -> setItem(i, 1, new QTableWidgetItem(QString::number(sort->a[i + 1].money)));
    }
}

void Admin::on_exist_clicked()
{
    close();
}
