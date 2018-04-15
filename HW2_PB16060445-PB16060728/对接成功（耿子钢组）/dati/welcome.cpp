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
#include "package.h"

using namespace std;




QLibrary mylib("Project3.dll");

extern int ques_num, oper_max, oper_num, decimal,real, prec, flag_1;
extern bool ad, su, mu, di, po;

//QFile xt("suanshi.txt"),xa("result.txt");
//canshu values={ques_num,oper_max,oper_num,prec,real,decimal,po,ad,su,mu,di,1000};
//canshu values={100,10,5,4,1,1,1,1,1,1,1,1000};

/*values.num_ques = ques_num;
values.scalemax_op= oper_max;
values.num_op = oper_num;
values.num_float = prec;
values.is_add=ad;
values.is_sub=su;
values.is_mul=mu;
values.is_div=di;
values.is_power=po;
values.result_max=1000;
values.is_real=real;
values.is_decimal=decimal;*/
typedef void(*Fun)(canshu);

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
    if(flag_1 == 0)
    {
        ad=1;
        su=1;
        mu=1;
        di=1;
        po=0;
    }

 /*  std::string strq="ques",stra="ans";
    if(!xt.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xt.errorString();
    if(!xa.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xa.errorString();
    QTextStream out_6(&xt);
    QTextStream out_7(&xa);
    QString strq_1,stra_1;
    const char* exp="D:/build-dati-Desktop_Qt_5_4_0_MinGW_32bit-Debug/produce_q.txt";
    const char* ans="D:/build-dati-Desktop_Qt_5_4_0_MinGW_32bit-Debug/produce_a.txt";
*/
    canshu values={ques_num,oper_max,oper_num,prec,real,decimal,po,ad,su,mu,di,1000};
    //canshu values={5 ,10 ,10, 2, 0, 0, 0, 1, 1, 1, 1, 1000};

    //qDebug()<<values.num_ques<<values.scalemax_op<<values.num_op<<values.num_float<<values.is_real<<values.is_decimal<<values.is_power<<values.is_add<<values.is_sub<<values.is_mul<<values.is_div<<values.result_max;

    if(mylib.load())
    {

       Fun Produce=(Fun)mylib.resolve("?Produce@@YAHUcanshu@@@Z");
       Produce(values);//qDebug()<<"aaaa";
    }
    //(&xt)->close();
    //(&xa)->close();
    this->hide();
    widget->show();
}




