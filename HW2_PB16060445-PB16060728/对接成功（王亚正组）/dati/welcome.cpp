#include "welcome.h"
#include "ui_welcome.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QTextCodec>
#include <QLibrary>
#include "Core_x86.h"

using namespace std;

typedef int(*Fun)(int, int, Parameter);
typedef int(*Fun1)(int);

QLibrary mylib("Core_x86.dll");

extern int ques_num, oper_max, oper_num, oper_kind, flag_1;
extern bool ad, su, mu, di, po, frac, doub;

QFile xt("produce_q.txt"),xa("produce_a.txt");

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    bool ok;
    this->hide();
    Setting *setting= new Setting(this);
    setting->show();
}

void Welcome::on_pushButton_2_clicked()
{
    if(flag_1 == 0) {ad=1; su=1; mu=1; di=1; po=0;}
    int m=1;  //qDebug()<<oper_kind<<ad<<su<<mu<<di<<po;
    std::string strq="ques",stra="ans";
    if(!xt.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xt.errorString();
    if(!xa.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xa.errorString();

    if(mylib.load())
    {
        int error, error1;
        Fun Setting_Parameter=(Fun)mylib.resolve("?Setting_Parameter@@YAHHHUParameter@@@Z");
        Fun1 Generate=(Fun1)mylib.resolve("?Generate@@YAHH@Z");

        Parameter argu;    //Parameter结构体类型

        argu.integer = 0;
        argu.fraction = 0;
        argu.decimal = 0;
        if(oper_kind==0) argu.integer = 1;
        else if(oper_kind==2) { argu.integer = 1; argu.fraction = 1; }
        else argu.decimal = 1;
        argu.add = ad;      //支持加法
        argu.sub = su;      //支持减法
        argu.multiply = mu; //支持乘法
        argu.division = di; //支持除法
        argu.pow = po;      //不支持乘方
        argu.bracktet = 1; //支持括号
        error=Setting_Parameter(ques_num, oper_max, argu);//error接受Setting_Parameter函数的返回值
        error1=Generate(error);    //将error传入Generate函数，并用error1接受该函数返回值
    }

    (&xt)->close();
    (&xa)->close();
    this->hide();
    widget->show();
}




