#include "setback.h"
#include "ui_setback.h"
#include <QDebug>

Setback::Setback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setback)
{
    ui->setupUi(this);
}

Setback::~Setback()
{
    delete ui;
}

void Setback::on_pushButton_clicked()
{
    this->hide();
    History *history= new History(this);
    history->show();
}

void Setback::on_pushButton_2_clicked()
{
    this->hide();
    Error *error= new Error(this);
    error->show();
}

void Setback::on_pushButton_4_clicked()
{
    this->close();
}
