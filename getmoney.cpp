#include "getmoney.h"
#include "ui_getmoney.h"
#include "user.h"
extern User *user;
int get_money;
QString s_get;
GetMoney::GetMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetMoney)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("Withdraw money"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小

    //显示预备取款
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
    connect(back, &QPushButton::clicked, this, &GetMoney::Exsit);

    //确定键按钮
    act = new QPushButton(this);
    act -> setText("Determine");
    act -> setParent(this);
    act -> resize(200, 60);
    act -> move(150, 500);
    connect(act, &QPushButton::clicked, this, &GetMoney::Act);

    //数据清零
    clearing = new QPushButton(this);
    clearing -> setText("Clearing");
    clearing -> setParent(this);
    clearing -> resize(200,60);
    clearing -> move(450,500);
    connect(clearing, &QPushButton::clicked, this, &GetMoney::clean);

    //取款提示信息
    inputLabelDrawal = new QLabel(this);
    inputLabelDrawal -> setText("Withdrawal amount:");
    inputLabelDrawal -> setAlignment(Qt::AlignCenter);
    inputLabelDrawal -> resize(300,100);
    inputLabelDrawal -> move(380,130);

        //选择金额
    inputOne = new QPushButton(this);
    inputOne -> setText("100");
    inputOne -> setParent(this);
    inputOne -> resize(200,60);
    inputOne -> move(150,200);
    connect(inputOne, &QPushButton::clicked, this, &GetMoney::get100);

    inputTwo = new QPushButton(this);
    inputTwo -> setText("300");
    inputTwo -> setParent(this);
    inputTwo -> resize(200,60);
    inputTwo -> move(150,300);
    connect(inputTwo, &QPushButton::clicked, this, &GetMoney::get300);

    inputThree = new QPushButton(this);
    inputThree -> setText("500");
    inputThree -> setParent(this);
    inputThree -> resize(200,60);
    inputThree -> move(150,400);
    connect(inputThree, &QPushButton::clicked, this, &GetMoney::get500);
    inputFour = new QPushButton(this);
    inputFour -> setText("1000");
    inputFour -> setParent(this);
    inputFour -> resize(200,60);
    inputFour -> move(750,200);
    connect(inputFour, &QPushButton::clicked, this, &GetMoney::get1000);

    inputFive = new QPushButton(this);
    inputFive -> setText("2000");
    inputFive -> setParent(this);
    inputFive -> resize(200,60);
    inputFive -> move(750,300);
    connect(inputFive, &QPushButton::clicked, this, &GetMoney::get2000);

    inputSix = new QPushButton(this);
    inputSix -> setText("3000");
    inputSix -> setParent(this);
    inputSix -> resize(200,60);
    inputSix -> move(750,400);
    connect(inputSix, &QPushButton::clicked, this, &GetMoney::get3000);

}

GetMoney::~GetMoney()
{
    delete ui;
}

void GetMoney::Act()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString time = currentTime.toString("yyyy/MM/dd");

    char *s=(char *)malloc(10);
    QByteArray ba=time.toLatin1();
    strcpy(s,ba.data());

    if (user -> withdrawalMoney(get_money, s)) {
        QMessageBox::information(NULL, "Tips", "Successful withdrawal!");
        clean();
    }
    else QMessageBox::information(NULL, "Tips", "Insufficient deposit!");

}

void GetMoney::Exsit()
{
    close();
}
void GetMoney::clean()
{
    get_money = 0;
    count();
}
void GetMoney::count()
{
    s_get = "";
    int ls = get_money;
    int i = 100;
    while (get_money / i) i *= 10;
    i /= 10;
    while (i) {
        s_get += (ls / i) + '0';
        ls %= i;
        i /= 10;
    }
    browser -> setText(s_get);
}

void GetMoney::get100()
{
    get_money += 100;
    count();
}
void GetMoney::get300()
{
    get_money += 300;
    count();
}
void GetMoney::get500()
{
    get_money += 500;
    count();
}
void GetMoney::get1000()
{
    get_money += 1000;
    count();
}
void GetMoney::get2000()
{
    get_money += 2000;
    count();
}
void GetMoney::get3000()
{
    get_money += 3000;
    count();
}

