#ifndef ERROR_H
#define ERROR_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Error;
}

class Error : public QDialog
{
    Q_OBJECT

public:
    explicit Error(QWidget *parent = 0);
    ~Error();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Error *ui;
};

#endif // ERROR_H
