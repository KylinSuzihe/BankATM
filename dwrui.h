#ifndef DWRUI_H
#define DWRUI_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
namespace Ui {
class DWRUI;
}

class DWRUI : public QDialog
{
    Q_OBJECT

public:
    explicit DWRUI(QWidget *parent = 0);
    ~DWRUI();

private slots:
    void on_exist_clicked();

private:
    Ui::DWRUI *ui;
    QTableWidget* table;
};

#endif // DWRUI_H
