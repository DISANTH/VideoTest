//#ifndef LANDMARKDETECTION_H
//#define LANDMARKDETECTION_H
//#if 0
//#include </root/dlib-master/dlib/opencv.h>
//#include </root/dlib-master/dlib/opencv/cv_image.h>
//#include </root/dlib-master/dlib/image_loader/load_image.h>
//#include <opencv2/highgui/highgui.hpp>
//#include </root/dlib-master/dlib/image_processing/frontal_face_detector.h>
//#include </root/dlib-master/dlib/image_processing/render_face_detections.h>
//#include </root/dlib-master/dlib/image_processing.h>
//#include </root/dlib-master/dlib/gui_widgets.h>
//#include "/root/dlib-master/dlib/image_saver/image_saver.h"
//#include "/root/dlib-master/dlib/gui_widgets/widgets.h"
//#include "/root/dlib-master/dlib/image_io.h"
//#endif
//#include "/home/mounika/dlib/opencv.h"
//#include "/home/mounika/dlib/image_loader/load_image.h"
//#include "opencv2/highgui/highgui.hpp"
//#include "/home/mounika/dlib/image_processing/frontal_face_detector.h"
//#include "/home/mounika/dlib/image_processing/render_face_detections.h"
//#include "/home/mounika/dlib/image_processing.h"
//#include "/home/mounika/dlib/gui_widgets.h"
//#include "/home/mounika/dlib/image_saver/image_saver.h"
//#include "/home/mounika/dlib/gui_widgets/widgets.h"
//#include "/home/mounika/dlib/image_io.h"
//#include "/home/mounika/dlib/geometry/rectangle.h"
//#include "/home/mounika/dlib/geometry.h"
//#include "/home/mounika/dlib/opencv/cv_image.h"

////#include "face_utils.hpp"
////#include "precomp.hpp"
//#include "videodevice.h"
//#include "opencv/cv.h"
//#include "opencv/highgui.h"
//#include <QImage>
//#include "thread.h"
//#include "showthread.h"
//#include <QWidget>
//#include <QTimer>
//#include "facedetect.h"

//class landmarkDetection;

//class landmarkDetection : public QWidget
//{
//    Q_OBJECT
//public:
//    landmarkDetection(QWidget *parent=0);
//    ~landmarkDetection();
//FaceDetect faceDetect;
//    QTimer *timer1;
//double compute_EAR(std::vector<cv::Point> vec);
//     dlib::frontal_face_detector detector;
//     dlib::shape_predictor pose_model;
//     dlib::image_window win;
//        VideoDevice *vd;
//        uchar *pp;
//        uchar * p;
//        unsigned int len;
//        QImage *frame;
//        IplImage *cvimg;
//         int rs;
//        void convert_qimage_to_iplimage(QImage* qImage,IplImage* cvimg);
//        //cv::Mat resize1(cv::Mat img, int width, int height, cv::InterpolationFlags);

//    private :
//        friend class Thread;
//        Thread *paintThread;
//        friend class showThread;
//        showThread *showthread;
//        int convert_yuv_to_rgb_pixel(int y, int u, int v);
//        int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);
//       // frontal_face_detector detector;
//    private slots:
//          void LandMarkDetection();
//      void showFrame();
//      void DisplayBlinkMessage();
//       void DisplayCapturedMessage();
//       //   void paintEvent();
//signals:
//      void mesgsignal();
//      void capsignal();

//};

//#endif // LANDMARKDETECTION_H
