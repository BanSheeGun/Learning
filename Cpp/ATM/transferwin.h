#ifndef TRANSFERWIN_H
#define TRANSFERWIN_H

#include <QDialog>

namespace Ui {
class TransferWin;
}

class TransferWin : public QDialog
{
    Q_OBJECT

public:
    explicit TransferWin(QWidget *parent = 0);
    ~TransferWin();

private slots:
    void on_YesButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::TransferWin *ui;
};

#endif // TRANSFERWIN_H
