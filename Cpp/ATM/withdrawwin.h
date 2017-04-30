#ifndef WITHDRAWWIN_H
#define WITHDRAWWIN_H

#include <QDialog>

namespace Ui {
class WithdrawWin;
}

class WithdrawWin : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawWin(QWidget *parent = 0);
    ~WithdrawWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::WithdrawWin *ui;
};

#endif // WITHDRAWWIN_H
