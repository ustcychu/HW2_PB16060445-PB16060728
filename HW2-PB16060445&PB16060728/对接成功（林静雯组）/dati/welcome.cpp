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
#include "DLL.h"

using namespace std;

typedef void(*Fun)(int, int, int, bool, bool, int, int, int);

QLibrary mylib("DLL1.dll");

extern int ques_num, oper_max, oper_num, oper_kind, prec;
extern bool frac, doub;

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
    int m=1;  //qDebug()<<oper_kind<<ad<<su<<mu<<di<<po;
    std::string strq="ques",stra="ans";
    if(!xt.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xt.errorString();
    if(!xa.open(QIODevice::WriteOnly |QIODevice::Text))
        qDebug()<<xa.errorString();

    if(mylib.load())
    {
        Fun set=(Fun)mylib.resolve("?set@@YA_NHHH_N0HHH@Z");
        set(ques_num, oper_num, prec, frac, doub, 1, oper_max, oper_kind);
    }
    (&xt)->close();
    (&xa)->close();
    this->hide();
    widget->show();
}




