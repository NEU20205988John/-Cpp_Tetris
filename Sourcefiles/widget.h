#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//需要包含按键事件的头文件
#include <QKeyEvent>
#include<mainwindow.h>
#include"bgm_mainwindow.h"
#include"duoplayermainwindow.h"
#include"chr_mainwindow.h"
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE




class Widget : public QWidget
{

    Q_OBJECT
public:
    void classIsOver();
    void single_game_clicked();
    void CHR_button_clicked();
    void open_new_mainwindown();//打开新窗口
    void close_new_mainwindow();//关闭新窗口
    void open_new_duoplayermainwindow();
    void open_new_bgm_mainwindown();//打开BGM窗口
    void open_new_historyrecord(); //打开历史榜单窗口
    MainWindow * newmainwindow;
    BGM_MainWindow * new_bgm_mainwindow;
    DuoPlayerMainWindow* new_duoplayermainwindow;
    CHR_MainWindow* newCHR_MainWindow;
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void on_pushbutton_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
