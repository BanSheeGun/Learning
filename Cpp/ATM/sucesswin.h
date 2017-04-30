#ifndef SUCESSWIN_H
#define SUCESSWIN_H

#include <QDialog>

namespace Ui {
class SucessWin;
}

class SucessWin : public QDialog
{
    Q_OBJECT

public:
    explicit SucessWin(QWidget *parent = 0);
    ~SucessWin();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::SucessWin *ui;
};

#endif // SUCESSWIN_H
