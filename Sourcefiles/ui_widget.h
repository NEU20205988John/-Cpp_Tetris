/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *Close_Window_button;
    QWidget *horizontalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SinglePlayer_game_button;
    QPushButton *DuoPlayer_game_button;
    QPushButton *BGM_button;
    QPushButton *CheckHistoryrecord_button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 600);
        Widget->setBaseSize(QSize(960, 960));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 330, 401, 211));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        Close_Window_button = new QPushButton(Widget);
        Close_Window_button->setObjectName(QString::fromUtf8("Close_Window_button"));
        Close_Window_button->setGeometry(QRect(440, 0, 161, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        Close_Window_button->setFont(font1);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 281, 261));
        verticalLayout = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SinglePlayer_game_button = new QPushButton(horizontalLayoutWidget);
        SinglePlayer_game_button->setObjectName(QString::fromUtf8("SinglePlayer_game_button"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        SinglePlayer_game_button->setFont(font2);
        SinglePlayer_game_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(SinglePlayer_game_button);

        DuoPlayer_game_button = new QPushButton(horizontalLayoutWidget);
        DuoPlayer_game_button->setObjectName(QString::fromUtf8("DuoPlayer_game_button"));
        DuoPlayer_game_button->setFont(font2);
        DuoPlayer_game_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(DuoPlayer_game_button);




        BGM_button = new QPushButton(horizontalLayoutWidget);
        BGM_button->setObjectName(QString::fromUtf8("BGM_button"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Consolas"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        BGM_button->setFont(font3);

        verticalLayout->addWidget(BGM_button);

        CheckHistoryrecord_button = new QPushButton(horizontalLayoutWidget);
        CheckHistoryrecord_button->setObjectName(QString::fromUtf8("CheckHistoryrecord_button"));
        CheckHistoryrecord_button->setFont(font2);

        verticalLayout->addWidget(CheckHistoryrecord_button);


        retranslateUi(Widget);
        QObject::connect(Close_Window_button, SIGNAL(clicked(bool)), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Tetris", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Hello,World!", nullptr));
        Close_Window_button->setText(QCoreApplication::translate("Widget", "Close", nullptr));
        SinglePlayer_game_button->setText(QCoreApplication::translate("Widget", "\345\215\225\344\272\272\346\270\270\346\210\217", nullptr));
        DuoPlayer_game_button->setText(QCoreApplication::translate("Widget", "\345\217\214\344\272\272\346\270\270\346\210\217", nullptr));
        BGM_button->setText(QCoreApplication::translate("Widget", "BGM", nullptr));
        CheckHistoryrecord_button->setText(QCoreApplication::translate("Widget", "\346\237\245\347\234\213\345\216\206\345\217\262\346\246\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
