#include "resswin.h"
#include "ui_ResSWin.h"
#include "loginwin.h"
#include "reswin.h"

extern int ID, IID;
extern Bank bank;

ResSWin::ResSWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResSWin)
{
    ui->setupUi(this);
    QString tmp = QString::number(ID, 10);
    ui->ShowID->setText(tmp);
    ui->ShowID->show();
}

ResSWin::~ResSWin()
{
    delete ui;
}

void ResSWin::on_ReturnButton_clicked()
{
    this->close();
}
