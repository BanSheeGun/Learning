#include "loginwin.h"
#include <QApplication>

int ID, IID;
Bank bank;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ATM w;
    w.show();
    return a.exec();
}
