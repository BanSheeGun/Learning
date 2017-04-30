#ifndef RESSWIN_H
#define RESSWIN_H

#include <QDialog>

namespace Ui {
class ResSWin;
}

class ResSWin : public QDialog
{
    Q_OBJECT

public:
    explicit ResSWin(QWidget *parent = 0);
    ~ResSWin();

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::ResSWin *ui;
};

#endif // RESSWIN_H
