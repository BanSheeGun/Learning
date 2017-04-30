#ifndef PAYLOANWIN_H
#define PAYLOANWIN_H

#include <QDialog>

namespace Ui {
class PayLoanWin;
}

class PayLoanWin : public QDialog
{
    Q_OBJECT

public:
    explicit PayLoanWin(QWidget *parent = 0);
    ~PayLoanWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::PayLoanWin *ui;
};

#endif // PAYLOANWIN_H
