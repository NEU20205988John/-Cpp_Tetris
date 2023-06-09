/********************************************************************************
** Form generated from reading UI file 'gameover_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_WIDGET_H
#define UI_GAMEOVER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameover_widget
{
public:
    QTextEdit *textEdit;
    QLabel *Label2_2;
    QLabel *Label1;
    QLabel *scoreLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *gameover_widget)
    {
        if (gameover_widget->objectName().isEmpty())
            gameover_widget->setObjectName(QString::fromUtf8("gameover_widget"));
        gameover_widget->resize(400, 200);
        textEdit = new QTextEdit(gameover_widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 60, 191, 31));
        Label2_2 = new QLabel(gameover_widget);
        Label2_2->setObjectName(QString::fromUtf8("Label2_2"));
        Label2_2->setGeometry(QRect(10, 40, 271, 21));
        Label1 = new QLabel(gameover_widget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(10, 10, 221, 21));
        scoreLabel = new QLabel(gameover_widget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(240, 10, 81, 21));
        pushButton = new QPushButton(gameover_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 110, 80, 20));

        retranslateUi(gameover_widget);

        QMetaObject::connectSlotsByName(gameover_widget);
    } // setupUi

    void retranslateUi(QWidget *gameover_widget)
    {
        gameover_widget->setWindowTitle(QCoreApplication::translate("gameover_widget", "GameOver!", nullptr));
        Label2_2->setText(QCoreApplication::translate("gameover_widget", "\350\257\267\350\276\223\345\205\245\346\230\265\347\247\260\357\274\232(\344\273\205\345\214\205\345\220\253\351\235\236\344\270\255\346\226\207\345\255\227\347\254\246)", nullptr));
        Label1->setText(QCoreApplication::translate("gameover_widget", "Game Over! Your Score is:", nullptr));
        scoreLabel->setText(QCoreApplication::translate("gameover_widget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("gameover_widget", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameover_widget: public Ui_gameover_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_WIDGET_H
