#include "sucesswin2.h"
#include "ui_SucessWin2.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

SucessWin2::SucessWin2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SucessWin2)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetCredit(IID));
    ui->ShowCredit->setText(s1);
}

SucessWin2::~SucessWin2()
{
    delete ui;
}

void SucessWin2::on_ExitButton_clicked()
{
    this->hide();
}
