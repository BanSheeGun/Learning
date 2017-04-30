#ifndef LOANWIN_H
#define LOANWIN_H

#include <QDialog>

namespace Ui {
class LoanWin;
}

class LoanWin : public QDialog
{
    Q_OBJECT

public:
    explicit LoanWin(QWidget *parent = 0);
    ~LoanWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::LoanWin *ui;
};

#endif // LOANWIN_H
