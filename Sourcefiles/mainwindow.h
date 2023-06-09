#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include "tetris.h"
#include "tetrisbox.h"
#include "nexttetris.h"
#include"ui_mainwindow.h"
#include<QLabel>
#include<QVector>
#include"gameover_widget.h"

//游戏的状态
#define STATUS_ON 0     //游戏正常进行
#define STATUS_PAUSE 1  //游戏暂停
#define STATUS_OFF 2    //游戏未开始
#define STATUS_END 3    //游戏结束
#define level1 1000
#define level2 600
#define level3 400
#define level4 350
#define item1 300

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
      void initMainWindow();
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void keyPressEvent(QKeyEvent *event);   //响应键盘事件
        void changeEvent(QEvent *event);        //窗口最小化后暂停
        void updateScore();                     //更新分数的数据和显示
        gameover_widget *GOwidget;          //游戏结束后弹出提醒窗口，输入昵称载入排行榜




    public slots:
        void onTimer();
    private:
        void startTimer(int toResetLabel);
        Ui::MainWindow *ui;
        int status;                     //游戏状态
        Tetris tetris;                  //俄罗斯方块类对象
        QTimer *timer;                  //计时器
        TetrisBox *tetrisBox;           //游戏窗口
        NextTetrisBox *nextTetrisBox;   //“下一个”窗口
        //QPushButton * pushButton;       //button
        QGridLayout *mainLayout;        //mainLayout
        //QPushButton *pushbutton;        //Pushbutton的标签
        QLabel *nextTetrisLabel;        //“下一个”窗口的标签
        QLabel *controlLabel;           //“控制”标签
        QLabel *w_controlLabel;         //W键的标签
        QLabel *s_controlLabel;         //S键的标签
        QLabel *a_controlLabel;         //A键的标签
        QLabel *d_controlLabel;         //D键的标签
        QLabel *h_controlLabel;         //H键的标签
        QLabel *j_controlLabel;         //J键的标签
        QLabel *c_controlLabel;         //C键的标签
        QLabel *m_controlLabel;         //M键的标签
        QLabel *scoreTitleLabel;        //分数标题标签
        QLabel *scoreLabel;             //分数标签（用来显示分数）
        QLabel *levelLabel;           //“关卡”标题标签
        QLabel *levelTitleLabel;        //关卡显示标签（用来显示关卡）
        QLabel *spaceLabel;         //空格直接下落
        int score;  //分数
        QSoundEffect effect5;   //休息一会的音效
};


#endif // MAINWINDOW_H
