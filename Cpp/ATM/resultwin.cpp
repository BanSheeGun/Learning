#include "resultwin.h"
#include "loginwin.h"
#include "ui_ResultWin.h"

extern int ID, IID;
extern Bank bank;

ResultWin::ResultWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetBalance(IID));
    ui->ShowBalance->setText(s1);
}

ResultWin::~ResultWin()
{
    delete ui;
}

void ResultWin::on_ExitButton_clicked()
{
    this->hide();
}
