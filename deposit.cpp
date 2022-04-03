#include "deposit.h"
#include "ui_deposit.h"
#include "user.h"
#include <cstring>
#include <iostream>
using namespace std;
extern User *user;
int save_money;
QString s;
Deposit::Deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Deposit"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小
         //显示预备存款
    browser = new QLabel;
    browser -> setParent(this);
    browser -> setGeometry(600,155,100,50);
    browser -> setText("0");
            //返回按钮
    back = new QPushButton(this);
    back -> setText("Return");
    back -> setParent(this);
    back -> resize(200,60);
    back -> move(750,500);
    connect(back, &QPushButton::clicked, this, &Deposit::Exsit);
            //确定键按钮
    act = new QPushButton(this);
    act -> setText("Determine");
    act -> setParent(this);
    act -> resize(200, 60);
    act -> move(150, 500);
    connect(act, &QPushButton::clicked, this, &Deposit::Act);
            //数据清零
    clearing = new QPushButton(this);
    clearing -> setText("Clearing");
    clearing -> setParent(this);
    clearing -> resize(200,60);
    clearing -> move(450,500);
    connect(clearing, &QPushButton::clicked, this, &Deposit::clean);

    //存款提示信息
    inputLabelDeposit = new QLabel(this);
    inputLabelDeposit -> setText("Please select the deposit amount:");
    inputLabelDeposit -> setAlignment(Qt::AlignCenter);
    inputLabelDeposit -> resize(300,100);
    inputLabelDeposit -> move(300,130);
         //选择存款金额
         //选择金额
    inputOne = new QPushButton(this);
    inputOne -> setText("100");
    inputOne -> setParent(this);
    inputOne -> resize(200,60);
    inputOne -> move(150,200);
    connect(inputOne, &QPushButton::clicked, this, &Deposit::save100);
    inputTwo = new QPushButton(this);
    inputTwo -> setText("300");
    inputTwo -> setParent(this);
    inputTwo -> resize(200,60);
    inputTwo -> move(150,300);
    connect(inputTwo, &QPushButton::clicked, this, &Deposit::save300);
    inputThree = new QPushButton(this);
    inputThree -> setText("500");
    inputThree -> setParent(this);
    inputThree -> resize(200,60);
    inputThree -> move(150,400);
    connect(inputThree, &QPushButton::clicked, this, &Deposit::save500);
    inputFour = new QPushButton(this);
    inputFour -> setText("1000");
    inputFour -> setParent(this);
    inputFour -> resize(200,60);
    inputFour -> move(750,200);
    connect(inputFour, &QPushButton::clicked, this, &Deposit::save1000);
    inputFive = new QPushButton(this);
    inputFive -> setText("2000");
    inputFive -> setParent(this);
    inputFive -> resize(200,60);
    inputFive -> move(750,300);
    connect(inputFive, &QPushButton::clicked, this, &Deposit::save2000);
    inputSix = new QPushButton(this);
    inputSix -> setText("3000");
    inputSix -> setParent(this);
    inputSix -> resize(200,60);
    inputSix -> move(750,400);
    connect(inputSix, &QPushButton::clicked, this, &Deposit::save3000);

}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::Act()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString time = currentTime.toString("yyyy/MM/dd");

    char *s=(char *)malloc(10);
    QByteArray ba=time.toLatin1();
    strcpy(s,ba.data());

    user -> saveMoney(save_money, s);

    QMessageBox::information(NULL, "Tips", "Successful deposit!");
    clean();
}

void Deposit::Exsit()
{
    close();
}
void Deposit::clean()
{
    save_money = 0;
    count();
}
void Deposit::count()
{
    s = "";
    int ls = save_money;
    int i = 100;
    while (save_money / i) i *= 10;
    i /= 10;
    while (i) {
        s += (ls / i) + '0';
        ls %= i;
        i /= 10;
    }
    browser -> setText(s);
}

void Deposit::save100()
{
    save_money += 100;
    count();
}
void Deposit::save300()
{
    save_money += 300;
    count();
}
void Deposit::save500()
{
    save_money += 500;
    count();
}
void Deposit::save1000()
{
    save_money += 1000;
    count();
}
void Deposit::save2000()
{
    save_money += 2000;
    count();
}
void Deposit::save3000()
{
    save_money += 3000;
    count();
}
