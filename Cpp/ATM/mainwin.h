#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>

namespace Ui {
class MainWin;
}

class MainWin : public QDialog
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private slots:
    void on_VisitButton_clicked();

    void on_WithdrawButton_clicked();

    void on_DepositButton_clicked();

    void on_TransferButton_clicked();

    void on_LoanButton_clicked();

    void on_CreditButton_clicked();

    void on_ExitButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWin *ui;
};

#endif // MAINWIN_H
