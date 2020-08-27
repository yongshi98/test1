#include "widget.h"
#include "ui_widget.h"
#include<QThread>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerout);
    thread =new mythread(this);
    connect(this,&Widget::destroyed,[=](){
       //关闭线程
       thread->quit();
       //等待线程处理完手头工作
       thread->wait();
       qDebug()<<"线程已经关闭";
    });
}

Widget::~Widget()
{
    delete ui;
}



void Widget::timerout()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}
void Widget::on_pushButton_clicked()
{
    if(timer->isActive()==false)
    {
        timer->start(10);
    }

    //假如要经过长时间数据处理
    //QThread::sleep(3);
    thread->start();
    connect(thread,&mythread::isdone,this,&Widget::dealdone);


}

void Widget::dealdone()
{
    qDebug()<<"thread is over";
    timer->stop();
}
