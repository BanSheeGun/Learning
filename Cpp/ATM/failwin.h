#ifndef FAILWIN_H
#define FAILWIN_H

#include <QDialog>

namespace Ui {
class FailWin;
}

class FailWin : public QDialog
{
    Q_OBJECT

public:
    explicit FailWin(QWidget *parent = 0);
    ~FailWin();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::FailWin *ui;
};

#endif // FAILWIN_H
