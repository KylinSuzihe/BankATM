#include "check.h"
#include "ui_check.h"
#include "user.h"
extern User *user;
Check::Check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("Query account balance"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小

    //提示信息
    inputLabelBalance = new QLabel(this);
    inputLabelBalance -> setText("The account balance is:");
    inputLabelBalance -> setAlignment(Qt::AlignCenter);
    inputLabelBalance -> resize(250, 100);
    inputLabelBalance -> move(315, 290);

    // 添加TextBrowser输出框
    browser = new QPushButton;
    browser->setParent(this);
    browser->setGeometry(530,300,400,80);
    //tGeometry(左右，上下，长，宽)

    Back = new QPushButton(this);
    Back -> setText("return");
    Back -> setParent(this);
    Back -> resize(150,40);
    Back -> move(650,450);
    connect(Back, &QPushButton::clicked, this, &Check::toExist);

    QString s = "";
    int ls = user -> getMoney();
    int i = 100;
    while (ls / i) i *= 10;
    i /= 10;
    while (i) {
        s += (ls / i) + '0';
        ls %= i;
        i /= 10;
    }
    browser -> setText(s);


}

Check::~Check()
{
    delete ui;
}

void Check::toExist()
{
    close();
}
