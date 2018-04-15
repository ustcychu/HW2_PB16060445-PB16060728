#include "error.h"
#include "ui_error.h"
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>
#include<QString>

Error::Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
}

Error::~Error()
{
    delete ui;
}

QFile ww("error.txt");

void Error::on_pushButton_2_clicked()
{

    if(!ww.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<ww.errorString();

QTextStream in(&ww);
    QString ss="";
    while(!in.atEnd()){
        QString line=in.readLine();
        ss=ss+line+"\n";

       }
    ui->textEdit->setText(ss);
    ui->pushButton_2->setEnabled(false);

}

void Error::on_pushButton_clicked()
{
    (&ww)->close();
    this->hide();
    parentWidget()->show(); //显示父窗体
}
