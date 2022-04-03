#ifndef SELECT_H
#define SELECT_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QApplication>
#include "transfer.h"
#include "deposit.h"
#include "getmoney.h"
#include "check.h"
#include "dwrui.h"
#include "tfrui.h"
namespace Ui {
class select;
}

class select : public QDialog
{
    Q_OBJECT

public:
    explicit select(QWidget *parent = nullptr);
    ~select();

private:
    Ui::select *ui;
    QPushButton *saveMoney;
    QPushButton *getMoney;
    QPushButton *check;
    QPushButton *turn;
    QPushButton *exist;
    QPushButton *cance;
    QPushButton *dwr;
    QPushButton *tfr;

    class Deposit *sm;
    class GetMoney *gm;
    class Check *ch;
    class Transfer * tur;
    class DWRUI *dwrui;
    class TFRUI *tfrui;

    void toDeposit();
    void toGetMoney();
    void toCheck();
    void toTurn();
    void toExist();
    void toCancellation();
    void toDwrUi();
    void toTfrUi();
};

#endif // SELECT_H
