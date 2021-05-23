#include "videodev2.h"
#include "qv4l2.h"
#include "general-tab.h"
#include "capture-win.h"
#include "error.h"
#include "errno.h"

#include <QToolBar>
#include <QToolButton>
#include <QMenuBar>
#include <QFileDialog>
#include <QStatusBar>
#include <QApplication>
#include <QMessageBox>
#include <QLineEdit>
#include <QValidator>
#include <QLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QToolTip>
#include <QImage>
#include <QWhatsThis>
#include <QThread>
#include <QCloseEvent>
#include <QThread>
#include <QTimer>
#include<QStatusBar>

#include <assert.h>
#include <sys/mman.h>
#include <errno.h>
#include <dirent.h>
#include "core.hpp"
//int timeoutCount=0;
int countflag=0,blinkCount1=0;
#include "FaceAuthentication.h"


QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #338D52,stop: 0.4999 #338D52,stop: 0.5 #338D52,stop: 1 #338D52 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";


extern "C"
{
#include "gl11.h"
}

int flag2=0;
int green_count=0;
bool greenbuzz=false;
bool Frameflag=false;
ApplicationWindow::ApplicationWindow() :
    //m_capture(NULL),
    m_sigMapper(NULL)
{

    this->setGeometry(0,0,640,480);
    gl11_iodev_open();


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(LCD_ON()));
    timer->start(90);


    // gl11_audio_power_on();
    //system("amixer cset numid=1 190");
    // showFullScreen();
    // setAttribute(Qt::WA_DeleteOnClose, true);
    QMenu *file = new QMenu();
    //QMenuBar *menuBar1 = new QMenuBar(0);
    //file = menuBar()->addMenu(tr("&VIEW"));

    //For Exit
    QAction* exit = new QAction(tr("&Exit"),this);
    //  exit->setShortcuts(QKeySequence::Close);
    exit->setStatusTip(tr("exit now"));
    //menuBar()->addAction(exit);
    file->addAction(exit);
    connect(exit, SIGNAL(triggered()), this, SLOT(closeApp()));

    //Viewing Saved image
//    QAction* savedImage = new QAction(tr("&ShowImage"),this);
//    //  exit->setShortcuts(QKeySequence::Close);
//    savedImage->setStatusTip(tr("saved image"));
//    file->addAction(savedImage);
//    connect(savedImage, SIGNAL(triggered()), this, SLOT(ShowImage()));


    // menuBar1->addMenu(file);



//    dlib::deserialize("/mnt/jffs2/shape_predictor_68_face_landmarks.dat") >> pose_model;
//       detector = dlib::get_frontal_face_detector();


    m_capNotifier = NULL;
    m_capImage = NULL;
    m_frameData = NULL;
    m_nbuffers = 0;
    m_buffers = NULL;

    m_capImage = new QImage;
    CvSize Size;
    Size.height = 240 ; //720; //240
    Size.width = 320 ;//1280; //320


    quitAct = new QAction(QIcon(":/IMAGES/cross1.jpeg"), "&Quit", this);
    //quitAct->setStatusTip("Exit the application");

    quitAct->setEnabled(true);

    connect(quitAct, SIGNAL(triggered()), this, SLOT(closeApp()));
    QToolBar *toolBar = addToolBar("");
    toolBar->setObjectName("toolBar");
   // toolBar->addAction(m_capStartAct);
//    toolBar->addSeparator();
//    toolBar->addSeparator();
    toolBar->addSeparator();
    toolBar->addSeparator();
    toolBar->addAction(quitAct);


    //added on 22-10-2020


//    probar=new QProgressBar();
//    probar->setParent(this);
//    probar->setGeometry(100,50,150,50);
//  //  probar->setOrientation(Qt::Vertical);
//   // probar->setTextDirection(QProgressBar::BottomToTop);
//    toolBar->addSeparator();
//    toolBar->addSeparator();

//   probar->setValue(40);

//   // statusBar()->addPermanentWidget(probar,1);

////toolBar->addAction(probar);

//     if(probar->value()>=50)
//     {
//    probar->setStyleSheet(safe);
//     }
//     else{
//     probar->setStyleSheet(danger);
//     }
//    // toolBar->addAction(probar);
//     //statusBar()->addPermanentWidget(probar,1);
//     probar->setEnabled(true);
//     probar->show();

    //**********END************


    m_tabs = new QTabWidget;
    m_tabs->setFixedSize(320, 240);
        setCentralWidget(m_tabs);



    charIplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 1);

    cvsaveimg = cvCreateImage(Size, IPL_DEPTH_8U, 3);

    cvimg = cvCreateImage(Size, IPL_DEPTH_8U, 1);


    paintThread = new Thread;
    connect(paintThread,SIGNAL(sigtest() ),this,SLOT(paintRun()),Qt::DirectConnection);
    paintThread->start();

    //    paintThread1 = new Thread;
    //    connect(paintThread1,SIGNAL(sigtest1() ),this,SLOT(paintRun1()),Qt::DirectConnection);
    //    paintThread1->start();

#if 0
    FaceDetectThread *faceThread = new FaceDetectThread(this);
    connect(faceThread,SIGNAL(sigtest()),this,SLOT(paintRun()));

    faceThread->start();
    faceThread->moveToThread(faceThread);
#endif
    m_tabs = new QTabWidget;
    //connect(this,SIGNAL(Photocapturing()),paintThread,SLOT(terminate()));
    //m_tabs->setFixedSize(320, 240);
    // setCentralWidget(m_tabs);

}

void ApplicationWindow::LCD_ON()
{
     gl11_lcdbklt_on();

}

void ApplicationWindow::paintRun1()
{
    qDebug()<<"INSIDE QGraphicsScene";

    //    QGraphicsScene  *scene = new QGraphicsScene(this);
    //    QGraphicsView *view=new QGraphicsView(this);
    //    view->setGeometry(0,0,320,240);
    //    view->setScene(scene);
    //    QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    //    //     painter.setPen(pen);
    //    //    painter.drawRect(50, 20,230,180);
    //    QGraphicsRectItem *rectangle = scene->addRect(0, 0,320,240,pen);

}
void FaceDetectThread::run()
{
    while(1)
    {
        //printf("Hello from Thread!\n");
        QThread::msleep(100);
        //sleep(1);
        emit sigtest();
        // emit sigtest1();
    }
}

void ApplicationWindow::ShowImage()
{
    qDebug()<<"SHOW IMAGE>>>>>>>>>>>>>>>>>>>>>";
    QDialog d(this) ;
/*
QPalette Palet = d.palette();
QPixmap pix(":/root/Captured.jpeg");

QPixmap pix_scaled(pix.scaled(316,150,  Qt::IgnoreAspectRatio, Qt::SmoothTransformation ));
Palet.setBrush(QPalette::Window, QBrush(pix_scaled));
setPalette(Palet);
setAutoFillBackground(true);
*/
   // d.setParent(this);
    d.setGeometry(0,0,640,480);
   // d.setStyleSheet("background-image: url(/root/Captured.jpeg)");
    d.setStyleSheet("background-image: url(/tmp/test.jpeg)");
    d.exec();
}

void ApplicationWindow::sample()
{
    qDebug()<<"************************Hi Inside Thread slot";

    cvimg = QImageToIplImage(m_capImage);
}


//ApplicationWindow::~ApplicationWindow()
//{
//    gl11_audio_power_off();
//    gl11_iodev_close();
//    //paintThread->quit();
//    //paintThread->wait();
//    // delete paintThread;
//    closeDevice();
//    qDebug()<<"---------------------IN DESTRUCTOR";
//    FaceAuthentication *face = new FaceAuthentication;
//    face->show();
//    face->imageProcessing();



//}

//void ApplicationWindow::closeApp()
//{
//    QFont BtnFont("Times", 13, QFont::Bold);
// //timer_flag = 1;
//       QMessageBox verify_msg1;
//       verify_msg1.setFont(BtnFont);
//       verify_msg1.setGeometry(68,50,400,250);
//       verify_msg1.setStyleSheet("background-color: rgb(255, 170, 127);");
//       verify_msg1.setInformativeText("<b>Back To Face Verification Screen</b>");
//       //verify_msg1.setStandardButtons(QMessageBox   ::Ok);
//       verify_msg1.setWindowFlags(Qt::FramelessWindowHint);
//       verify_msg1.setParent(this);
//     //  verify_msg1.setWindowModality(Qt::ApplicationModal);
//       QTimer::singleShot(10000, &verify_msg1 , SLOT(hide()));//10 sec time out
//       verify_msg1.exec();
//    stopCapture();
//    paintThread->terminate();
//    g_mw->close();
//    /*	delete g_mw;
//    g_mw=NULL;*/
//    qDebug("closed");
//    close();


//}

void ApplicationWindow::closeApp()
{
    QCoreApplication::processEvents();

    stopCapture();
       paintThread->terminate();
       QCoreApplication::processEvents();

       g_mw->close();


    /*	delete g_mw;
    g_mw=NULL;*/
 //   qDebug("closed");
     // close();
}

void ApplicationWindow::setCheck()
{               

    // g_mw->m_capStartAct->setChecked(true);
}  


void ApplicationWindow::setDevice(const QString &device, bool rawOpen)
{
    qDebug("in setDevice");
    closeDevice();
    m_sigMapper = new QSignalMapper(this);
    connect(m_sigMapper, SIGNAL(mapped(int)), this, SLOT(ctrlAction(int)));

    if (!open(device, !rawOpen))
        return;

    //	m_capture = new CaptureWin;
    //	m_capture->setParent(m_tabs);
    //        m_capture->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //	//m_capture->setFixedSize(200, 200);
    //	connect(m_capture, SIGNAL(close()), this, SLOT(closeCaptureWin()));
    QWidget *w = new QWidget(m_tabs);
    m_genTab = new GeneralTab(device, *this, 4, w);
    //	m_tabs->addTab(w, "General");
    addTabs();
    if (QWidget *current = m_tabs->currentWidget()) {
        current->show();
    }
    //m_tabs->show();
    //m_tabs->setFocus();
    m_convertData = v4lconvert_create(fd());
    //m_capStartAct->setEnabled(fd() >= 0);

}
void ApplicationWindow::openrawdev()
{
    QFileDialog d(this, "Select v4l device", "/dev", "V4L Devices (video* vbi* radio*)");

    qDebug("in openrawdev fun");

    d.setFilter(QDir::Dirs | QDir::System);
    d.setFileMode(QFileDialog::ExistingFile);
    if (d.exec())
        setDevice(d.selectedFiles().first(), true);
}


bool ApplicationWindow::startCapture(unsigned buffer_size)
{

   // sleep(3);
    unsigned int i;
    v4l2_requestbuffers req;

    qDebug("in stratCapture fun");

    memset(&req, 0, sizeof(req));
    switch (m_capMethod) {
    case methodRead:
        /* Nothing to do. */
        return true;

    case methodMmap:
        if (!reqbufs_mmap_cap(req, 3)) {
            error("Cannot capture 1");
            break;
        }

        if (req.count < 2) {
            error("Too few buffers");
            reqbufs_mmap_cap(req);
            break;
        }

        m_buffers = (buffer *)calloc(req.count, sizeof(*m_buffers));

        if (!m_buffers) {
            error("Out of memory");
            reqbufs_mmap_cap(req);
            break;
        }

        for (m_nbuffers = 0; m_nbuffers < req.count; ++m_nbuffers) {
            v4l2_buffer buf;

            memset(&buf, 0, sizeof(buf));

            buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buf.memory      = V4L2_MEMORY_MMAP;
            buf.index       = m_nbuffers;

            if (-1 == ioctl(VIDIOC_QUERYBUF, &buf)) {
                perror("VIDIOC_QUERYBUF");
                goto error;
            }

            m_buffers[m_nbuffers].length = buf.length;
            m_buffers[m_nbuffers].start = mmap(buf.length, buf.m.offset);

            if (MAP_FAILED == m_buffers[m_nbuffers].start) {
                perror("mmap");
                goto error;
            }
        }
        for (i = 0; i < m_nbuffers; ++i) {
            if (!qbuf_mmap_cap(i)) {
                perror("VIDIOC_QBUF");
                goto error;
            }
        }
        if (!streamon_cap()) {
            perror("VIDIOC_STREAMON");
            goto error;
        }
        return true;

    case methodUser:
        if (!reqbufs_user_cap(req, 4)) {
            error("Cannot capture 2");
            break;
        }

        if (req.count < 4) {
            error("Too few buffers");
            reqbufs_user_cap(req);
            break;
        }

        m_buffers = (buffer *)calloc(4, sizeof(*m_buffers));

        if (!m_buffers) {
            error("Out of memory");
            break;
        }

        for (m_nbuffers = 0; m_nbuffers < 4; ++m_nbuffers) {
            m_buffers[m_nbuffers].length = buffer_size;
            m_buffers[m_nbuffers].start = malloc(buffer_size);

            if (!m_buffers[m_nbuffers].start) {
                error("Out of memory");
                goto error;
            }
        }
        for (i = 0; i < m_nbuffers; ++i)
            if (!qbuf_user_cap(i, m_buffers[i].start, m_buffers[i].length)) {
                perror("VIDIOC_QBUF");
                goto error;
            }
        if (!streamon_cap()) {
            perror("VIDIOC_STREAMON");
            goto error;
        }
        return true;
    }

   // sleep(3);

error:
    //m_capStartAct->setChecked(false);
    return false;
}

void ApplicationWindow::stopCapture()
{

    qDebug("in stop Capture");

    v4l2_requestbuffers reqbufs;
    v4l2_encoder_cmd cmd;
    unsigned int i;

    switch (m_capMethod) {
    case methodRead:
        memset(&cmd, 0, sizeof(cmd));
        cmd.cmd = V4L2_ENC_CMD_STOP;
        ioctl(VIDIOC_ENCODER_CMD, &cmd);
        break;

    case methodMmap:
        if (m_buffers == NULL)
            break;
        if (!streamoff_cap())
            perror("VIDIOC_STREAMOFF");
        for (i = 0; i < m_nbuffers; ++i)
            if (-1 == munmap(m_buffers[i].start, m_buffers[i].length))
                perror("munmap");
        // Free all buffers.
        reqbufs_mmap_out(reqbufs, 0);
        break;

    case methodUser:
        if (!streamoff_cap())
            perror("VIDIOC_STREAMOFF");
        for (i = 0; i < m_nbuffers; ++i)
            free(m_buffers[i].start);

        break;
    }
    free(m_buffers);
    m_buffers = NULL;
    //m_capture->stop();
}

void ApplicationWindow::startOutput(unsigned)
{
}

void ApplicationWindow::stopOutput()
{
}

void ApplicationWindow::closeCaptureWin()
{
    //m_capStartAct->setChecked(false);
}

void ApplicationWindow::capStart(bool start)
{

    qDebug("in CapStart");

//sleep(3);
    static const struct {
        __u32 v4l2_pixfmt;
        QImage::Format qt_pixfmt;
    } supported_fmts[] = {
    { V4L2_PIX_FMT_RGB32, QImage::Format_ARGB32 },



    { V4L2_PIX_FMT_RGB24, QImage::Format_RGB888 },
    { V4L2_PIX_FMT_RGB565X, QImage::Format_RGB16 },
    { V4L2_PIX_FMT_RGB555X, QImage::Format_RGB555 },
    { V4L2_PIX_FMT_RGB444, QImage::Format_RGB444 },
    { 0, QImage::Format_Invalid }
};
    QImage::Format dstFmt = QImage::Format_RGB888;
//sleep(3);
    if (!start) {
        stopCapture();
        qDebug("hello");
        delete m_capNotifier;
        m_capNotifier = NULL;
     //  sleep(3);


   //     m_capImage->scaled(QSize(320,240), Qt::IgnoreAspectRatio).save("/root/test.png","PNG",1);

      //   m_capImage->scaled(QSize(1280,720), Qt::KeepAspectRatio,Qt::FastTransformation).save("/tmp/test.jpeg","JPEG",70);
if(flag2==1)
{
      m_capImage->scaled(QSize(1280,720), Qt::KeepAspectRatio,Qt::FastTransformation).save("/root/test.jpeg","JPEG",70);
}



       //  m_capImage->scaled(QSize(1280,720), Qt::IgnoreAspectRatio).save("/root/test.jpeg","JPEG",100);
        delete m_capImage;



        return;
    }
    m_capMethod = m_genTab->capMethod();
    g_fmt_cap(m_capSrcFormat);
    m_frameData = new unsigned char[m_capSrcFormat.fmt.pix.sizeimage];
    m_capDestFormat = m_capSrcFormat;
    m_capDestFormat.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24;

    for (int i = 0; supported_fmts[i].v4l2_pixfmt; i++) {
        if (supported_fmts[i].v4l2_pixfmt == m_capSrcFormat.fmt.pix.pixelformat) {
            m_capDestFormat.fmt.pix.pixelformat = supported_fmts[i].v4l2_pixfmt;
            dstFmt = supported_fmts[i].qt_pixfmt;
            break;
        }
    }
    v4lconvert_try_format(m_convertData, &m_capDestFormat, &m_capSrcFormat);
    // v4lconvert_try_format sometimes modifies the source format if it thinks
    // that there is a better format available. Restore our selected source
    // format since we do not want that happening.
    g_fmt_cap(m_capSrcFormat);
    //->setMinimumSize(m_capDestFormat.fmt.pix.width, m_capDestFormat.fmt.pix.height);
    m_capImage = new QImage(m_capDestFormat.fmt.pix.width, m_capDestFormat.fmt.pix.height, dstFmt);

    m_capImage->fill(0);




    //m_capture->setImage(*m_capImage, true);
    //     m_capture->setGeometry(0,30,320,200);
    //m_capture->show();
    if (startCapture(m_capSrcFormat.fmt.pix.sizeimage))
    {
        m_capNotifier = new QSocketNotifier(fd(), QSocketNotifier::Read, m_tabs);
        connect(m_capNotifier, SIGNAL(activated(int)), this, SLOT(capFrame()));
        //    qtime = new QTimer(this);
        //   connect(qtime,SIGNAL(timeout()),this,SLOT(repaint()));
    }
}

void ApplicationWindow::capFrame()
{
    v4l2_buffer buf;
    unsigned i;
    int s = 0;
    int err = 0;
if(Frameflag==false){

    qDebug("in capFrame fun");

    switch (m_capMethod) {
    case methodRead:
        s = read(m_frameData, m_capSrcFormat.fmt.pix.sizeimage);
        qDebug("in capFrame fun case :method read");
        err = v4lconvert_convert(m_convertData, &m_capSrcFormat, &m_capDestFormat,
                                 m_frameData, m_capSrcFormat.fmt.pix.sizeimage,
                                 m_capImage->bits(), m_capDestFormat.fmt.pix.sizeimage);
        break;

    case methodMmap:
        if (!dqbuf_mmap_cap(buf)) {
            error("dqbuf");
            qDebug("in case  method Mmap");
            //	m_capStartAct->setChecked(false);
            return;
        }

        err = v4lconvert_convert(m_convertData, &m_capSrcFormat, &m_capDestFormat,
                                 (unsigned char *)m_buffers[buf.index].start, buf.bytesused,
                m_capImage->bits(), m_capDestFormat.fmt.pix.sizeimage);
        qDebug("in v412convert case");
        //frame sending
        qbuf(buf);
        break;

    case methodUser:
        if (!dqbuf_user_cap(buf)) {
            error("dqbuf");
            qDebug("in method user case ");
            //m_capStartAct->setChecked(false);
            return;
        }

        for (i = 0; i < m_nbuffers; ++i)
            if (buf.m.userptr == (unsigned long)m_buffers[i].start
                    && buf.length == m_buffers[i].length)
                break;

        err = v4lconvert_convert(m_convertData, &m_capSrcFormat, &m_capDestFormat,
                                 (unsigned char *)buf.m.userptr, buf.bytesused,
                                 m_capImage->bits(), m_capDestFormat.fmt.pix.sizeimage);

        qbuf(buf);
        break;
    }
    //m_capture->setImage(*m_capImage);
    update();
}
else
{
    closeApp();
    //repaint();
}

}

void ApplicationWindow::paintEvent(QPaintEvent *)
{
//    qDebug()<<"PAINTEVENT=====================================";
//    qDebug()<<"rectList values is--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>---------"<<rectList.x<<rectList.y<<rectList.width<<rectList.height;
//int success=0;
//    QDialog *Dlg =new QDialog(this);
//    Dlg->setWindowTitle("FaceAuth::");
//    Dlg->setWindowFlags(Qt::FramelessWindowHint);
//     Dlg->setGeometry(100,100,220,90);

//    QFont BtnFont("times",13,QFont::Bold);
//  QLabel *lb=new QLabel("<font color=green><b>Captured!!</b></font>",Dlg);
//  lb->setFont(BtnFont);
//lb->setGeometry(0,-20,220,100);
//  lb->show();
//  QTimer *timer = new QTimer(this);
//         connect(timer, SIGNAL(timeout()), Dlg, SLOT(close()));
//QCoreApplication::processEvents();
//         timer->start(1000);
//QCoreApplication::processEvents();
 if(rectList.x <= 0  && rectList.y <= 0 && Frameflag==false)
 {
               QPainter painter(this);
               QPainter painter1(this);
               QPen pen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
                 QPen pen1(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                 painter.setPen(pen);
                 painter.drawImage(0,0,*m_capImage);
                 painter1.setPen(pen1);
                  painter1.drawEllipse(30,10,260,220);
                  painter.end();
                  painter1.end();

                  //  Dlg->close();
                  QCoreApplication::processEvents();


}

     //   if(rectList.x>0 && rectList.y>0 && Frameflag==false)//&& success ==1)
            if(rectList.x>=40 && rectList.y>=20 && Frameflag==false)
            {
                QCoreApplication::processEvents();

                                  QPainter painter2(this);
                                 QPainter painter3(this);
                                  QPen pen2(Qt::green, 1, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
                                   QPen pen3(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                                   painter2.setPen(pen2);
                                   painter2.drawImage(0,0,*m_capImage);
                                   painter3.setPen(pen3);
                                    painter3.drawEllipse(30,10,260,220);
                                    // painter3.drawEllipse(30,10,200,180);
                                      painter2.end();
                                       painter3.end();
                                       green_count++;


//Dlg->exec();
              sleep(0.5);
          //    sleep(2);
//              int flag=0;
              if(green_count==3 && greenbuzz==false)
              {
              convert_qimage_to_iplimage(m_capImage,cvsaveimg);
// if(greenbuzz==false){
                            qDebug()<<"buzz on in 1 sec    ##########################################################";
                                               gl11_buzz_on();
                                                sleep(1);
                                                 gl11_buzz_off();
                                                 qDebug()<<"buzz off in 1 sec    ##########################################################";
                                                // greenbuzz=true;
// }
                              cvsaveimg1=cvCreateImage(cvSize(1280,720),cvsaveimg->depth,cvsaveimg->nChannels);
                                     cvResize(cvsaveimg,cvsaveimg1,CV_INTER_LINEAR);
                                    cvSaveImage("/tmp/test.jpeg",cvsaveimg1);
                                        system("curl -T /tmp/test.jpeg ftp://115.111.229.10 -u rnd:rnd123");
                                              Frameflag=true;
//                                    flag=2;
                            //  cvSaveImage("/tmp/test.jpeg",cvsaveimg);

//                                   sleep(2);
                                    green_count=0;
                                    greenbuzz=true;

                                      QTimer *timer = new QTimer(this);
                                           connect(timer, SIGNAL(timeout()), this, SLOT(closeApp()));
                                           timer->start(1000);

                                          // connect(this,SIGNAL(keyString()),this,SLOT(closeApp()));

                                   // closeApp();

                                   //  qDebug()<<"flag val is::"<<i;
//                                    if(i==2)
//                                    {
//                                        qDebug()<<"flag val is::"<<i;
//                                        closeApp();


//                                    }


//            }
              }

}



}
/*int ApplicationWindow::closepop()
{
qDebug()<<"closepop called";

}*/

void ApplicationWindow::DisplayPopup()
{
    qDebug()<<"Inside Display Popup";
    QMessageBox *enr_msg = new QMessageBox;
    enr_msg->setStyleSheet("background-color:rgb(188,133,255)");
    enr_msg->setInformativeText("<b>EYE BLINKED!! Photo Captured</b>");
    /*sim1_msg.setStandardButtons(QMessageBox::NoButton);*/
    enr_msg->setStandardButtons(QMessageBox::Ok);
    //enr_msg.setWindowFlags(Qt::FramelessWindowHint);
    //enr_msg.setParent(this);
    // enr_msg.setWindowModality(Qt::ApplicationModal);
    // QTimer::singleShot(1000, &enr_msg, SLOT(close()));
    /*sim1_msg.show();*/
    enr_msg->exec();
    QCoreApplication::processEvents();
}

void ApplicationWindow::paintRun()
{
    //    QPainter painter(this);
    //     QPen pen(Qt::red, 2, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    //     painter.setPen(pen);
    //    painter.drawRect(50, 20,230,180);
    // #if 1
if(Frameflag==false){
    qDebug()<<"Inside paintRun Thread"<<QTime::currentTime().toString("hh:mm:ss");;
    faceDetect.region.width=0;
    faceDetect.region.height=0;
#if 1
    if(m_capImage->size().width()!= 0 )// && timeoutCount ==0)
    {

      //  if(countflag !=0)
     //  {
        qDebug()<<"Before converting QImage to IplImage"<<QTime::currentTime().toString("hh:mm:ss");;
        cvimg = QImageToIplImage(m_capImage);
        //convert_qimage_to_iplimage(m_capImage,cvimg);

        qDebug()<<"After converting QImage to IplImage iplImage"<<QTime::currentTime().toString("hh:mm:ss");;
        rectList.width=0;rectList.height=0;
        rectList = faceDetect.facesdetect(cvimg);
        qDebug()<<"------>>>>>>>>>>>>>>>>>>>>>>rect list values in paint run thread"<<rectList.x<<rectList.y<<rectList.width<<rectList.height;
        //  rectList = faceDetect.detectFaces(cvimg);
        qDebug()<<"After FaceDetect Method"<<QTime::currentTime().toString("hh:mm:ss");
        qDebug()<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ rect list values in paint run thread"<<rectList.x<<rectList.y<<rectList.width<<rectList.height;


        }


    #endif


    else{
        qDebug()<<"Image is NULL";
    }
}


}

IplImage *ApplicationWindow::QImageToIplImage(const QImage * qImage)
{
    QTime time;
    qDebug()<<"INSIDE IPLIMAGE"<<time.currentTime().toString("hh:mm:ss");
    int width = qImage->width();
    int height = qImage->height();
    //    CvSize Size;
    //    Size.height = height;
    //    Size.width = width;

    //      IplImage* charIplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 1);
    char *charTemp = (char *) charIplImageBuffer->imageData;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = y * width + x;
            charTemp[index] = (char) qGray(qImage->pixel(x, y));
        }
    }
    qDebug()<<"AFTER CVSet2D\n"<<time.currentTime().toString("hh:mm:ss");
    return charIplImageBuffer;
}
void ApplicationWindow::convert_qimage_to_iplimage(QImage* qImage,IplImage* cvimg)
{
    QTime time;
    qDebug()<<"INSIDE IPLIMAGE"<<time.currentTime().toString("hh:mm:ss");
    int width = qImage->width();
    int height = qImage->height();
    qDebug()<<"BEFORE CvSize IPLIMAGE"<<time.currentTime().toString("hh:mm:ss");;
    CvSize Size;
    Size.height = height;
    Size.width = width;
    qDebug()<<"AFTER CvSize IPLIMAGE"<<time.currentTime().toString("hh:mm:ss");;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            QRgb rgb = qImage->pixel(x, y);
            cvSet2D(cvimg, y, x, CV_RGB(qRed(rgb), qGreen(rgb), qBlue(rgb)));

        }
    }
    qDebug()<<"AFTER CVSet2D\n"<<time.currentTime().toString("hh:mm:ss");
}                                               

//void ProcessImage::convert_qimage_to_iplimage(QImage* qImage,IplImage* cvimg)
//{
//    int width = qImage->width();
//    int height = qImage->height();
//    CvSize Size;
//    Size.height = height;
//    Size.width = width;
//    for (int y = 0; y < height; ++y)
//    {
//        for (int x = 0; x < width; ++x)
//        {
//            QRgb rgb = qImage->pixel(x, y);
//            cvSet2D(cvimg, y, x, CV_RGB(qRed(rgb), qGreen(rgb), qBlue(rgb)));
//        }
//    }
//}


void ApplicationWindow::closeDevice()
{

    qDebug("in close Device------------>>>>>>>>>>>>>>>>>>>");

    //m_capStartAct->setEnabled(false);
    //m_capStartAct->setChecked(false);
    if (fd() >= 0) {
        if (m_capNotifier) {
            delete m_capNotifier;
            delete m_capImage;
            m_capNotifier = NULL;
        }
        delete m_frameData;
        m_frameData = NULL;
        v4lconvert_destroy(m_convertData);
        v4l2::close1();
        //	delete m_capture;
        //m_capture = NULL;
    }
    while (QWidget *page = m_tabs->widget(0)) {
        m_tabs->removeTab(0);
        delete page;
    }
    delete m_sigMapper;
    m_sigMapper = NULL;
    m_ctrlMap.clear();
    m_widgetMap.clear();
    m_classMap.clear();
    /*int cam_ret1;
    cam_ret1=gl11_cam_control(0);
    if(cam_ret1==0)
    {
        printf("camera control disable success\n");
    }
*/

}

void ApplicationWindow::about()
{
    QMessageBox::about(this, "V4L2 Test Bench",
                       "This program allows easy experimenting with video4linux devices.");
}

void ApplicationWindow::error(const QString &error)
{
    statusBar()->showMessage(error, 20000);
    if (!error.isEmpty())
        fprintf(stderr, "%s\n", error.toAscii().data());
}

void ApplicationWindow::error(int err)
{
    error(QString("Error: %1").arg(strerror(err)));
}

void ApplicationWindow::errorCtrl(unsigned id, int err)
{
    error(QString("Error %1: %2")
          .arg((const char *)m_ctrlMap[id].name).arg(strerror(err)));
}

void ApplicationWindow::errorCtrl(unsigned id, int err, long long v)
{
    error(QString("Error %1 (%2): %3")
          .arg((const char *)m_ctrlMap[id].name).arg(v).arg(strerror(err)));
}

void ApplicationWindow::info(const QString &info)
{
    statusBar()->showMessage(info, 5000);
}

void ApplicationWindow::closeEvent(QCloseEvent *event)
{

    closeDevice();
    //delete m_capture;
    event->accept();
    qDebug("closeEvent AppWin");
    exit(0);

}

//void ApplicationWindow::keyPressEvent(QKeyEvent *ke)
//{
//        int keyVal = ke->key();
//        qDebug("KeyPressEvent");
//        qDebug("keyEvent=%d",keyVal);

//        qDebug("in keyEvent");

//        switch(keyVal)
//        {
//                case 16777220:
//            qDebug("Enter Press");
//            setCursor(Qt::WaitCursor);
//            stopCapture();
//                //-->delete m_capImage;
//            //printf("\nwiDth=%d\n",wiDth);

//            qDebug()<<"buzz on in 5 sec    ##########################################################";
//           gl11_buzz_on();
//           sleep(5);
//           gl11_buzz_off();
//            qDebug()<<"buzz off in 5 sec    ##########################################################";


//   m_capImage->scaled(QSize(1280,720), Qt::IgnoreAspectRatio).save("/tmp/test.jpeg","JPEG",70);            sleep(2);
//            unsetCursor();

//            qDebug("close Press");
//            setCursor(Qt::WaitCursor);
//            stopCapture();
//                //-->delete m_capImage;
//            //printf("\nwiDth=%d\n",wiDth);
//        //    m_capImage->scaled(QSize(1280,720), Qt::IgnoreAspectRatio).save("/tmp/test.jpeg","JPEG",70);
//            sleep(2);
//            unsetCursor();
//          //  startCapture(m_capSrcFormat.fmt.pix.sizeimage);



//            qDebug("Close Press");
//            delete m_capNotifier;
//            m_capNotifier = NULL;
//            ::close(m_fd);
//            sleep(2);
//            delete m_capImage;
//            this->close();
//           // startCapture(m_capSrcFormat.fmt.pix.sizeimage);
//            break;

//        }
// }

//void ApplicationWindow::keyPressEvent(QKeyEvent *ke)
//{
//        int keyVal = ke->key();
//	qDebug("KeyPressEvent");
//        qDebug("keyEvent=%d",keyVal);

//qDebug("in keyEvent");

//	switch(keyVal)
//        {
//		case 16777220:
//                     g_mw->close();
//	            /* delete g_mw;
//			g_mw=NULL; */
//		    system("./fswebcam -S 2 -d /dev/video0 -r 680x680 --no-banner -save /root/Photos/test.jpeg ");
//                    break;

//        }

//}
ApplicationWindow *g_mw;

