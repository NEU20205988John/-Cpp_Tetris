/********************************************************************************
** Form generated from reading UI file 'duoplayermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUOPLAYERMAINWINDOW_H
#define UI_DUOPLAYERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DuoPlayerMainWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DuoPlayerMainWindow)
    {
        if (DuoPlayerMainWindow->objectName().isEmpty())
            DuoPlayerMainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        DuoPlayerMainWindow->resize(800, 600);
        menubar = new QMenuBar(DuoPlayerMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        DuoPlayerMainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(DuoPlayerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DuoPlayerMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DuoPlayerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DuoPlayerMainWindow->setStatusBar(statusbar);

        retranslateUi(DuoPlayerMainWindow);

        QMetaObject::connectSlotsByName(DuoPlayerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DuoPlayerMainWindow: public Ui_DuoPlayerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUOPLAYERMAINWINDOW_H
