#ifndef GETMONEY_H
#define GETMONEY_H

#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QByteArray>
#include <QDialog>
#include <QWidget>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <QDateTime>
namespace Ui {
class GetMoney;
}

class GetMoney : public QDialog
{
    Q_OBJECT

public:
    explicit GetMoney(QWidget *parent = 0);
    ~GetMoney();

private:
    Ui::GetMoney *ui;
    QPushButton *back;//返回键按钮
    QPushButton *act;
    QLabel *inputLabelDrawal;//输入存款数额
    QLabel *browser;
    QPushButton *clearing;

    //存款金额
    QPushButton *inputOne;
    QPushButton *inputTwo;
    QPushButton *inputThree;
    QPushButton *inputFour;
    QPushButton *inputFive;
    QPushButton *inputSix;

    void get100();
    void get300();
    void get500();
    void get1000();
    void get2000();
    void get3000();
    void count();
    void clean();

    void Exsit();
    void Act();
};

#endif // GETMONEY_H
