#include "visitwin.h"
#include "ui_VisitWin.h"
#include "mainwin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

VisitWin::VisitWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitWin)
{
    ui->setupUi(this);
    QString s1, s2, s3, s4;
    s1 = QString::number(ID, 10);
    s2 = QString::fromStdString(bank.GetName(IID));
    s3 = QString::number(bank.GetBalance(IID));
    s4 = QString::number(bank.GetLoan(IID));
    ui->ShowID->setText(s1);
    ui->ShowBalance->setText(s3);
    ui->ShowLoan->setText(s4);
    ui->ShowName->setText(s2);
}

VisitWin::~VisitWin()
{
    delete ui;
}

void VisitWin::on_ExitButton_clicked()
{
    this->close();
}
