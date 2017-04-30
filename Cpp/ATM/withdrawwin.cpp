#include "withdrawwin.h"
#include "ui_WithdrawWin.h"
#include "failwin.h"
#include "resultwin.h"
#include "mainwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

WithdrawWin::WithdrawWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetBalance(IID));
    ui->ShowBalance->setText(s1);
}

WithdrawWin::~WithdrawWin()
{
    delete ui;
}

void WithdrawWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    if(bank.Withdraw(IID, money)){
        ResultWin *resw=new ResultWin(this);
        resw->show();
        this->hide();
    }
    else{
        FailWin *failw=new FailWin(this);
        failw->show();
        this->hide();
    }
}

void WithdrawWin::on_ExitButton_clicked()
{
    this->close();
}
