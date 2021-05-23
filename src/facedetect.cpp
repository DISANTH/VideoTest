//#include <QtGui>
#include "facedetect.h"
#include "qwidget.h"
//int timeoutCount=0;
#include<QProgressBar>


FaceDetect::FaceDetect()
{
    qDebug()<<"FaceDetect Constructor";
    //cascadeFile = "haarcascade_frontalface_alt2.xml";//7sec
    //cascadeFile = "haarcascade_frontalface_alt.xml";//10sec
   // cascadeFile = "lbpcascade_frontalface.xml";
    //  cascadeFile = "aface.xml";
    // cascadeFile = "haarcascade_eye_tree_eyeglasses.xml";
    // cascadeFile =  "haarcascade_mcs_eyepair_small.xml";
    //cascadeFile = "haarcascade_righteye_2splits.xml";
    // cascadeFile = "haarcascade_profileface.xml";
  // cascade = (CvHaarClassifierCascade *) cvLoad(cascadeFile.toUtf8());
    flags = CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_DO_ROUGH_SEARCH;

    //

   // if(!cascade.load( "/usr/bin/haarcascade_frontalface_alt2.xml"))
        if(!cascade.load( "/root/lbpcascade_frontalface.xml"))
//    if(!cascade.load( "lbpcascade_frontalface.xml"))
     {
       std::cout << "Error during loading";
       //QMessageBox::information(this,"","cascade .xml file not found");
       exit(0);
     //  return -1;
     }


    //
    // Storage for the rectangles detected
    storage = cvCreateMemStorage(0);
    CvSize size;
    size.width = 70;
    size.height = 80;
    faceImage = cvCreateImage(size,IPL_DEPTH_8U,CV_8UC1);


    //
    //    shape_predictor pose_model;
    // dlib::deserialize("/home/shape_predictor_68_face_landmarks.dat") >> pose_model;
    //  detector = dlib::get_frontal_face_detector();

}

FaceDetect::~FaceDetect() {
   // if(cascade) cvReleaseHaarClassifierCascade(&cascade);
}


// Load a new classifier cascade, we unload first the previous classifier
void FaceDetect::setCascadeFile(QString cascadeFrom) {
    cascadeFile = cascadeFrom;
   // if(cascade) cvReleaseHaarClassifierCascade(&cascade);
   // cascade = (CvHaarClassifierCascade *) cvLoad(cascadeFile.toUtf8());
}

QString FaceDetect::cascadeName() const {
    return cascadeFile;
}

/* Possible values for flags on cvHaarDetectObjects. It can be a combination of zero or more of the following values:

        * CV_HAAR_SCALE_IMAGE- for each scale factor used the function will downscale the image rather than "zoom"
            the feature coordinates in the classifier cascade. Currently, the option can only be used alone,
            i.e. the flag can not be set together with the others.
        * CV_HAAR_DO_CANNY_PRUNING- If it is set, the function uses Canny edge detector to reject some image regions
            that contain too few or too much edges and thus can not contain the searched object. The particular
            threshold values are tuned for face detection and in this case the pruning speeds up the processing.
        * CV_HAAR_FIND_BIGGEST_OBJECT- If it is set, the function finds the largest object (if any) in the image.
            That is, the output sequence will contain one (or zero) element(s).
        * CV_HAAR_DO_ROUGH_SEARCH- It should be used only when CV_HAAR_FIND_BIGGEST_OBJECT is set and min_neighbors > 0.
            If the flag is set, the function does not look for candidates of a smaller size as soon as it has found the
            object (with enough neighbor candidates) at the current scale. Typically, when min_neighbors is fixed, the
            mode yields less accurate (a bit larger) object rectangle than the regular single-object mode
            (CV_HAAR_FIND_BIGGEST_OBJECT), but it is much faster, up to an order of magnitude. A greater value of
            min_neighbors may be specified to improve the accuracy.

Note, that in single-object mode CV_HAAR_DO_CANNY_PRUNING does not improve performance much and can even slow down the
processing. */



void FaceDetect::setFlags(int flagsFrom) {
    flags = flagsFrom;
}


//void FaceDetect::closeApp()
//{
//    stopCapture();
//   // paintThread->terminate();
//    g_mw->close();
//    /*	delete g_mw;
//    g_mw=NULL;*/
//    qDebug("closed");
//    close();


//}

cv::Rect FaceDetect::facesdetect(IplImage *cImg)
{
    QTime time;
    qDebug()<<"^^^^^FaceDetection Method Starting^^^^^"<<time.currentTime().toString("hh:mm:ss");
    cv::Rect obj1;
    cv::Mat matImage = cv::cvarrToMat(cImg);
   // cv::Mat picGray;
    //cv::cvtColor( matImage, picGray, CV_BGR2GRAY );
    std::vector<cv::Rect> objs;
    qDebug()<<"^^^^^Before Detect Multi Scale Method^^^^^"<<time.currentTime().toString("hh:mm:ss");
    //2sec-IMX25
    cascade.detectMultiScale(matImage, objs, 1.1, 1, CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_DO_ROUGH_SEARCH, cv::Size(200, 200) );
    qDebug()<<"^^^^^After Detect Multi Scale Method^^^^^"<<time.currentTime().toString("hh:mm:ss");
    qDebug()<<"::::::::::::::::"<<objs.empty();
    if(objs.empty())
    {
        qDebug()<<"OBJECTS DATA IS EMPTY";
        qDebug()<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Face Not Detected";
       /* timeoutCount++;
        qDebug()<<"timeout count value is"<<timeoutCount;
        if(timeoutCount==250)  // Automatic timeout if the image is not captuing till 10 sec
        {


                     //count4=0;
                   //emit timeoutSignal();
            QFont BtnFont("Times", 13, QFont::Bold);
          QLabel msg;

          msg.setText("Session Timeout!!");
          msg.setFont(BtnFont);
          msg.setGeometry(110,80,121,51);
          msg.setVisible(true);
       //timer_flag = 1;
          sleep(5);
          msg.setVisible(false);

          QCoreApplication::quit();

        }*/

    }
    else
    {

        obj1 = objs.at(0);
        qDebug()<<"-------Width"<<obj1.width<<"\n"<<"------Height"<<obj1.height;

    }
    qDebug()<<"^^^^^Before Return of FaceDetect^^^^^"<<time.currentTime().toString("hh:mm:ss");
    return obj1;
}

QVector<QRect> FaceDetect::detectFaces(IplImage *cvImage ) {
    QVector<QRect> listRect;
    CvRect *rect = NULL;
    double scale = 1.2;
#if 0
    QTime time;
qDebug()<<"^^^^^ FaceDetect STARTING^^^^^"<<time.currentTime().toString("hh:mm:ss");
    // Create a gray scale image (1 channel) to turn it into a small image that we send to cvHaarDetectObjects to process
  //IplImage *grayImage = cvCreateImage(cvSize(cvImage->width, cvImage->height), cvImage->depth, CV_8UC1);
    IplImage *smallImage = cvCreateImage(cvSize(cvRound(cvImage->width/scale), cvRound(cvImage->height/scale)),
                                         cvImage->depth, CV_8UC1);


    //cvCvtColor(cvImage, grayImage, CV_BGR2GRAY);
    cvResize(cvImage, smallImage);
    cvEqualizeHist(smallImage, smallImage);         // Grays smoothing (normaliza brillo, incrementa contraste)


    if(cascade) {
        qDebug()<<"Inside Cascade detect";
        // printf(">>>>>>>>>>>>>>>Inside detect ");
        // It isn't necessary in this context, because cascade exist if we reach this point
        qDebug()<<"----------------CvCreate image--------------";
        system("date");
        double timeElapsed = (double)cvGetTickCount();
        CvSeq *faces = cvHaarDetectObjects(smallImage, cascade, storage, scale, 0, flags, cvSize(170, 170),cvSize(200,200));
        timeElapsed = (double)cvGetTickCount() - timeElapsed;
        printf( "detection time = %g ms\n", timeElapsed/((double)cvGetTickFrequency()*1000) );
        //qDebug() << QString("detection time = %1").arg(timeElapsed/((double)cvGetTickFrequency()*1000));
        qDebug()<<"----------------CvCreate image-----After---------";
        system("date");
        if(faces->total==0)
        {
            blinkFlag=0;
            eyeClosedFlag=0;
        }
        for(int i = 0; i < faces->total; i++)
        {
            printf("INISDE FOR LOOP");
            rect = (CvRect*)cvGetSeqElem(faces, i);
            listRect.append(QRect(rect->x * scale, rect->y * scale, rect->width * scale, rect->height * scale));
            region = *rect;

            region.x = region.x*scale + 6;
            region.y = region.y*scale + 5;
            region.width = region.width*scale - 2*6;
            region.height = region.height*scale - 5;
            if (region.width < 1)
                region.width = 1;
            if (region.height < 1)
                region.height = 1;
            printf("%dX%d\n",region.width,region.height);
            //cvSetImageROI(smallImage,region);
            //            cvSaveImage("/root/mounika.jpeg",smallImage);
            //  cvResize(smallImage,faceImage,CV_INTER_AREA);
            //  cvEqualizeHist(faceImage,faceImage);
            qDebug()<<"After equalization";
            // Converting the OpenCV rectangle coordinates to Dlib rectangle
            // dlib_rect = dlib::rectangle(int(x), int(y), int(x + w), int(y + h));
#if 0
            dlib::rectangle r(int(region.x), int(region.y), int(region.x + region.width), int(region.y + region.height));
            long dlibx=r.left();//x
            long dliby= r.right();//y
            long dlibw = r.bottom();
            long dlibh = r.top();
            qDebug()<<"dlibx"<<dlibx<<"dliby"<<dliby<<"dlibw"<<dlibw<<"dlibh"<<dlibh;



            //                 cv::Mat MatinputImage = cv::cvarrToMat(smallImage);
            //             cv::imwrite("/root/Matimage.jpeg",MatinputImage);
            //cv::Rect rect1;

            //        dlibDetectEyes(MatinputImage);
#endif
        }
    }

    //cvReleaseImage(&grayImage);
   // cvReleaseImage(&smallImage);
    qDebug()<<"^^^^^ENDING FaceDetect^^^^^"<<time.currentTime().toString("hh:mm:ss");
#endif
    return listRect;
}


