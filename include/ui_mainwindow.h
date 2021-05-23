/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Apr 26 17:39:49 2019
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDefault;
    QAction *actionAlt;
    QAction *actionAlt2;
    QAction *actionProfileface;
    QAction *actionUpperbody;
    QAction *actionFullbody;
    QAction *actionAbout;
    QAction *actionimageShow;
    QAction *actionFrom;
    QAction *actionClose;
    QAction *actionUnload;
    QAction *actionRest;
    QWidget *widget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu_View;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(465, 300);
        MainWindow->setMinimumSize(QSize(465, 300));
        MainWindow->setMaximumSize(QSize(16777215, 320));
        actionDefault = new QAction(MainWindow);
        actionDefault->setObjectName(QString::fromUtf8("actionDefault"));
        actionAlt = new QAction(MainWindow);
        actionAlt->setObjectName(QString::fromUtf8("actionAlt"));
        actionAlt2 = new QAction(MainWindow);
        actionAlt2->setObjectName(QString::fromUtf8("actionAlt2"));
        actionProfileface = new QAction(MainWindow);
        actionProfileface->setObjectName(QString::fromUtf8("actionProfileface"));
        actionUpperbody = new QAction(MainWindow);
        actionUpperbody->setObjectName(QString::fromUtf8("actionUpperbody"));
        actionFullbody = new QAction(MainWindow);
        actionFullbody->setObjectName(QString::fromUtf8("actionFullbody"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionimageShow = new QAction(MainWindow);
        actionimageShow->setObjectName(QString::fromUtf8("actionimageShow"));
        actionFrom = new QAction(MainWindow);
        actionFrom->setObjectName(QString::fromUtf8("actionFrom"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionUnload = new QAction(MainWindow);
        actionUnload->setObjectName(QString::fromUtf8("actionUnload"));
        actionRest = new QAction(MainWindow);
        actionRest->setObjectName(QString::fromUtf8("actionRest"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        MainWindow->setCentralWidget(widget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 465, 20));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_View->menuAction());
        menu_View->addAction(actionimageShow);
        menu_View->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Face Recognition", 0, QApplication::UnicodeUTF8));
        actionDefault->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        actionAlt->setText(QApplication::translate("MainWindow", "Alt", 0, QApplication::UnicodeUTF8));
        actionAlt2->setText(QApplication::translate("MainWindow", "Alt2", 0, QApplication::UnicodeUTF8));
        actionProfileface->setText(QApplication::translate("MainWindow", "Profileface", 0, QApplication::UnicodeUTF8));
        actionUpperbody->setText(QApplication::translate("MainWindow", "Upperbody", 0, QApplication::UnicodeUTF8));
        actionFullbody->setText(QApplication::translate("MainWindow", "Fullbody", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionimageShow->setText(QApplication::translate("MainWindow", "&ShowImage", 0, QApplication::UnicodeUTF8));
        actionFrom->setText(QApplication::translate("MainWindow", "From...", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "&CLOSE", 0, QApplication::UnicodeUTF8));
        actionUnload->setText(QApplication::translate("MainWindow", "&Unload", 0, QApplication::UnicodeUTF8));
        actionRest->setText(QApplication::translate("MainWindow", "&Reset", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
