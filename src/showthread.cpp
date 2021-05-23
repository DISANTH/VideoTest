#include "showthread.h"
#include "ui_mainwindow.h"

showThread::showThread(QObject *parent)
    :QThread(parent)
{
}

void showThread::run()
{
    while(1)
    {
        QThread::msleep(100);
        //sleep(1);
        emit showsigtest();
    //printf("Hello from Thread!\n");

    }
}
