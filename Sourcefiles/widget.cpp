#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include<QPainter>
#include<mainwindow.h>
#include"bgm_mainwindow.h"
#include<QPalette>
#include"ui_gameover_widget.h"
#include<iostream>
#include<fstream>
#include<QDir>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
 ui->setupUi(this);
     QDir d;
     d.cdUp();
     d.cd("./samp2_1/BackGroundPic");
     QString str = d.absolutePath();

    setPalette(QPalette(Qt::white));
    move(600,300);
    QPalette palette=this->palette();
    setAutoFillBackground(true);
    palette.setBrush(QPalette::Background,QBrush(QPixmap(str+"/2.jpg").scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    setPalette(palette); // 至此, 已给widget加上了背景图.
    connect(ui->SinglePlayer_game_button,&QPushButton::clicked,this,&Widget::open_new_mainwindown);
    connect(ui->BGM_button,&QPushButton::clicked,this,&Widget::open_new_bgm_mainwindown);
    connect(ui->DuoPlayer_game_button,&QPushButton::clicked,this,&Widget::open_new_duoplayermainwindow);
    connect(ui->CheckHistoryrecord_button,&QPushButton::clicked,this,&Widget::open_new_historyrecord);
}



void Widget::open_new_mainwindown()
{
    newmainwindow = new MainWindow();
    newmainwindow->show();
    newmainwindow->setAttribute(Qt::WA_DeleteOnClose); //关闭窗口时释放内存防止内存泄漏
}
void Widget::close_new_mainwindow()
{
    newmainwindow->close();
}
void Widget::open_new_bgm_mainwindown(){
    new_bgm_mainwindow = new BGM_MainWindow();
    new_bgm_mainwindow->show();
    new_bgm_mainwindow->setAttribute(Qt::WA_DeleteOnClose); //关闭窗口时释放内存防止内存泄漏
}

void Widget::open_new_duoplayermainwindow(){
    QDesktopWidget *desktopWidget = QApplication::desktop();
    int w1 = (desktopWidget->width() - this->width()) /3;
    int h1= (desktopWidget->height()-this->height())/2;
    //move(h1, w1);
    new_duoplayermainwindow = new DuoPlayerMainWindow();
    new_duoplayermainwindow->resize(h1,w1);
    new_duoplayermainwindow->show();
    new_duoplayermainwindow->setAttribute(Qt::WA_DeleteOnClose); //关闭窗口时释放内存防止内存泄漏
}

void Widget::open_new_historyrecord(){
    newCHR_MainWindow = new CHR_MainWindow;
    newCHR_MainWindow->show();
    newCHR_MainWindow->setAttribute(Qt::WA_DeleteOnClose); //关闭窗口时释放内存防止内存泄漏
}

Widget::~Widget()
{
    delete ui;
}


