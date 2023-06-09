#include <QPushButton>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include <QIODevice>
#include <QDebug>
#include <QCoreApplication>
#include"gameover_widget.h"
#include"ui_gameover_widget.h"

#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std;


#define level1 1000
#define level2 600
#define level3 400
#define level4 350
#define item1 300
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);//创建对象
    QFont ft;
    ft.setPointSize(16);
    QDir d;
    d.cdUp();
    d.cd("./samp2_1/SoundEffect");
    QString f = d.absolutePath();
    effect5.setSource(QUrl::fromLocalFile(f+"/5.wav"));
    effect5.setVolume(200);//设置音效和字体



    tetrisBox = new TetrisBox(this);
    nextTetrisBox = new NextTetrisBox(this);

    nextTetrisLabel = new QLabel(tr("下一个："),this);

    controlLabel = new QLabel(tr("控制："),this);
    w_controlLabel = new QLabel(tr("W-旋转"),this);
    s_controlLabel = new QLabel(tr("S-向下移动"),this);
    a_controlLabel = new QLabel(tr("A-向左移动"),this);
    d_controlLabel = new QLabel(tr("D-向右移动"),this);
    h_controlLabel = new QLabel(tr("H-开始"),this);
    j_controlLabel = new QLabel(tr("J-暂停"),this);
    c_controlLabel = new QLabel(tr("C-重新开始"),this);
    m_controlLabel = new QLabel(tr("M-结束游戏"),this);
    scoreTitleLabel = new QLabel(tr("得分："),this);
    scoreLabel = new QLabel(tr("0"),this);
    levelTitleLabel = new QLabel(tr("关卡："),this);
    levelLabel = new QLabel(tr("0"),this);
    spaceLabel = new QLabel(tr("Space-直接下落"),this);

    spaceLabel->setFont(ft);
    nextTetrisLabel->setFont(ft);
    controlLabel->setFont(ft);
    w_controlLabel->setFont(ft);
    s_controlLabel->setFont(ft);
    a_controlLabel->setFont(ft);
    d_controlLabel->setFont(ft);
    h_controlLabel->setFont(ft);
    j_controlLabel->setFont(ft);
    c_controlLabel->setFont(ft);
    m_controlLabel->setFont(ft);
    scoreTitleLabel->setFont(ft);
    scoreLabel->setFont(ft);
    levelTitleLabel->setFont(ft);
    levelLabel->setFont(ft);





    mainLayout = new QGridLayout;
    score = 0;

    //设置mainLayout的水平和横向的间隔为20
    mainLayout->setHorizontalSpacing(20);
    mainLayout->setVerticalSpacing(20);
    //设置mainLayout居中
    mainLayout->setAlignment(Qt::AlignCenter);
    //添加各个widget
    //mainLayout->addWidget(pushbutton, 10, 10, 1, 1);
    mainLayout->addWidget(tetrisBox, 0, 0, 14, 1);
    mainLayout->addWidget(nextTetrisLabel, 0, 1);
    mainLayout->addWidget(nextTetrisBox, 1, 1, 1, 2);
    mainLayout->addWidget(controlLabel, 5, 1);
    mainLayout->addWidget(w_controlLabel, 6, 1);
    mainLayout->addWidget(s_controlLabel, 6, 2);
    mainLayout->addWidget(a_controlLabel, 7, 1);
    mainLayout->addWidget(d_controlLabel, 7, 2);
    mainLayout->addWidget(h_controlLabel, 8, 1);
    mainLayout->addWidget(j_controlLabel, 8, 2);
    mainLayout->addWidget(c_controlLabel, 9, 1);
    mainLayout->addWidget(m_controlLabel, 9, 2);
    mainLayout->addWidget(scoreTitleLabel, 12, 1);
    mainLayout->addWidget(scoreLabel, 12, 2);
    mainLayout->addWidget(levelTitleLabel, 13, 1);
    mainLayout->addWidget(levelLabel, 13, 2);
    mainLayout->addWidget(spaceLabel,10,1);
    //因为mainWindow已有一个layout，所以不能直接将mainLayout
    //设置到mainWindow中，需要先将mainLayout设置为一个widget的layout
    //在将widget设置为mainLayout的centralWidget
    QWidget *widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    GOwidget = new gameover_widget;

    //设置窗口背景为灰色
    setPalette(Qt::gray);
    //设置窗口在电脑屏幕上居中
    QDesktopWidget *desktopWidget = QApplication::desktop();
    int w = (desktopWidget->width() - this->width()) / 2;
    //int h = 0;
    move(0, w);
    //初始化
    status = STATUS_OFF;
    nextTetrisBox->updateNextTetris(tetris);
    setWindowTitle(tr("Game_Tetris - OFF"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    resize(100,200);
}


MainWindow::~MainWindow() {
    delete ui;
}







//相应键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        //W键-进行旋转并更新游戏窗口内容
        if (tetris.rotate())
            if (status == STATUS_ON)//需要游戏状态为：正常进行
                tetrisBox->updateTetris(tetris);
    } else if (event->key() == Qt::Key_A) {
        //A键-将方块向左移动并更新游戏窗口内容
        if (status == STATUS_ON)
            if (tetris.moveToLeft())
                tetrisBox->updateTetris(tetris);
    } else if (event->key() == Qt::Key_S) {
        //S键-将方块向下移动并更新游戏窗口内容
        if (status == STATUS_ON) {
            if (tetris.moveToBottom()) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();
                startTimer(1);
            } else {


                //游戏结束
                timer->stop();//计时器停止
                //QString str;//输出结束提示
                //str += QString("Game Over!\nYour Score is: %1!").arg(tetris.getScore());
                //QMessageBox::information(this, tr("Game Over"), str);
                //更改游戏状态为：游戏结束
                status = STATUS_END;
                setWindowTitle(tr("Game_Tetris - END"));
                GOwidget->ui->textEdit->setText("");
                GOwidget->ui->scoreLabel->setText(QString("%1!").arg(tetris.getScore()));
                GOwidget->show();
                GOwidget->myscore = tetris.getScore();
            }
        }
    } else if (event->key() == Qt::Key_D) {
        //D键-将方块向右移动并更新游戏窗口内容
        if (status == STATUS_ON)
            if (tetris.moveToRight())
                tetrisBox->updateTetris(tetris);
    } else if (event->key() == Qt::Key_H) {
        //H键-开始游戏
        //不同状态的相应：
        //之前状态    之后状态
        //游戏暂停 -> 正常进行
        //还未开始 -> 正常进行
        //游戏结束 -> 正常进行
        if (status == STATUS_PAUSE) {
            startTimer(0);
            status = STATUS_ON;
            setWindowTitle(tr("Game_Tetris - ON"));
        } else if (status == STATUS_OFF) {
            //初始化窗口视图
            tetris.createBlock();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);
            updateScore();
            startTimer(1);//设置计时器后修改levelLabel
            status = STATUS_ON;
            setWindowTitle(tr("Game_Tetris - ON"));
            startTimer(0);
        } else if (status == STATUS_END) {
            //初始化tetris
            tetris.clear();
            tetris.createBlock();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);
            updateScore();
            startTimer(1);//设置计时器后修改levelLabel
            status = STATUS_ON;
            setWindowTitle(tr("Game_Tetris - ON"));
            startTimer(0);
        }
    } else if (event->key() == Qt::Key_J) {
        //J键-游戏暂停
        if (status == STATUS_ON) {
            timer->stop();
            status = STATUS_PAUSE;
            setWindowTitle(tr("Game_Tetris - PAUSE"));
        }
    } else if (event->key() == Qt::Key_C) {
            //C键-重新开始游戏
            timer->stop();
            tetris.clear();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);

            updateScore();
            status = STATUS_OFF;
            setWindowTitle(tr("Game_Tetris - OFF"));
    } else if (event->key() == Qt::Key_M) {
        //M键-关闭游戏
        close();
    } else if (event->key()==Qt::Key_Space){
        if (status == STATUS_ON) {
            int k = 0;
            while((k = tetris.movetolastLine())) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();
                startTimer(1);
            }
            if(k){
                GOwidget->ui->textEdit->setText("");
                GOwidget->ui->scoreLabel->setText(QString("%1!").arg(tetris.getScore()));
                GOwidget->show();
                GOwidget->myscore = tetris.getScore();



                //游戏结束
                //计时器停止
                timer->stop();
                //输出结束提示
                QString str;
                str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris.getScore());
                QMessageBox::information(this, tr("Game Over!"), str);
                QMessageBox::information(this, tr("Please Enter Your Nickname!"), str);
                //更改游戏状态为：游戏结束
                status = STATUS_END;
                setWindowTitle(tr("Game_Tetris - END"));
            }
        }
    }
}







void MainWindow::onTimer() {
    if (tetris.moveToBottom()) {//若能往下移一格
        tetrisBox->updateTetris(tetris);
        nextTetrisBox->updateNextTetris(tetris);
        updateScore();
        startTimer(1);//设置计时器后修改levelLabel
    } else {
        timer->stop();
        //QString str;
        //str += QString("Game Over!\nYour Score is: %1!").arg(tetris.getScore());
        //QMessageBox::information(this, tr("Game Over"), str);
        //int finalscore=tetris.getScore();


        //游戏结束时->将text设置好，并用GOwidget显示出来
        GOwidget->ui->textEdit->setText("");
        GOwidget->ui->scoreLabel->setText(QString("%1!").arg(tetris.getScore()));
        GOwidget->show();
        GOwidget->myscore = tetris.getScore();


        effect5.play(); //"好了，我们休息一会"
        status = STATUS_END;
        setWindowTitle(tr("Game_Tetris - END"));
    }
}

void MainWindow::updateScore() {//更新scoreLabel并根据分数设定timer间隔
    QString str;
    score = tetris.getScore();
    str += QString("%1").arg(score);
    scoreLabel->setText(str);
    //if(status==STATUS_ON)
    //startTimer(1);//设置计时器后修改levelLabel
}

//若窗口最小化就停止计时器
void MainWindow::changeEvent(QEvent *event) {
    if (event->type() != QEvent::WindowStateChange)
        return;
    if (windowState() == Qt::WindowMinimized){
        timer->stop();
     effect5.play();
    }
}

void MainWindow::startTimer(int toResetLabel) {
    if (score < 160) {
        timer->start(level1);
        if (toResetLabel)
            levelLabel->setText("1");
    } else if (score >= 160 && score < 240) {
        timer->start(level2);
        if (toResetLabel)
            levelLabel->setText("2");
    } else if (score >= 240 && score < 400) {
        timer->start(level3);
        if (toResetLabel)
            levelLabel->setText("3");
    } else if (score >= 400) {
        timer->start(level4);
        if (toResetLabel)
            levelLabel->setText("Gigoku Môdo!!!");
    }
}
