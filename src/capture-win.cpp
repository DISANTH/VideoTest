#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <QLabel>
#include <QImage>
#include <QTimer>
#include <QVBoxLayout>
#include <QCloseEvent>

#include "qv4l2.h"
#include "capture-win.h"

CaptureWin::CaptureWin()
{

    //qDebug("in CaptureWin  Constructor");

    QVBoxLayout *vbox = new QVBoxLayout(this);
    m_frame = 0;
    m_label = new QLabel();
    m_msg = new QLabel("No frame");
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    vbox->addWidget(m_label);
 //   vbox->addWidget(m_msg);
}

void CaptureWin::setImage(const QImage &image, bool init)
{
   // qDebug("in SetImage fun");
    m_label->setPixmap(QPixmap::fromImage(image));
    if (init) {
        m_frame = m_lastFrame = m_fps = 0;
        m_msg->setText("No frame");
    } else {
        if (m_frame == 0) {
            //	m_timer->start(20000);
            m_timer->start(100);
        }
        m_msg->setText(QString("Frame: %1 Fps: %2")
                       .arg(++m_frame).arg(m_fps));
    }
}

void CaptureWin::stop()
{
    //qDebug("in CAPWIN::stop");
    m_timer->stop();
}

void CaptureWin::update()
{

    //qDebug("in capwin::update");
    m_fps = (m_frame - m_lastFrame + 1) / 2;
    m_lastFrame = m_frame;
}

void CaptureWin::closeEvent(QCloseEvent *event)
{
    //qDebug("in capwin::closeevent");
    QWidget::closeEvent(event);
    emit close();
}
