#ifndef WIDGET_H
#define WIDGET_H
#include<error.h>
#include <QWidget>
#include<QTimerEvent>
#include <setback.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
  void timerEvent(QTimerEvent *event);
private slots:
  void on_pushButton_clicked();

  void on_pushButton_4_clicked();


private:
    Ui::Widget *ui;
    int timerId;
    Setback *setback= new Setback;
};

#endif // WIDGET_H
