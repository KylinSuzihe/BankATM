#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QAction>
#include <QMenuBar>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QByteArray>
#include <QDialog>
#include <QWidget>
#include <QFont>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <QApplication>

#include "Graph.h"
#include "trie.h"
#include "user.h"
//#include "transfer.h"
#include "register.h"
#include "select.h"
#include "admin.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton *logIn;
    QPushButton *exi;
    QPushButton *reg;
    QPushButton *adm;

    QLineEdit *inputName;
    QLineEdit *inputPassword;
    QLabel *inputLabelName;
    QLabel *inputLabelPassword;

    QLabel *showName;
    QLabel *showPassword;

    class select *sel;
    class Register *re;
    class Admin *admin;

    void userLogIn();
    void exist();
    void regist();
    void adminLogIn();

};

#endif // MAINWINDOW_H
