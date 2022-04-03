#ifndef TFRUI_H
#define TFRUI_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class TFRUI;
}

class TFRUI : public QDialog
{
    Q_OBJECT

public:
    explicit TFRUI(QWidget *parent = 0);
    ~TFRUI();

private slots:
    void on_pushButton_clicked();
    
    void on_exist_clicked();
    
private:
    Ui::TFRUI *ui;
    QTableWidget* table;
};

#endif // TFRUI_H
