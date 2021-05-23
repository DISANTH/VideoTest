/********************************************************************************
** Form generated from reading UI file 'FaceAuthentication.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEAUTHENTICATION_H
#define UI_FACEAUTHENTICATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceAuthentication
{
public:
    QPushButton *firstImgBtn;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;

    void setupUi(QWidget *FaceAuthentication)
    {
        if (FaceAuthentication->objectName().isEmpty())
            FaceAuthentication->setObjectName(QString::fromUtf8("FaceAuthentication"));
        FaceAuthentication->resize(320, 240);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        FaceAuthentication->setFont(font);
        FaceAuthentication->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);"));
        firstImgBtn = new QPushButton(FaceAuthentication);
        firstImgBtn->setObjectName(QString::fromUtf8("firstImgBtn"));
        firstImgBtn->setGeometry(QRect(30, 90, 91, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        firstImgBtn->setFont(font1);
        label_4 = new QLabel(FaceAuthentication);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 321, 20));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(FaceAuthentication);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 80, 91, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        progressBar = new QProgressBar(FaceAuthentication);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(80, 190, 118, 23));
        progressBar->setValue(24);

        retranslateUi(FaceAuthentication);

        QMetaObject::connectSlotsByName(FaceAuthentication);
    } // setupUi

    void retranslateUi(QWidget *FaceAuthentication)
    {
        FaceAuthentication->setWindowTitle(QApplication::translate("FaceAuthentication", "Form", 0, QApplication::UnicodeUTF8));
        firstImgBtn->setText(QApplication::translate("FaceAuthentication", "ENROLL", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FaceAuthentication", "<html><head/><body><p align=\"center\">FACE CAPTURE</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("FaceAuthentication", "CLOSE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FaceAuthentication: public Ui_FaceAuthentication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEAUTHENTICATION_H
