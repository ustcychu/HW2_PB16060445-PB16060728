#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QFile>

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = 0);
    ~History();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::History *ui;
};

#endif // HISTORY_H
