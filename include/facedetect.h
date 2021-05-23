#ifndef FACEDETECT_H
#define FACEDETECT_H

#include <QtGui>
#include <QString>
#include <QVector>
#include <QRect>
#include<QWidget>
#include <QTimer>
//#include <cv.h>
//#ifdef LIBQT
#include "opencv/cv.h"
#include "opencv/highgui.h"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#if 0
#ifdef LIBGNOME
#include "opencv/cv.h"
#include "opencv/highgui.h"


#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#endif
#endif

//dlib libraries
#if 0
#include </root/dlib-master/dlib/opencv.h>
#include </root/dlib-master/dlib/opencv/cv_image.h>
#include </root/dlib-master/dlib/image_loader/load_image.h>
#include <opencv2/highgui/highgui.hpp>
#include </root/dlib-master/dlib/image_processing/frontal_face_detector.h>
#include </root/dlib-master/dlib/image_processing/render_face_detections.h>
#include </root/dlib-master/dlib/image_processing.h>
#include </root/dlib-master/dlib/gui_widgets.h>
#include "/root/dlib-master/dlib/image_saver/image_saver.h"
#include "/root/dlib-master/dlib/gui_widgets/widgets.h"
#include "/root/dlib-master/dlib/image_io.h"
#include "/root/dlib-master/dlib/geometry/rectangle.h"
#include "/root/dlib-master/dlib/geometry.h"
//#include "/root/dlib-master/dlib/python/numpy.h"

#include "/home/mounika/dlib/opencv.h"
#include "/home/mounika/dlib/image_loader/load_image.h"
#include "opencv2/highgui/highgui.hpp"
#include "/home/mounika/dlib/image_processing/frontal_face_detector.h"
#include "/home/mounika/dlib/image_processing/render_face_detections.h"
#include "/home/mounika/dlib/image_processing.h"
#include "/home/mounika/dlib/gui_widgets.h"
#include "/home/mounika/dlib/image_saver/image_saver.h"
#include "/home/mounika/dlib/gui_widgets/widgets.h"
#include "/home/mounika/dlib/image_io.h"
#include "/home/mounika/dlib/geometry/rectangle.h"
#include "/home/mounika/dlib/geometry.h"
#include "/home/mounika/dlib/opencv/cv_image.h"

#endif
//using namespace dlib;

class FaceDetect {
public:
    FaceDetect();
    ~FaceDetect();



    void setCascadeFile(QString cascadeFile);
    QString cascadeName() const;
    void setFlags(int flags);
    QVector<QRect> detectFaces(IplImage *cvImage);
    CvRect region;
    IplImage *faceImage;
    void dlibDetectEyes(cv::Mat );

    cv::Rect facesdetect(IplImage *cImg);

   // dlib::frontal_face_detector detector;
   //  dlib::shape_predictor pose_model;


private:
  //  CvHaarClassifierCascade *cascade;
    cv::CascadeClassifier cascade;
    CvMemStorage *storage;
    int flags;
    QString cascadeFile;
    QTimer saveTimer;
    CvSize size;




//    void saveByClick();
};

#endif // FACEDETECT_H
