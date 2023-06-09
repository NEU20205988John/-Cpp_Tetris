/********************************************************************************
** Form generated from reading UI file 'chr_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHR_MAINWINDOW_H
#define UI_CHR_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHR_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *TitileLabel;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuRanklist;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CHR_MainWindow)
    {
        if (CHR_MainWindow->objectName().isEmpty())
            CHR_MainWindow->setObjectName(QString::fromUtf8("CHR_MainWindow"));
        CHR_MainWindow->resize(1200, 1200);
        centralwidget = new QWidget(CHR_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TitileLabel = new QLabel(centralwidget);
        TitileLabel->setObjectName(QString::fromUtf8("TitileLabel"));
        TitileLabel->setGeometry(QRect(20, 0, 381, 121));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        TitileLabel->setFont(font);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 100, 300, 750));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft JhengHei"));
        font1.setPointSize(14);
        plainTextEdit->setFont(font1);
        plainTextEdit->setReadOnly(true);
        CHR_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CHR_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        menuRanklist = new QMenu(menubar);
        menuRanklist->setObjectName(QString::fromUtf8("menuRanklist"));
        CHR_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CHR_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CHR_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuRanklist->menuAction());

        retranslateUi(CHR_MainWindow);

        QMetaObject::connectSlotsByName(CHR_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CHR_MainWindow)
    {
        CHR_MainWindow->setWindowTitle(QCoreApplication::translate("CHR_MainWindow", "MainWindow", nullptr));
        TitileLabel->setText(QCoreApplication::translate("CHR_MainWindow", "\345\210\206\346\225\260\346\216\222\350\241\214\346\246\234", nullptr));
        menuRanklist->setTitle(QCoreApplication::translate("CHR_MainWindow", "Ranklist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHR_MainWindow: public Ui_CHR_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHR_MAINWINDOW_H
