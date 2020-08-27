#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);
    //qthread 的虚函数，线程处理函数，通过start调用
    void run() override;


signals:
    void isdone();

};

#endif // MYTHREAD_H
