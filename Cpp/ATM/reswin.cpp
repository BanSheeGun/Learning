#include "reswin.h"
#include "ui_ResWin.h"
#include "resswin.h"
#include "loginwin.h"
#include <string>
#include <QString>
#include "loginwin.h"
extern int ID, IID;
extern Bank bank;

extern int ID, IID;
extern Bank bank;

ResWin::ResWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResWin)
{
    ui->setupUi(this);
    ui->TipMS->hide();
}

ResWin::~ResWin()
{
    delete ui;
}

void ResWin::on_pushButton_clicked()
{
    int AccountType=ui->comboBox->currentIndex();//获取下拉列表的下标
    QString password=ui->Password->text(); //获取文本内容
    QString rpassword=ui->Repassword->text();
    QString name=ui->Name->text();
    QString personId=ui->PersonID->text();
    QString email=ui->Email->text();
    if(password!=rpassword){
        ui->TipMS->setText("两次密码输入不一致");
        ui->TipMS->show();
        return ;
    }
    string name1 = name.toStdString();
    string password1 = password.toStdString();
    string perid = personId.toStdString();
    string email1 = email.toStdString();
    IID = bank.Res(AccountType, name1, password1, perid, email1);
    ID = IID + 10000;
    ResSWin *ressw=new ResSWin();
    ressw->show();
    this->close();
}

void ResWin::on_pushButton_2_clicked()
{
    this->close();
}
