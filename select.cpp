#include "select.h"
#include "ui_select.h"

extern User* user;
extern User* users[10000];
extern Trie* idTree[100005];

select::select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("ATM options"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小

    saveMoney = new QPushButton(this);
    saveMoney -> setText("Deposit");
    saveMoney -> setParent(this);
    saveMoney -> resize(200, 100);
    saveMoney -> move(200, 130);
    connect(saveMoney, &QPushButton::clicked, this, &select::toDeposit);

    getMoney = new QPushButton(this);
    getMoney -> setText("Withdraw money");
    getMoney -> setParent(this);
    getMoney -> resize(200, 100);
    getMoney -> move(530, 130);
    connect(getMoney, &QPushButton::clicked, this, &select::toGetMoney);

    check = new QPushButton(this);
    check -> setText("Query account balance");
    check -> setParent(this);
    check -> resize(200, 100);
    check -> move(860, 130);
    connect(check, &QPushButton::clicked, this, &select::toCheck);

    turn = new QPushButton(this);
    turn -> setText("Transfer accounts");
    turn -> setParent(this);
    turn -> resize(200, 100);
    turn -> move(200, 400);
    connect(turn, &QPushButton::clicked, this, &select::toTurn);

    exist = new QPushButton(this);
    exist -> setText("Exist");
    exist -> setParent(this);
    exist -> resize(200, 100);
    exist -> move(530, 400);
    connect(exist, &QPushButton::clicked, this, &select::toExist);

    cance = new QPushButton(this);
    cance -> setText("Cancellation");
    cance -> setParent(this);
    cance -> resize(200, 100);
    cance -> move(860, 400);
    connect(cance, &QPushButton::clicked, this, &select::toCancellation);

    dwr = new QPushButton(this);
    dwr -> setText("DWRecords");
    dwr -> setParent(this);
    dwr -> resize(200, 100);
    dwr -> move(1100, 400);
    connect(dwr, &QPushButton::clicked, this, &select::toDwrUi);

    tfr = new QPushButton(this);
    tfr -> setText("TFRecords");
    tfr -> setParent(this);
    tfr -> resize(200, 100);
    tfr -> move(1100, 130);
    connect(tfr, &QPushButton::clicked, this, &select::toTfrUi);

}

select::~select()
{
    delete ui;
}

void select::toDeposit()
{
    sm = new Deposit;
    sm -> exec();
}
void select::toGetMoney()
{
    gm = new GetMoney;
    gm -> exec();
}
void select::toCheck()
{
    ch = new class Check;
    ch -> exec();
}
void select::toTurn()
{
    tur = new class Transfer;
    tur -> exec();
}
void select::toExist()
{
    close();
}
void select::toCancellation()
{
    QString deleteID = QString::fromStdString(user->getId());
    int re = idTree[0]->Find(deleteID);
    idTree[0]->Delete(deleteID);
    delete users[re];
    users[re] = nullptr;
    QMessageBox::information(NULL, "Tips", "成功销毁账户!");
    close();
}
void select::toDwrUi() {
    dwrui = new DWRUI();
    dwrui -> exec();
}
void select::toTfrUi() {
    tfrui = new TFRUI();
    tfrui -> exec();
}

