#ifndef CREDITWIN_H
#define CREDITWIN_H

#include <QDialog>

namespace Ui {
class CreditWin;
}

class CreditWin : public QDialog
{
    Q_OBJECT

public:
    explicit CreditWin(QWidget *parent = 0);
    ~CreditWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::CreditWin *ui;
};

#endif // CREDITWIN_H
