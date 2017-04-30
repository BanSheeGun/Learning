#include "transferwin.h"
#include "ui_TransferWin.h"
#include "failwin.h"
#include "resultwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

TransferWin::TransferWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetBalance(IID));
    ui->ShowBalance->setText(s1);
}

TransferWin::~TransferWin()
{
    delete ui;
}

void TransferWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    int IID2 = ui->GetID->text().toInt() - 10000;
    if(bank.Transfer(IID, IID2, money)){
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

void TransferWin::on_ExitButton_clicked()
{
    this->close();
}
