#ifndef FACEAUTHENTICATION_H
#define FACEAUTHENTICATION_H

#include <QWidget>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <QtGui>

namespace Ui {
class FaceAuthentication;
}

class FaceAuthentication : public QWidget
{
    Q_OBJECT

public:
    explicit FaceAuthentication(QWidget *parent = 0);
    ~FaceAuthentication();


private:
    Ui::FaceAuthentication *ui;
};

#endif // FACEAUTHENTICATION_H
