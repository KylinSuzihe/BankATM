#include "transfer.h"
#include "ui_transfer.h"

extern User* user;
extern User* users[10000];
extern Trie* idTree;
extern Graph* tfRecord;

Transfer::Transfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Transfer accounts"));  // 设置窗口标题
    this->resize(1375,760);  // 设置窗口大小

    inputAccount = new QLineEdit(this);
    inputAccount->setParent(this);
    inputAccount->resize(525,50);
    inputAccount->move(525,235);
    connect(inputAccount, &QLineEdit::returnPressed, this, Confirm);

    inputAmount = new QLineEdit(this);
    inputAmount->setParent(this);
    inputAmount->resize(525,50);
    inputAmount->move(525,360);
    connect(inputAmount, &QLineEdit::returnPressed, this, Confirm);

    labelAccount = new QLabel(this);
    labelAccount->setText("Transfer to Account");
    labelAccount->setAlignment(Qt::AlignCenter);
    labelAccount->resize(450,150);
    labelAccount->move(200,187);

    labelAmount = new QLabel(this);
    labelAmount->setText("Transfer Amount");
    labelAmount->setAlignment(Qt::AlignCenter);
    labelAmount->resize(450,150);
    labelAmount->move(200,312);

    ok = new QPushButton(this);
    ok->setText("OK");
    ok->setParent(this);
    ok->resize(100,50);
    ok->move(600,500);
    connect(ok, &QPushButton::clicked, this, Confirm);

    cancel = new QPushButton(this);
    cancel->setText("Cancel");
    cancel->setParent(this);
    cancel->resize(100,50);
    cancel->move(900,500);
    connect(cancel, &QPushButton::clicked, this, close);
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::Confirm()
{
    QString account = inputAccount -> displayText().toLatin1();
    QString amount = inputAmount -> displayText().toLatin1();
    string str = amount.toStdString();

    //检查输入账户中的违法字符
    for(int i = 0; i < account.size(); i++) {
        if(account[i] < '0' || account[i] > '9') {
            QMessageBox::critical(NULL, "Error", "转账用户输入了特殊字符 Please enter the correct account!");
            return;
        }
    }
    int recPos = idTree->Find(account);  // 接受者的数组下标
    if(recPos == -1) {  // 检查转账接受方的合法性
        QMessageBox::critical(NULL, "Error", "查无此人 Please enter the correct user name!");
        return;
    }
    if(users[recPos] == user) {
        QMessageBox::critical(NULL, "Error", "不能转账给自己 You can't transfer money to yourself!");
        return;
    }

    // 检查转账金额的合法性
    int m = 0;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] < '0' || str[i] > '9') {
            QMessageBox::critical(NULL, "Error", "转账金额输入了特殊字符 Please enter the correct amount!");
            inputAmount->clear();
            return;
        }
        m = m * 10 + str[i] - '0';
    }
    if (m <= 0) {
        QMessageBox::critical(NULL, "Error", "转账金额不正确");
        return;
    }
    if (user->getMoney() < m) {
        QMessageBox::critical(NULL, "Error", "余额不足");
        return;
    }

    // 转账
    user->setMoney(user->getMoney()-m);
    users[recPos]->setMoney(users[recPos]->getMoney()+m);

    // 添加转账记录
    QDateTime current_time = QDateTime::currentDateTime();
    QString currentTime = current_time.toString("yyyy/MM/dd");
    string time = currentTime.toStdString();
    bool re = tfRecord->AddRecord(users[recPos]->getId(), m, time);
    if(re) QMessageBox::information(NULL, "Tips", "转账成功!");

}
