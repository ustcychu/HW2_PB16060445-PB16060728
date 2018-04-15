#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <widget.h>
#include <setting.h>


namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Welcome *ui;
    Widget *widget=new Widget;
};

#endif // WELCOME_H
