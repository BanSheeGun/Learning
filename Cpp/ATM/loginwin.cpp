#include "loginwin.h"
#include "mainwin.h"
#include "resswin.h"
#include "reswin.h"
#include "ui_LoginWin.h"

#ifndef AABBCCD
#define AABBCCD

ATM::ATM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ATM)
{
    ui->setupUi(this);
}

ATM::~ATM()
{
    delete ui;
}

void ATM::on_ResButton_clicked()
{
    ResWin *resw=new ResWin(this);
    resw->show();
}


void ATM::on_LoginButton_clicked()
{
    MainWin *mainw=new MainWin();
    QString Name1, Password1;
    string Name2, Password2;
    Name1 = ui->Name->text();
    Password1 = ui->Password->text();
    Name2 = Name1.toStdString();
    Password2 = Password1.toStdString();
    IID = bank.Login(Name2, Password2);
    if (IID == 0) return;
    ID = IID + 10000;
    mainw->show();
    this->hide();
}

#endif
