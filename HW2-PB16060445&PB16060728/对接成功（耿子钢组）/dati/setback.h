#ifndef SETBACK_H
#define SETBACK_H

#include <QDialog>
#include <history.h>
#include <error.h>

namespace Ui {
class Setback;
}

class Setback : public QDialog
{
    Q_OBJECT

public:
    explicit Setback(QWidget *parent = 0);
    ~Setback();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Setback *ui;
};

#endif // SETBACK_H
