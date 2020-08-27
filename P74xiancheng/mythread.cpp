#include "mythread.h"

mythread::mythread(QObject *parent) : QThread(parent)
{

}

void mythread::run()
{
    sleep(5);
    emit isdone();
}
