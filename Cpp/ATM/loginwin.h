#ifndef ATM_H
#define ATM_H

#include<QMainWindow>
#include <QDialog>
#include "Bank.cpp"
namespace Ui {
class ATM;
}

class ATM : public QMainWindow
{
    Q_OBJECT

public:
    explicit ATM(QWidget *parent = 0);
    ~ATM();

private slots:
    void on_ResButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::ATM *ui;
};


extern int ID, IID;
extern Bank bank;
#endif // ATM_H
