#ifndef RESULTWIN_H
#define RESULTWIN_H

#include <QDialog>

namespace Ui {
class ResultWin;
}

class ResultWin : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWin(QWidget *parent = 0);
    ~ResultWin();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::ResultWin *ui;
};

#endif // RESULTWIN_H
