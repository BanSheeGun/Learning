#ifndef VISITWIN_H
#define VISITWIN_H

#include <QDialog>

namespace Ui {
class VisitWin;
}

class VisitWin : public QDialog
{
    Q_OBJECT

public:
    explicit VisitWin(QWidget *parent = 0);
    ~VisitWin();

private slots:
    void on_ExitButton_clicked();

private:
    Ui::VisitWin *ui;
};

#endif // VISITWIN_H
