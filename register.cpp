#include "register.h"
#include "ui_register.h"

extern User* user;
extern User* users[10000];
extern int userNum;
extern Trie* idTree[100005];

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password); //输入密码时显示圆点
    ui->confirm->setEchoMode(QLineEdit::Password);

    // 获取当前时间，截取部分作为账户id
    QDateTime current_time = QDateTime::currentDateTime();
    QString currentTime = current_time.toString("yyyyMMddhhmmss");
    QString userID = currentTime.mid(6);  // 从下标[6]开始截取子串

    ui->userId->setText(userID);  //将userID显示在Text Browser中
}

Register::~Register()
{
    delete ui;
}
void Register::on_regist_clicked()
{
    QString pw = ui->password->text();  // 密码(PassWord)
    QString pwc = ui->confirm->text();  // 确认密码(PassWordConfirm)

    if(pw != pwc || pw == "") // 两次输入的密码不同 或 未输入密码
    {
        QMessageBox::critical(NULL, "Error","The password entered twice is not the same!");
        ui->confirm->clear();  // 清空确认密码输入框
    }
    else //两次输入的密码一样
    {
        QString userID = ui->userId->text();
        int pos = ++userNum;         // = User::getEmpty();
        idTree[0]->Insert(userID, pos);  // 将账户id存入字典树tric中
        users[userNum] = new User(userID.toStdString(), pw.toStdString());
        QMessageBox::information(NULL, "Tips", "Register successful!");
        close();
    }
}

void Register::on_cancel_clicked()
{
    close();
}
