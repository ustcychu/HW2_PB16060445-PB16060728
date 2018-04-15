#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
