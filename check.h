#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include <QPushButton>
#include <QMainWindow>
#include <QPaintEvent>
#include <QWidget>
#include <QtWidgets>
namespace Ui {
class Check;
}

class Check : public QDialog
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = 0);
    ~Check();

private:
    Ui::Check *ui;
    QPushButton *browser;
    QPushButton *Back;
    QLineEdit *inputBalance;
    QLabel *inputLabelBalance;
    void toExist();
};

#endif // CHECK_H
