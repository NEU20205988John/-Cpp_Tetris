#ifndef DUOPLAYERMAINWINDOW_H
#define DUOPLAYERMAINWINDOW_H

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
#include"ui_duoplayermainwindow.h"

//游戏的状态
#define STATUS_ON 0     //游戏正常进行
#define STATUS_PAUSE 1  //游戏暂停
#define STATUS_OFF 2    //游戏未开始
#define STATUS_END 3    //游戏结束

namespace Ui {
class DuoPlayerMainWindow;
}

class DuoPlayerMainWindow:public QMainWindow
{       Q_OBJECT
    public:
        DuoPlayerMainWindow(QWidget *parent = 0);
        ~DuoPlayerMainWindow();
        void keyPressEvent(QKeyEvent *event);   //响应键盘事件
        void changeEvent(QEvent *event);        //窗口最小化后暂停
        void updateScore();                     //更新分数的数据和显示

    public slots:
        void onTimer();
        //void startTimer(int a,int b);
    private:
        void startTimer(int timerN, int toResetLabel);
        Ui::DuoPlayerMainWindow *ui;
        int status1;                     //游戏状态
        int status2;                     //游戏状态
        Tetris tetris1;                  //俄罗斯方块类对象
        Tetris  tetris2;                //二号玩家的俄罗斯方块对象
        QTimer *timer1;                  //计时器
        QTimer *timer2;                  //计时器
        QTimer *timer3;                  //计时器  用于加速道具-玩家1 Q键
        QTimer *timer4;                 //计时器 用于加速道具-玩家2 I键
        TetrisBox *tetrisBox1;           //游戏窗口
        TetrisBox *tetrisBox2;           //游戏窗口

        NextTetrisBox *nextTetrisBox1;   //“下一个”窗口
        NextTetrisBox *nextTetrisBox2;   //“下一个”窗口


        QWidget *interactionBox;   //用来互动的“下一个”窗口
        QLabel  *prop1status;
        QLabel  *prop2status;

        QGridLayout *mainLayout1;        //mainLayout
        QPushButton *pushbutton1;        //Pushbutton的标签
        QLabel *nextTetrisLabel1;        //“下一个”窗口的标签
        QLabel *controlLabel1;           //“控制”标签
        QLabel *w_controlLabel1;         //W键的标签
        QLabel *s_controlLabel1;         //S键的标签
        QLabel *a_controlLabel1;         //A键的标签
        QLabel *d_controlLabel1;         //D键的标签
            QLabel *prop1_controlLabel1;         //玩家1道具1的标签    "Q-加速对手方块下落速度直至消行"
            QLabel *prop2_controlLabel1;         //玩家1道具2的标签    "E-将"下一个"方块与对手交换"
            QLabel *prop3_controlLabel1;         //玩家1道具3的标签    "R-快速下落对手方块"
            QLabel *prop1_controlLabel2;         //玩家2道具1的标签    "I-加速对手方块下落速度直至消行"
            QLabel *prop2_controlLabel2;         //玩家2道具2的标签    "O-将"下一个"方块与对手交换"
            QLabel *prop3_controlLabel2;        //玩家2道具3的标签     "P-快速下落对手方块"
           QLabel  *l_controlLabel;     //玩家2按L快速下落         "L-方块快速下落"
           QLabel  *space_controlLabel;  //玩家1按空格快速下落       "space-方块快速下落"

        QLabel *h_controlLabel1;         //H键的标签
        QLabel *j_controlLabel1;         //J键的标签
        QLabel *c_controlLabel1;         //C键的标签
        QLabel *m_controlLabel1;         //M键的标签
        QLabel *scoreTitleLabel1;        //分数标题标签

        QLabel *scoreLabel1;

        int score1;
        int score2;
        QLabel *levelLabel1;           //“关卡”标题标签
        QLabel *levelTitleLabel1;        //关卡显示标签（用来显示关卡）
        QLabel *levelLabel2;           //“关卡”标题标签
        QLabel *levelTitleLabel2;        //关卡显示标签（用来显示关卡）


        QGridLayout *mainLayout2;        //mainLayout
        QPushButton *pushbutton2;        //Pushbutton的标签
        QLabel *nextTetrisLabel2;        //“下一个”窗口的标签
        QLabel *controlLabel2;           //“控制”标签
        QLabel *w_controlLabel2;         //↑键的标签
        QLabel *s_controlLabel2;         //↓键的标签
        QLabel *a_controlLabel2;         //←键的标签
        QLabel *d_controlLabel2;         //→键的标签
        QLabel *h_controlLabel2;         //H键的标签
        QLabel *j_controlLabel2;         //J键的标签
        QLabel *c_controlLabel2;         //C键的标签
        QLabel *m_controlLabel2;         //M键的标签
        QLabel *scoreTitleLabel2;        //分数标题标签
        QLabel *scoreLabel2;
        QSoundEffect effect5;   //休息一会的音效


};





#endif // DUOPLAYERMAINWINDOW_H
