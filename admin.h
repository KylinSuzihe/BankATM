#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "qsort.h"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:
    void on_search_clicked();

    void on_exist_clicked();

private:

    Ui::Admin *ui;
    QTableWidget* table;
};

#endif // ADMIN_H
