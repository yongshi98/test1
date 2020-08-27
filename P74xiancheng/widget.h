#ifndef WIDGET_H
#define WIDGET_H
#include<QTimer>
#include <QWidget>
#include "mythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void timerout();
    void dealdone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    mythread *thread;
};
#endif // WIDGET_H
