#include "sucesswin.h"
#include "ui_SucessWin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

SucessWin::SucessWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SucessWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetLoan(IID));
    ui->ShowLoan->setText(s1);
}

SucessWin::~SucessWin()
{
    delete ui;
}

void SucessWin::on_ExitButton_clicked()
{
    this->hide();
}
