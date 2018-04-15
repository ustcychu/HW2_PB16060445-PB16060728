#include "setting.h"
#include "ui_setting.h"
#include <QButtonGroup>
#include <QDebug>

int ques_num=5, oper_max=100, oper_num=10, oper_kind=0, prec=2, flag_1=0;
bool ad=0, su=0, mu=0, di=0, po=0;

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_clicked()
{
    QButtonGroup *qbg = new QButtonGroup(this);
    qbg->addButton(ui->radioButton,0);
    qbg->addButton(ui->radioButton_1,1);
    qbg->addButton(ui->radioButton_2,2);
    int select=qbg->checkedId();

    ques_num= (ui->lineEdit->text()).toInt();
    oper_max= (ui->lineEdit_2->text()).toInt();
    oper_num= (ui->lineEdit_3->text()).toInt();
    prec= (ui->lineEdit_5->text()).toInt();

    switch(select)
    {
        case 0: oper_kind=0; break;
        case 1: oper_kind=2; break;
        case 2: oper_kind=1; break;
        default: oper_kind=2;
    }

    if( ques_num<1 || ques_num>1000 )  ques_num=5;
    if( oper_max<1 || oper_max>1000 )  oper_max=100;
    if( oper_num<1 || oper_num>50 )  oper_num=10;
    if( prec<1 || prec>10 )  prec=2;

    if(ui->checkBox->isChecked())
    {
        flag_1=1;
        ad=1;
    }
    if(ui->checkBox_2->isChecked())
    {
        flag_1=1;
        su=1;
    }
    if(ui->checkBox_3->isChecked())
    {
        flag_1=1;
        mu=1;
    }
    if(ui->checkBox_4->isChecked())
    {
        flag_1=1;
        di=1;
    }
    if(ui->checkBox_5->isChecked())
    {
        flag_1=1;
        po=1;
    }

    this->hide();
    parentWidget()->show(); //显示父窗体
}
