#include "set.h"
#include "ui_set.h"

set::set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set)
{
    ui->setupUi(this);
}

set::~set()
{
    delete ui;
}

void set::on_pushButton_clicked()
{
    this->hide();
    parentWidget()->show(); //显示父窗体
}
