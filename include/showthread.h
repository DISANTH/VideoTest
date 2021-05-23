#ifndef SHOWTHREAD_H
#define SHOWTHREAD_H

#include <QThread>
//#include "mainwindow.h"

class showThread : public QThread
{
    Q_OBJECT

public:
   showThread(QObject *parent=0);

protected:
   void run();

signals:
   void showsigtest();
};


#endif // THREAD_H
