/********************************************************************************
** Form generated from reading UI file 'bgm_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BGM_MAINWINDOW_H
#define UI_BGM_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BGM_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnClear;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSound;
    QSlider *sliderVolumn;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabCurMedia;
    QSlider *sliderPosition;
    QLabel *LabRatio;

    void setupUi(QMainWindow *BGM_MainWindow)
    {
        if (BGM_MainWindow->objectName().isEmpty())
            BGM_MainWindow->setObjectName(QString::fromUtf8("BGM_MainWindow"));
        BGM_MainWindow->resize(1000, 400);
        centralWidget = new QWidget(BGM_MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/316.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        horizontalLayout_3->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/318.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon1);

        horizontalLayout_3->addWidget(btnRemove);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/214.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon2);

        horizontalLayout_3->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout_3);

        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnPlay = new QPushButton(centralWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon3);

        horizontalLayout->addWidget(btnPlay);

        btnPause = new QPushButton(centralWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon4);

        horizontalLayout->addWidget(btnPause);

        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon5);

        horizontalLayout->addWidget(btnStop);

        btnPrevious = new QPushButton(centralWidget);
        btnPrevious->setObjectName(QString::fromUtf8("btnPrevious"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/616.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevious->setIcon(icon6);

        horizontalLayout->addWidget(btnPrevious);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("images/630.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon7);

        horizontalLayout->addWidget(btnNext);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSound = new QPushButton(centralWidget);
        btnSound->setObjectName(QString::fromUtf8("btnSound"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound->setIcon(icon8);
        btnSound->setFlat(true);

        horizontalLayout->addWidget(btnSound);

        sliderVolumn = new QSlider(centralWidget);
        sliderVolumn->setObjectName(QString::fromUtf8("sliderVolumn"));
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolumn);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LabCurMedia = new QLabel(centralWidget);
        LabCurMedia->setObjectName(QString::fromUtf8("LabCurMedia"));
        LabCurMedia->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(LabCurMedia);

        sliderPosition = new QSlider(centralWidget);
        sliderPosition->setObjectName(QString::fromUtf8("sliderPosition"));
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderPosition);

        LabRatio = new QLabel(centralWidget);
        LabRatio->setObjectName(QString::fromUtf8("LabRatio"));
        LabRatio->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(LabRatio);


        verticalLayout_2->addLayout(horizontalLayout_2);

        BGM_MainWindow->setCentralWidget(centralWidget);

        retranslateUi(BGM_MainWindow);

        QMetaObject::connectSlotsByName(BGM_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BGM_MainWindow)
    {
        BGM_MainWindow->setWindowTitle(QCoreApplication::translate("BGM_MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BGM_MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        btnAdd->setText(QCoreApplication::translate("BGM_MainWindow", "\346\267\273\345\212\240", nullptr));
        btnRemove->setText(QCoreApplication::translate("BGM_MainWindow", "\347\247\273\351\231\244", nullptr));
        btnClear->setText(QCoreApplication::translate("BGM_MainWindow", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        btnPlay->setToolTip(QCoreApplication::translate("BGM_MainWindow", "\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPlay->setText(QCoreApplication::translate("BGM_MainWindow", "Play", nullptr));
#if QT_CONFIG(tooltip)
        btnPause->setToolTip(QCoreApplication::translate("BGM_MainWindow", "\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPause->setText(QCoreApplication::translate("BGM_MainWindow", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        btnStop->setToolTip(QCoreApplication::translate("BGM_MainWindow", "\345\201\234\346\255\242", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStop->setText(QCoreApplication::translate("BGM_MainWindow", "Stop", nullptr));
#if QT_CONFIG(tooltip)
        btnPrevious->setToolTip(QCoreApplication::translate("BGM_MainWindow", "\345\211\215\344\270\200\346\233\262\347\233\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrevious->setText(QCoreApplication::translate("BGM_MainWindow", "Previous", nullptr));
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("BGM_MainWindow", "\344\270\213\344\270\200\346\233\262\347\233\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QCoreApplication::translate("BGM_MainWindow", "Next", nullptr));
        btnSound->setText(QString());
        LabCurMedia->setText(QCoreApplication::translate("BGM_MainWindow", "\346\227\240\346\233\262\347\233\256", nullptr));
        LabRatio->setText(QCoreApplication::translate("BGM_MainWindow", "\350\277\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BGM_MainWindow: public Ui_BGM_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BGM_MAINWINDOW_H
