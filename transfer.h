#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"


namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = 0);
    ~Transfer();
    void Confirm();

private:
    Ui::Transfer *ui;
    QPushButton* cancel;  // 取消按钮
    QPushButton* ok;  // 确认按钮
    QLineEdit* inputAccount;  // 接收方账户输入框
    QLineEdit* inputAmount;  // 转账金额输入框
    QLabel* labelAccount;  // 账户输入提示标签
    QLabel* labelAmount;  // 金额输入提示标签
};

#endif // TRANSFER_H
