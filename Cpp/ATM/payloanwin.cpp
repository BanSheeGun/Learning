#include "payloanwin.h"
#include "ui_PayLoanWin.h"
#include "sucesswin.h"
#include "failwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

PayLoanWin::PayLoanWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayLoanWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetLoan(IID));
    ui->ShowLoan->setText(s1);
}

PayLoanWin::~PayLoanWin()
{
    delete ui;
}

void PayLoanWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    if (bank.PayLoan(IID, money)) {
        SucessWin *sucw=new SucessWin(this);
        sucw->show();
        this->hide();
    } else {
        FailWin * fdw = new FailWin(this);
        fdw->show();
        this->hide();
    }
}

void PayLoanWin::on_ExitButton_clicked()
{
    this->close();
}
