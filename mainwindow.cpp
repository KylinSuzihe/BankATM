#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "dwrui.h"

User* user;
User* users[10000];
int userNum = 0;//user
Trie* idTree[100005];  // 账户汇总
int cnt = 0;//trie
int loginNum = 0;
Graph* tfRecord;

// MainWindow构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("ATM"));//设置窗口标题
    this->resize(1375,760);//设置窗口大小


//登录按钮
    logIn = new QPushButton(this);//新建
    logIn -> setText("LonIn");      //设置文字信息
    logIn -> setParent(this);     //设置指针
    logIn -> resize(200, 60);     //修改大小
    logIn -> move(540, 500);      //框框左上角的坐标
    connect(logIn, &QPushButton::clicked, this, &MainWindow::userLogIn);

    exi = new QPushButton(this);//新建
    exi -> setText("Exist");      //设置文字信息
    exi -> setParent(this);     //设置指针
    exi -> resize(200, 60);     //修改大小
    exi -> move(840, 500);      //框框左上角的坐标
    connect(exi, &QPushButton::clicked, this, &MainWindow::exist);
//姓名输入框
    inputName = new QLineEdit(this);
    inputName -> setParent(this);
    inputName -> resize(350, 50);
    inputName -> move(500, 120);
    connect(inputName, &QLineEdit::returnPressed, this, &MainWindow::userLogIn);

//密码输入框
    inputPassword = new QLineEdit(this);
    inputPassword -> setEchoMode(QLineEdit::Password);
    inputPassword -> setParent(this);
    inputPassword -> resize(350, 50);
    inputPassword -> move(500, 320);
    connect(inputPassword, &QLineEdit::returnPressed, this, &MainWindow::userLogIn);

//登录提示信息
    inputLabelName = new QLabel(this);
    inputLabelName -> setText("User name:");
    inputLabelName -> setAlignment(Qt::AlignCenter);//对齐方式
    inputLabelName -> resize(300, 100);
    inputLabelName -> move(275, 100);

    inputLabelPassword = new QLabel(this);
    inputLabelPassword -> setText("Password:");
    inputLabelPassword -> setAlignment(Qt::AlignCenter);
    inputLabelPassword -> resize(300, 100);
    inputLabelPassword -> move(275, 300);

//注册
    reg = new QPushButton;
    reg -> setParent(this);
    reg -> setText("register");
    reg -> resize(200, 60);
    reg -> move(240, 500);
    connect(reg, &QPushButton::clicked, this, &MainWindow::regist);

    statusBar();//设置好StatusTip

    adm = new QPushButton(this);//新建
    adm -> setText("Admin");      //设置文字信息
    adm -> setParent(this);     //设置指针
    adm -> resize(200, 60);     //修改大小
    adm -> move(540, 600);      //框框左上角的坐标
    connect(adm, &QPushButton::clicked, this, &MainWindow::adminLogIn);

    idTree[0] = new Trie();
    tfRecord = new Graph();

    users[1] = new User("11111111", "1");
    users[2] = new User("22222222", "2");
    userNum += 2;
    idTree[0]->Insert("11111111", 1);
    idTree[0]->Insert("22222222", 2);
    int re1 = idTree[0]->Find("11111111");
    if(re1 != -1) {
        //QMessageBox::information(NULL, "Tips", "Find 11111111!");
        users[1]->setMoney(11111);
    }
    int re2 = idTree[0]->Find("22222222");
    if(re2 != -1) {
        //QMessageBox::information(NULL, "Tips", "Find 22222222!");
        users[2]->setMoney(22222);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exist()
{
    close();
}

void MainWindow::userLogIn()
{
    QString name = inputName->text();
    string pw = (inputPassword->text()).toStdString();

    for(int i = 0; i < name.size(); i++) {
        if(name[i] < '0' || name[i] > '9') {
            QMessageBox::critical(NULL, "Error", "Please enter the correct account!");
            return;
        }
    }

    int pos = idTree[0]->Find(name);
    user = users[pos];
    if(pos < 0)
        QMessageBox::information(NULL, "Error", "The account could not be found!");
    else {
        if(pw == user->getPassword()) { // 密码正确
            QMessageBox::information(NULL, "Tips", "Login Successfully!");
            loginNum = 0;
            user = users[pos];
            sel = new class select;
            sel -> exec();
            inputName -> clear();
            inputPassword -> clear();
        } else {
            QMessageBox::information(NULL, "Error", "PassWord Error!");
            if(++loginNum == 3) close();
        }
    }

}

void MainWindow::regist() {
    re = new Register;
    re -> exec();
}
void MainWindow::adminLogIn() {
    admin = new Admin();
    admin -> exec();
}
