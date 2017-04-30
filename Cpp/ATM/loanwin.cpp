#include "loanwin.h"
#include "ui_LoanWin.h"
#include "sucesswin.h"
#include <QMainWindow>
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

LoanWin::LoanWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoanWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetLoan(IID));
    ui->ShowLoan->setText(s1);
}

LoanWin::~LoanWin()
{
    delete ui;
}

void LoanWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    bank.RequestLoan(IID, money);
    SucessWin *sucw=new SucessWin(this);
    sucw->show();
    this->hide();
}

void LoanWin::on_ExitButton_clicked()
{
    this->close();
}
