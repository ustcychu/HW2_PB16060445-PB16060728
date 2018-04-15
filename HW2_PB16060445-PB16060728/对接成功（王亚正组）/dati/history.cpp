#include "history.h"
#include "ui_history.h"
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>
#include<QString>

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}
QFile hh("history.txt");
QFile sco("score.txt");
void History::on_pushButton_2_clicked()
{
    if(!hh.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<hh.errorString();

    QTextStream in(&hh);
    QString ss="";
    QString inf;
    QString line_5;
     QString line_6;

    while(!in.atEnd()){
        QString line=in.readLine();
        ss=ss+line+"\n";

       }
    ui->textEdit->setText(ss);
    if(!sco.open(QIODevice::ReadOnly |QIODevice::Text))
     qDebug()<<sco.errorString();
    QTextStream in_5(&sco);
         line_5=in_5.readLine();
         line_6=in_5.readLine();
     inf = QString("正确率：%1/%2").arg(line_5).arg(line_6);
    ui->score->setText(inf);
    ui->pushButton_2->setEnabled(false);


}

void History::on_pushButton_clicked()
{
    (&hh)->close();
    (&sco)->close();
    this->hide();
    parentWidget()->show(); //显示父窗体
}
