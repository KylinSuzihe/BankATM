#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <iostream>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
//    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

//    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

//    void on_pushButton_clicked();

    void on_regist_clicked();

    void on_cancel_clicked();

private:
    Ui::Register *ui;    
};

#endif // REGISTER_H
