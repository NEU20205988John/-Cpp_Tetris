#include "widget.h"
#include"mainwindow.h"
#include"bgm_mainwindow.h"
#include <QApplication>
#include<QDesktopServices>
#include<QTextCodec>
#include"duoplayermainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    Widget widget;
    widget.show();

    //MainWindow mainwindow;
    //DuoPlayerMainWindow duoplayermainwindow;
    //duoplayermainwindow.resize(1440,960);
    //BGM_MainWindow bgm_mainwindow;

    //mainwindow.show();

    return a.exec();
}
