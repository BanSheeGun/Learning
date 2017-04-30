#ifndef RESWIN_H
#define RESWIN_H

#include <QDialog>

namespace Ui {
class ResWin;
}

class ResWin : public QDialog
{
    Q_OBJECT

public:
    explicit ResWin(QWidget *parent = 0);
    ~ResWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ResWin *ui;
};



#endif // RESWIN_H
