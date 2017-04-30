#include "depositwin.h"
#include "ui_DepositWin.h"
#include "failwin.h"
#include "resultwin.h"
#include "mainwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

DepositWin::DepositWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetBalance(IID));
    ui->ShowBalance->setText(s1);
}

DepositWin::~DepositWin()
{
    delete ui;
}

void DepositWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    bank.Deposit(IID, money);
    ResultWin *resw=new ResultWin(this);
    resw->show();
    this->hide();
}

void DepositWin::on_ExitButton_clicked()
{
    this->close();
}
