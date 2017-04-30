#ifndef DEPOSITWIN_H
#define DEPOSITWIN_H

#include <QDialog>

namespace Ui {
class DepositWin;
}

class DepositWin : public QDialog
{
    Q_OBJECT

public:
    explicit DepositWin(QWidget *parent = 0);
    ~DepositWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::DepositWin *ui;
};

#endif // DEPOSITWIN_H
