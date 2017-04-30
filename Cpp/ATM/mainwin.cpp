#include "mainwin.h"
#include "ui_MainWin.h"
#include "visitwin.h"
#include "depositwin.h"
#include "withdrawwin.h"
#include "transferwin.h"
#include "loanwin.h"
#include "creditwin.h"
#include "loginwin.h"
#include "payloanwin.h"
#include "failwin.h"

extern int ID, IID;
extern Bank bank;

MainWin::MainWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_VisitButton_clicked()
{
    VisitWin *vis=new VisitWin(this);
    vis->show();
}

void MainWin::on_WithdrawButton_clicked()
{
    WithdrawWin *withdw=new WithdrawWin(this);
    withdw->show();
}

void MainWin::on_DepositButton_clicked()
{
    DepositWin *depw=new DepositWin(this);
    depw->show();
}

void MainWin::on_TransferButton_clicked()
{
    TransferWin *trefw=new TransferWin(this);
    trefw->show();
}

void MainWin::on_LoanButton_clicked()
{
    LoanWin *loanw=new LoanWin(this);
    loanw->show();
}

void MainWin::on_CreditButton_clicked()
{
    if (bank.IsCredit((IID))) {
        CreditWin *credw=new CreditWin(this);
        credw->show();
    } else {
        FailWin *fdw = new FailWin();
        fdw->show();
    }
}

void MainWin::on_ExitButton_clicked()
{
    ATM *atmw=new ATM();
    atmw->show();
    this->close();
}

void MainWin::on_pushButton_clicked()
{
    PayLoanWin *payw=new PayLoanWin(this);
    payw->show();
}
