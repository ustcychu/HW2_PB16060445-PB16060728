#include "widget.h"
#include "ui_widget.h"
#include "error.h"
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QMessageBox>
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QDateTime>
#include<QTextCodec>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->display(20);

}
Widget::~Widget()
{
    delete ui;
}

static int i=1;int j=0;int flag=0;
QString ques[1000],ans[1000];
std::string strq, stra;
int m=0,n=0,l=0,max=0,score=0;

QFile er("error.txt"),hi("history.txt");
QFile ti("produce_q.txt"),da("produce_a.txt");
QFile sc("score.txt");
void Widget::on_pushButton_4_clicked()
{
/*   QString num;
   set(3, 100, 100,  0, 2);
   generate();
   while(get_exp(m, strq, stra) == true)
   {
       //把strq和stra转化为QString然后赋给ques[m]和ans[m]
       num=QString ::number(m+1);
       ques[m]=num+". "+ques[m];//加题号
       //把ques[m]和ans[m]写入文件
       m++;
   }
*/
    if(!da.open(QIODevice::ReadOnly |QIODevice::Text))
          qDebug()<<da.errorString();
      QTextStream in_0(&da);
      while(!in_0.atEnd()){
          QString line_1=in_0.readLine();
          ans[l]=line_1; //qDebug()<<ans[l];
          l++;
      }

    if(!ti.open(QIODevice::ReadOnly |QIODevice::Text))
        qDebug()<<ti.errorString();
    QTextStream in_1(&ti);
    QString num;
    while(!in_1.atEnd())
    {
            QString line_2=in_1.readLine();
            num=QString ::number(m+1);
            ques[m]=num+". "+line_2+" = ";
            m++;
    }


    if(!er.open(QIODevice::WriteOnly |QIODevice::Text))
         qDebug()<<er.errorString();
    if(!hi.open(QIODevice::WriteOnly |QIODevice::Text))
         qDebug()<<hi.errorString();
    if(!sc.open(QIODevice::WriteOnly |QIODevice::Text))
         qDebug()<<sc.errorString();
    ui->label_3->setText(ques[0]);
    ui->label_3->setWordWrap(true);
    timerId = startTimer(1000);   // 1s
    ui->stackedWidget->setCurrentIndex(i++);

    //qDebug()<<m;
}

void Widget::on_pushButton_clicked()
{
    QTextStream out_1(&hi);
    if(ui->answer1->text() == ans[n])
    {
        score++;
        out_1<<ques[n]<<ui->answer1->text()<<endl;
    }
    else{
        QTextStream out(&er);
        QString inf = QString(" (错误！答案应为%1)").arg(ans[n]);
        out<<ques[n]<<ui->answer1->text()<<inf<<endl;
        QString inf_1 = QString(" (错误！)");
        out_1<<ques[n]<<ui->answer1->text()<< inf_1<<endl;
    }
    n++;
    if(n==m)//题目数-1；
    {
        QString str = QString("恭喜！您答对了 %1 题！").arg(score);
        QMessageBox::information(this, "得分", str);

              QTextStream out_2(&sc);
              QString score_1;
              score_1=QString ::number(score);
              out_2<<score_1<<endl;
              out_2<<n<<endl;
        killTimer(this->timerId);
        this->hide();
        setback->show();
    }
    ui->label_3->setText(ques[n]);
    ui->label_3->setWordWrap(true);
    ui->answer1->setText("");
    ui->answer1->setFocus();
    ui->lcdNumber->display(20);
}

    /*if(ui->answer1->text() == "2")
      {
        ui->lcdNumber->display(20);
        j++;
      } else {
        QMessageBox::warning(this, tr("警告！"),
                tr("错误！"),
                QMessageBox::Yes);
      }*/

void Widget::timerEvent(QTimerEvent *event)
{
   ui->lcdNumber->display(ui->lcdNumber->value() - 1);    //时间递减
  if (ui->lcdNumber->value() == 0)                       //0s时
  {
      QTextStream out_1(&hi);
      if(ui->answer1->text() == ans[n])
      {
          score++;
          out_1<<ques[n]<<ui->answer1->text()<<endl;
      }
      else{
          QTextStream out(&er);
          QString inf = QString(" (错误！答案应为%1)").arg(ans[n]);
          out<<ques[n]<<ui->answer1->text()<<inf<<endl;
          QString inf_1 = QString(" (错误！)");
          out_1<<ques[n]<<ui->answer1->text()<< inf_1<<endl;
      }
    n++;                                               //计数+1
    if(n==m)//题目数-1；
    {
        QString str = QString("恭喜！您答对了 %1 题！").arg(score);
        QMessageBox::information(this, "得分", str);

        QTextStream out_2(&sc);
        QString score_1;
        score_1=QString ::number(score);
        out_2<<score_1<<endl;
        out_2<<n<<endl;

        killTimer(this->timerId);
        this->hide();
        setback->show();
    }
    ui->label_3->setText(ques[n]);
    ui->answer1->setText("");
    ui->answer1->setFocus();
    ui->lcdNumber->display(20);
   }
}
