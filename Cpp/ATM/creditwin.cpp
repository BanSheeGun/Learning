#include "creditwin.h"
#include "ui_CreditWin.h"
#include "sucesswin2.h"
#include "failwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

CreditWin::CreditWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditWin)
{
    ui->setupUi(this);
    QString s1 = QString::number(bank.GetCredit(IID));
    ui->ShowCredit->setText(s1);
}

CreditWin::~CreditWin()
{
    delete ui;
}

void CreditWin::on_YesButton_clicked()
{
    double money = ui->GetNum->text().toDouble();
    bank.SetCredit(IID, money);
    SucessWin2 *sucw2=new SucessWin2(this);
    sucw2->show();
    this->hide();
}

void CreditWin::on_ExitButton_clicked()
{
    this->close();
}
