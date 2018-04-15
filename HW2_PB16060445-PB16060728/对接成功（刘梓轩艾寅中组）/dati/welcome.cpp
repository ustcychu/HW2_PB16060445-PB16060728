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
#include "DLL2.h"

using namespace std;

typedef bool (*Fun)(int,int);
typedef bool (*Fun1)(int,int);
typedef bool (*Fun2)(int);
typedef bool (*Fun3)(int);
typedef bool (*Fun4)(bool,bool,bool,bool,bool);
typedef bool (*Fun5)(bool);
typedef bool (*Fun6)(int);
typedef bool (*Fun7)(bool,bool,string,string);
typedef void (*Fun8)(void);

QLibrary mylib("DLL2.dll");

extern int ques_num, oper_max, oper_num, oper_kind, prec, flag_1;
extern bool ad, su, mu, di, po;

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
    if(flag_1 == 0)
    {
        ad=1;
        su=1;
        mu=1;
        di=1;
        po=0;
    }
    int m=1; qDebug()<<ques_num<<oper_max<<oper_num<<oper_kind<<prec<<ad<<su<<mu<<di<<po;
    std::string strq="ques",stra="ans";
    if(!xt.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xt.errorString();
    if(!xa.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xa.errorString();
    QTextStream out_6(&xt);
    QTextStream out_7(&xa);
    QString strq_1,stra_1;
    string exp="D:/build-dati-Desktop_Qt_5_4_0_MinGW_32bit-Debug/produce_q.txt";
    string  ans="D:/build-dati-Desktop_Qt_5_4_0_MinGW_32bit-Debug/produce_a.txt";

    if(mylib.load())
    {
        Fun set_range=(Fun)mylib.resolve("?set_range@@YA_NHH@Z");
        Fun1 set_len=(Fun1)mylib.resolve("?set_len@@YA_NHH@Z");
        Fun2 set_mode=(Fun2)mylib.resolve("?set_mode@@YA_NH@Z");
        Fun3 set_row=(Fun3)mylib.resolve("?set_row@@YA_NH@Z");
        Fun4 set_operator=(Fun4)mylib.resolve("?set_operator@@YA_N_N0000@Z");
        Fun5 set_PowerType=(Fun5)mylib.resolve("?set_PowerType@@YA_N_N@Z");
        Fun6 set_xi_disp=(Fun6)mylib.resolve("?set_xi_disp@@YA_NH@Z");
        // Fun7 set_path=(Fun7)mylib.resolve("?set_path@@YA_N_N0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z");
        Fun8 N_generate=(Fun8)mylib.resolve("?N_generate@@YAXXZ");

        set_range(1,oper_max);
        set_len(3,2*oper_num-1);
        set_mode(oper_kind);
        set_row(ques_num);
        set_operator(ad, su, mu, di, po);
        set_PowerType(0);
        set_xi_disp(prec);
        N_generate();


    }
    (&xt)->close();
    (&xa)->close();
    this->hide();
    widget->show();
}




