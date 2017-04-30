#include "failwin.h"
#include "ui_FailWin.h"
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

FailWin::FailWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FailWin)
{
    ui->setupUi(this);
}

FailWin::~FailWin()
{
    delete ui;
}

void FailWin::on_ExitButton_clicked()
{
    this->hide();
}
