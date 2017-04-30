#ifndef SUCESSWIN2_H
#define SUCESSWIN2_H

#include <QDialog>

namespace Ui {
class SucessWin2;
}

class SucessWin2 : public QDialog
{
    Q_OBJECT

public:
    explicit SucessWin2(QWidget *parent = 0);
    ~SucessWin2();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::SucessWin2 *ui;
};

#endif // SUCESSWIN2_H
