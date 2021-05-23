
#ifndef QV4L2_H
#define QV4L2_H

#include <QMainWindow>
#include <QTabWidget>
#include <QSignalMapper>
#include <QLabel>
#include <QGridLayout>
#include <QSocketNotifier>
#include <QImage>
#include <map>
#include <vector>
#include <QShortcut>
#include "v4l2-api.h"
#include <QTimer>
#include <QDebug>
#include "thread.h"


#include "facedetect.h"
#include "compheader.h"

//#ifdef LIBQT
//FOR IMX-25QT

#include <QPainter>
#include <QPen>
#include <QMenuBar>
#include <QMenu>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class QComboBox;
class QSpinBox;
class GeneralTab;
class QCloseEvent;
class CaptureWin;


typedef std::vector<unsigned> ClassIDVec;
typedef std::map<unsigned, ClassIDVec> ClassMap;
typedef std::map<unsigned, struct v4l2_queryctrl> CtrlMap;
typedef std::map<unsigned, QWidget *> WidgetMap;

enum {
    CTRL_UPDATE_ON_CHANGE = 0x10,
    CTRL_DEFAULTS,
    CTRL_REFRESH,
    CTRL_UPDATE
};

enum CapMethod {
    methodRead,
    methodMmap,
    methodUser
};

struct buffer {
    void   *start;
    size_t  length;
};


class ApplicationWindow: public QMainWindow, public v4l2
{
    Q_OBJECT

public:
    ApplicationWindow();
  //  virtual ~ApplicationWindow();
    QTimer *qtime;
    FaceDetect faceDetect;
    QTimer *timer1;
    IplImage* QImageToIplImage(const QImage * qImage);
    IplImage* convertToIplImage(QImage *qImage);
    void convert_qimage_to_iplimage(QImage* qImage,IplImage* cvimg);

  double compute_EAR(std::vector<cv::Point> vec);
#if 1
    // dlib::frontal_face_detector detector;

    // dlib::shape_predictor pose_model;
#endif

    double right_ear;
    double left_ear;
    std::vector<cv::Point> righteye1;
    std::vector<cv::Point> lefteye1;

    void DisplayPopup();
signals :
    void Photocapturing();
    //void timeoutSignal();

private slots:
    void closeDevice();
    void closeCaptureWin();
    void ShowImage();


public:
    void setDevice(const QString &device, bool rawOpen);
    void setCheck();
    cv::Rect rectList;
   QProgressBar *probar;

    // capturing
private:
    IplImage *charIplImageBuffer;
    //  double compute_EAR(std::vector<cv::Point> vec);
    CaptureWin *m_capture;
    bool startCapture(unsigned buffer_size);
    void stopCapture();
    void startOutput(unsigned buffer_size);
    void stopOutput();
    struct buffer *m_buffers;
    struct v4l2_format m_capSrcFormat;
    struct v4l2_format m_capDestFormat;
    unsigned char *m_frameData;
    unsigned m_nbuffers;
    struct v4lconvert_data *m_convertData;
    CapMethod m_capMethod;

    friend class Thread;
    Thread *paintThread;
    Thread *paintThread1;
//    QDialog *Dlg;

    IplImage *cvimg;
    IplImage *cvsaveimg;
    IplImage *cvsaveimg_final;
    IplImage *tmp;
     IplImage *cvsaveimg1;

//      QProgressBar *probar;

     QAction *quitAct;

public slots:
    void capStart(bool);
    void capFrame();
    void paintEvent(QPaintEvent *);


public slots:
    void closeApp();
     //void closeApp1();
   // int closepop();
      void LCD_ON();

    // gui
private slots:
    //void opendev();
    void openrawdev();
    void ctrlAction(int);

    void about();
    void sample();
    void paintRun();
    void paintRun1();
public:
    virtual void error(const QString &text);
    void error(int err);
    void errorCtrl(unsigned id, int err);
    void errorCtrl(unsigned id, int err, long long v);
    void info(const QString &info);
    virtual void closeEvent(QCloseEvent *event);
    void takePhoto();

//    QLabel *processing_show(QString str);




private:
    void addWidget(QGridLayout *grid, QWidget *w, Qt::Alignment align = Qt::AlignLeft);
    void addLabel(QGridLayout *grid, const QString &text, Qt::Alignment align = Qt::AlignRight)
    {
        addWidget(grid, new QLabel(text, parentWidget()), align);
    }
    void addTabs();
    void finishGrid(QGridLayout *grid, unsigned ctrl_class);
    void addCtrl(QGridLayout *grid, const struct v4l2_queryctrl &qctrl);
    void updateCtrl(unsigned id);
    void refresh(unsigned ctrl_class);
    void setDefaults(unsigned ctrl_class);
    int getVal(unsigned id);
    long long getVal64(unsigned id);
    void setVal(unsigned id, int v);
    void setVal64(unsigned id, long long v);
    QString getCtrlFlags(unsigned flags);
    void setWhat(QWidget *w, unsigned id, long long v);
    void updateVideoInput();
    void updateVideoOutput();
    void updateAudioInput();
    void updateAudioOutput();
    void updateStandard();
    void updateFreq();
    void updateFreqChannel();

    GeneralTab *m_genTab;
    //	QAction *m_capStartAct;
    QString m_filename;
    QSignalMapper *m_sigMapper;
    QTabWidget *m_tabs;
    QSocketNotifier *m_capNotifier;
    QImage *m_capImage;
    int m_row, m_col, m_cols;
    CtrlMap m_ctrlMap;
    WidgetMap m_widgetMap;
    ClassMap m_classMap;
protected:
 //  void keyPressEvent(QKeyEvent *ke);
};

extern ApplicationWindow *g_mw;


class FaceDetectThread : public QThread
{
    Q_OBJECT
public:
    explicit FaceDetectThread(QObject *parent = 0) : QThread(parent){}

protected:
    void run();
signals:
    void sigtest();
    void sigtest1();
    void keyString();

};

#endif
