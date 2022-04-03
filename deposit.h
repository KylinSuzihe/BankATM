#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <QLabel>
#include <QAction>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QByteArray>
#include <QDateTime>
namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = 0);
    ~Deposit();

private:
    Ui::Deposit *ui;

    QPushButton *back;//返回键按钮
    QPushButton *act;
    QLabel *inputLabelDeposit;//输入存款数额
    QLabel *browser;
    QPushButton *clearing;

    //存款金额
    QPushButton *inputOne;
    QPushButton *inputTwo;
    QPushButton *inputThree;
    QPushButton *inputFour;
    QPushButton *inputFive;
    QPushButton *inputSix;

    void save100();
    void save300();
    void save500();
    void save1000();
    void save2000();
    void save3000();
    void count();
    void clean();

    void Exsit();
    void Act();
};

#endif // DEPOSIT_H
