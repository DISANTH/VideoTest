//#include "landmarkdetection.h"
//extern int blinkFlag,eyeClosedFlag;

//landmarkDetection::landmarkDetection(QWidget *parent):QWidget(parent)
//{

//    //    shape_predictor pose_model;
//        dlib::deserialize("/home/shape_predictor_68_face_landmarks.dat") >> pose_model;
//        detector = dlib::get_frontal_face_detector();
//     //   deserialize("/home/shape_predictor_68_face_landmarks.dat") >> pose_model;

//        pp = (unsigned char *)malloc(WIDTH * HEIGHT/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
//        frame = new QImage(pp,WIDTH,HEIGHT,QImage::Format_RGB888);
//       // QfaceImage = new QImage;

//        int width = frame->width();
//        int height = frame->height();
//        CvSize Size;
//        Size.height = height;
//        Size.width = width;

//          cvimg = cvCreateImage(Size, IPL_DEPTH_8U, 3);

//        vd = new VideoDevice("/dev/video2");


//    //    connect(vd, SIGNAL(display_error(QString)), this,SLOT(display_error(QString)));
//        rs = vd->open_device();
//        if(-1==rs)
//        {
//            QMessageBox::warning(this,"error","open /dev/dsp error",QMessageBox::Yes);
//            vd->close_device();
//        }

//        rs = vd->init_device();
//        if(-1==rs)
//        {
//            QMessageBox::warning(this,"error","init failed",QMessageBox::Yes);
//            vd->close_device();
//        }

//        rs = vd->start_capturing();
//        if(-1==rs)
//        {
//            QMessageBox::warning(this,"error","start capture failed",QMessageBox::Yes);
//            vd->close_device();
//        }

//        if(-1==rs)
//        {
//            QMessageBox::warning(this,"error","get frame failed",QMessageBox::Yes);
//            vd->stop_capturing();
//        }

//        paintThread = new Thread;
//         connect(paintThread,SIGNAL(sigtest() ),this,SLOT(LandMarkDetection()),Qt::DirectConnection);



//         paintThread->start();

//        showthread = new showThread;
//         connect(showthread,SIGNAL(showsigtest() ),this,SLOT(showFrame()),Qt::DirectConnection);
//          connect(showthread,SIGNAL(mesgsignal() ),this,SLOT(DisplayBlinkMessage()),Qt::DirectConnection);
//          connect(showthread,SIGNAL(capsignal() ),this,SLOT(DisplayCapturedMessage()),Qt::DirectConnection);
//         showthread->start();

//}
//void landmarkDetection::DisplayBlinkMessage()
//{
//    qDebug()<<"...........................................";
//    QMessageBox msgBox;
//    //msgBox.setParent(win);
//    msgBox.setStyleSheet("background-color:rgb(145,45,232)");
//    //msgBox.setWindowFlags(Qt::FramelessWindowHint);
//    msgBox.setText("<b><font size=4 >Please Blink The Eye</font></b>");
//    msgBox.setStandardButtons(QMessageBox::Ok);
//    //QTimer::singleShot(1000, &msgBox, SLOT(close()));
//    msgBox.exec();
//}

//void landmarkDetection::DisplayCapturedMessage()
//{
//    QMessageBox msgBox;
//    msgBox.setParent(this);
//    msgBox.setStyleSheet("background-color:rgb(145,45,232)");
//    msgBox.setWindowFlags(Qt::FramelessWindowHint);
//    msgBox.setText("<b><font size=4 >EYES BLINKED</font></b>");
//    msgBox.setStandardButtons(QMessageBox::Ok);
//   // QTimer::singleShot(1000, &msgBox, SLOT(close()));
//    msgBox.exec();
//}

//void landmarkDetection::showFrame()
//{

//    system("date");
//    qDebug()<<"Inside Landmark detection";
//#if 0
//        rs = vd->get_frame((void **)&p,&len);
//    qDebug()<<"1";
//        convert_yuv_to_rgb_buffer(p,pp,WIDTH,HEIGHT/*QWidget::width(),QWidget::height()*/);
//    qDebug()<<"2";
//        frame->loadFromData((uchar *)pp,/*len*/WIDTH * HEIGHT * 3 * sizeof(char));
//        qDebug()<<"2";

//        convert_qimage_to_iplimage(frame,cvimg);
//#endif
//        faceDetect.region.width=0;
//        faceDetect.region.height=0;
//        faceDetect.detectFaces(cvimg);

//        qDebug()<<"face width"<<faceDetect.region.width<<"face height"<<faceDetect.region.height;
//        if(faceDetect.region.width > 100 && faceDetect.region.height > 100)
//        {
////            win.clear_overlay();
////            win.set_image(cimg);

//            std::vector<cv::Point> righteye;
//            std::vector<cv::Point> lefteye;
//            cv::Point cvp;
//            cv::Mat temp1 =  cv::cvarrToMat(cvimg);
//            dlib::cv_image<dlib::bgr_pixel> cimg(temp1);

//            qDebug()<<"================Inside FACEDETECT";
//       // cv::Mat temp =  cv::cvarrToMat(faceDetect.faceImage);
//        qDebug()<<"after Mat";
//       // dlib::cv_image<unsigned char> cimg(temp);
//              //  dlib::array2d<unsigned char> dlibImage;
//             //   dlib::assign_image(dlibImage, dlib::cv_image<unsigned char>(temp));
//       //cv::Mat temp = cv::cvarrToMat(cvimg);
//        dlib::full_object_detection shapes;
//       // std::vector<dlib::rectangle>faces ;
//        qDebug()<<"before shapes";
//      //   for (unsigned long i = 0; i < faces.size(); ++i)

//        dlib::rectangle r(int(faceDetect.region.x), int(faceDetect.region.y), int(faceDetect.region.x + faceDetect.region.width), int(faceDetect.region.y + faceDetect.region.height));
//       long dlibx=r.left();//x
//       long dliby= r.right();//y
//       long dlibw = r.bottom();
//       long dlibh = r.top();
//       qDebug()<<"dlibx"<<dlibx<<"dliby"<<dliby<<"dlibw"<<dlibw<<"dlibh"<<dlibh;


//       shapes = pose_model(cimg,r);
//       win.clear_overlay();
//       win.add_overlay(render_face_detections(shapes));

//       for (int b = 36; b < 42; b++)
//       {
//           qDebug()<<"............1---b==="<<b;
//           cvp.x = shapes.part(b).x();
//           cvp.y = shapes.part(b).y();
//           lefteye.push_back(cvp);
//       }
//       for (int b = 42; b < 48; b++)
//       {
//           qDebug()<<".........2..b==="<<b;
//           cvp.x = shapes.part(b).x();
//           cvp.y = shapes.part(b).y();
//           righteye.push_back(cvp);
//       }

//       //Compute Eye aspect ration for eyes
//       double right_ear = compute_EAR(righteye);
//       qDebug()<<"right_ear=="<<right_ear;
//       double left_ear = compute_EAR(lefteye);
//       qDebug()<<"left ear=="<<left_ear;
//        qDebug()<<"...................EAR RATIO................."<<(right_ear + left_ear) / 2;
////Added to check eye blinking with perfect ear ratio

//        if(blinkFlag==1)
//        {
//            if(eyeClosedFlag==1)
//            {
//                if((right_ear + left_ear)/2 > 0.3)
//                {
//                    qDebug()<<"Eyes Opened";
//                    //eyeClosedFlag=1;
//                    qDebug()<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ EYES BLINKED @@@@@@@@@@@@@@@@@";

//                    dlib::rectangle r1(5, 5, 3, 3);
//                   win.add_overlay(dlib::image_window::overlay_rect(r1, dlib::rgb_pixel(3, 121, 13), "EYES BLINKED"));
//                     sleep(2);
//                   cvSaveImage("/root/Captured.jpeg",faceDetect.faceImage);
//                     win.close_window();
//                   // emit capsignal();

//                }
//            }

//            if(eyeClosedFlag==0)
//            {
//                if((right_ear + left_ear)/2 < 0.25)
//                {
//                    qDebug()<<"..........................................................Eyes Closed";
//                    eyeClosedFlag=1;
//                }
//            }



////
//       //if the avarage eye aspect ratio of lef and right eye less than 0.2, the status is sleeping.

////       if ((right_ear + left_ear) / 2 > 0.3)
////           win.add_overlay(dlib::image_window::overlay_rect(r, dlib::rgb_pixel(255, 255, 255), "Not sleeping"));
////       else
////            win.add_overlay(dlib::image_window::overlay_rect(r, dlib::rgb_pixel(3, 121, 13), "Sleeping"));

////       righteye.clear();
////       lefteye.clear();

//       //qDebug()<<"face shapes size"<<shapes.size();
////       win.clear_overlay();
////       win.set_image(cimg);
// //      win.add_overlay(render_face_detections(shapes));
//     //  win.add_overlay(render_face_detections(shapes));

//        }
//    //    else
//    //    {

////            win.clear_overlay();
////            win.set_image(cimg);
//             //win.add_overlay(render_face_detections(shapes));
//     //   }


//    qDebug()<<"3";
//    system("date");
//    if(blinkFlag==0)
//    {
//     if((right_ear + left_ear)/2 >=0.3)
//     {
//         qDebug()<<"====================Please Blink the eye";
//         //QMessageBox::warning(this,"Message","Please Blink the eye",QMessageBox::Yes);


//          blinkFlag=1;
//           dlib::rectangle r1(5, 5, 3, 3);
//          win.add_overlay(dlib::image_window::overlay_rect(r1, dlib::rgb_pixel(3, 121, 13), "PLEASE BLINK EYES"));
//            sleep(2);
//          //win.add_overlay(dlib::image_window
//                         // (r, dlib::rgb_pixel(3, 121, 13), "Sleeping"));
//         //  emit mesgsignal();
//     }

//    }
//    righteye.clear();
//    lefteye.clear();

//  }
//}

//double landmarkDetection::compute_EAR(std::vector<cv::Point> vec)
//{

//    double a = cv::norm(cv::Mat(vec[1]), cv::Mat(vec[5]));
//    double b = cv::norm(cv::Mat(vec[2]), cv::Mat(vec[4]));
//    double c = cv::norm(cv::Mat(vec[0]), cv::Mat(vec[3]));
//    //compute EAR
//    double ear = (a + b) / (2.0 * c);
//    return ear;
//}

//void landmarkDetection::LandMarkDetection()
//{
//    rs = vd->get_frame((void **)&p,&len);
//    qDebug()<<"1";
//    convert_yuv_to_rgb_buffer(p,pp,WIDTH,HEIGHT/*QWidget::width(),QWidget::height()*/);
//    qDebug()<<"2";
//    frame->loadFromData((uchar *)pp,/*len*/WIDTH * HEIGHT * 3 * sizeof(char));
//    qDebug()<<"2";
//    convert_qimage_to_iplimage(frame,cvimg);
//    cv::Mat temp1 =  cv::cvarrToMat(cvimg);
//    dlib::cv_image<dlib::bgr_pixel> cimg(temp1);

//  //  win.clear_overlay();
//    win.set_image(cimg);

//    rs = vd->unget_frame();
//}

//int landmarkDetection::convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height)
//{
// unsigned int in, out = 0;
// unsigned int pixel_16;
// unsigned char pixel_24[3];
// unsigned int pixel32;
// int y0, u, y1, v;
// for(in = 0; in < width * height * 2; in += 4) {
//  pixel_16 =
//   yuv[in + 3] << 24 |
//   yuv[in + 2] << 16 |
//   yuv[in + 1] <<  8 |
//   yuv[in + 0];
//  y0 = (pixel_16 & 0x000000ff);
//  u  = (pixel_16 & 0x0000ff00) >>  8;
//  y1 = (pixel_16 & 0x00ff0000) >> 16;
//  v  = (pixel_16 & 0xff000000) >> 24;
//  pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
//  pixel_24[0] = (pixel32 & 0x000000ff);
//  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
//  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
//  rgb[out++] = pixel_24[0];
//  rgb[out++] = pixel_24[1];
//  rgb[out++] = pixel_24[2];
//  pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
//  pixel_24[0] = (pixel32 & 0x000000ff);
//  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
//  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
//  rgb[out++] = pixel_24[0];
//  rgb[out++] = pixel_24[1];
//  rgb[out++] = pixel_24[2];
// }
// return 0;
//}

//int landmarkDetection::convert_yuv_to_rgb_pixel(int y, int u, int v)
//{
// unsigned int pixel32 = 0;
// unsigned char *pixel = (unsigned char *)&pixel32;
// int r, g, b;
// r = y + (1.370705 * (v-128));
// g = y - (0.698001 * (v-128)) - (0.337633 * (u-128));
// b = y + (1.732446 * (u-128));
// if(r > 255) r = 255;
// if(g > 255) g = 255;
// if(b > 255) b = 255;
// if(r < 0) r = 0;
// if(g < 0) g = 0;
// if(b < 0) b = 0;
// pixel[0] = r * 220 / 256;
// pixel[1] = g * 220 / 256;
// pixel[2] = b * 220 / 256;
// return pixel32;
//}

//void landmarkDetection::convert_qimage_to_iplimage(QImage* qImage,IplImage* cvimg)
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

//landmarkDetection::~landmarkDetection()
//{

//}

