#include "FaceAuthentication.h"
#include "ui_FaceAuthentication.h"
#include "qv4l2.h"
//#include "compheader.h"
extern "C"
{
#include "gl11.h"
}
FaceAuthentication::FaceAuthentication(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceAuthentication)
{
  // ui->setupUi(this);
    ui->setupUi(this);
  //  setWindowFlags(Qt::FramelessWindowHint);
     //ui->setupUi(this);
    bool start =true;

    g_mw = new ApplicationWindow;
    g_mw->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    g_mw->setWindowTitle("V4L2 Test Bench");

    g_mw->setDevice("/dev/video2", true);

    qDebug()<<"buzz on in 1 sec    ##########################################################";
    gl11_buzz_on();

    sleep(1);
    gl11_buzz_off();
     qDebug()<<"buzz off in 1 sec    ##########################################################";


    g_mw->show();
    // FaceAuthentication::close();
    g_mw->capStart(start);

}

FaceAuthentication::~FaceAuthentication()
{
    delete ui;
}
