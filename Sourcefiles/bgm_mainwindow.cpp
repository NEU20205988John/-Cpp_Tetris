#include "bgm_mainwindow.h"
#include "ui_bgm_mainwindow.h"
#include<QDir>
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include <QString>
#include<QFileDialog>
#include<QDebug>

BGM_MainWindow::BGM_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BGM_MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);//
    playlist = new QMediaPlaylist(this);//
    playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环模式

    QDir d;
    d.cdUp();
    d.cd("./samp2_1/BGM");
    QString f = d.absolutePath();
    //qDebug()<<f;

    f += "/1.mp3";
    playlist->addMedia(QUrl::fromLocalFile(f));
    ui->listWidget->addItem("Eminence Front");

    f = d.absolutePath();
    f += "/2.mp3";
    playlist->addMedia(QUrl::fromLocalFile(f));
    ui->listWidget->addItem("Подмосковные вечера");

    f = d.absolutePath();
    f += "/3.mp3";
    playlist->addMedia(QUrl::fromLocalFile(f));
    ui->listWidget->addItem("Crepusculo");

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));

    connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));

    connect(playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));
    player->setPlaylist(playlist);
}

BGM_MainWindow::~BGM_MainWindow()
{
    delete ui;
}

void BGM_MainWindow::onStateChanged(QMediaPlayer::State state)
{//播放器状态变化，更新按钮状态
    ui->btnPlay->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->btnPause->setEnabled(state==QMediaPlayer::PlayingState);
    ui->btnStop->setEnabled(state==QMediaPlayer::PlayingState);
}

void BGM_MainWindow::onPlaylistChanged(int position)
{//播放列表变化,更新当前播放文件名显示
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem  *item=ui->listWidget->currentItem();
    if (item)
        ui->LabCurMedia->setText(item->text());
}

void BGM_MainWindow::onDurationChanged(qint64 duration)
{//文件时长变化，更新进度显示
    ui->sliderPosition->setMaximum(duration);

     int   secs=duration/1000;//秒
     int   mins=secs/60; //分钟
     secs=secs % 60;//余数秒
     durationTime=QString::asprintf("%d:%d",mins,secs);
     ui->LabRatio->setText(positionTime+"/"+durationTime);
}

void BGM_MainWindow::onPositionChanged(qint64 position)
{//当前文件播放位置变化，更新进度显示
    if (ui->sliderPosition->isSliderDown())
        return;

    ui->sliderPosition->setSliderPosition(position);//

    int   secs=position/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}

void BGM_MainWindow::on_btnAdd_clicked()
{//添加文件
     QString curPath=QDir::homePath();//获取系统当前目录
     QString dlgTitle="选择音频文件"; //对话框标题
     QString filter="音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)"; //文件过滤器
     QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);

     if (fileList.count()<1)
         return;

     for (int i=0; i<fileList.count();i++)
     {
        QString aFile=fileList.at(i);
        playlist->addMedia(QUrl::fromLocalFile(aFile));//添加文件

        QFileInfo   fileInfo(aFile);
        ui->listWidget->addItem(fileInfo.fileName());//添加到界面文件列表
     }

     if (player->state()!=QMediaPlayer::PlayingState)
         playlist->setCurrentIndex(0);
     player->play();
}

void BGM_MainWindow::on_btnPlay_clicked()
{//播放
    if (playlist->currentIndex()<0)
        playlist->setCurrentIndex(0);
    player->play();
}

void BGM_MainWindow::on_btnPause_clicked()
{//暂停播放
    player->pause();
}

void BGM_MainWindow::on_btnStop_clicked()
{//停止播放
    player->stop();
}

void BGM_MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{//双击时切换播放文件
    int rowNo=index.row();
    playlist->setCurrentIndex(rowNo);
    player->play();
}

void BGM_MainWindow::on_btnClear_clicked()
{//清空列表
    playlist->clear();
    ui->listWidget->clear();
    player->stop();
}

void BGM_MainWindow::on_sliderVolumn_valueChanged(int value)
{//调整音量
    player->setVolume(value);
    QDir d;
    d.cdUp();
    d.cd("./samp2_1/images");
    QString f = d.absolutePath();
    if (value!=0)
        ui->btnSound->setIcon(QIcon(f+"/volumn.bmp"));
    else
        ui->btnSound->setIcon(QIcon(f+"/mute.bmp"));
}

void BGM_MainWindow::on_btnSound_clicked()
{//静音控制
    QDir d;
    d.cdUp();
    d.cd("./samp2_1/images");
    QString f = d.absolutePath();
    bool mute=player->isMuted();
    player->setMuted(!mute);
    if (mute)
        ui->btnSound->setIcon(QIcon(f+"/volumn.bmp"));
    else
        ui->btnSound->setIcon(QIcon(f+"/mute.bmp"));
}

void BGM_MainWindow::on_sliderPosition_valueChanged(int value)
{//文件进度调控
   player->setPosition(value);
}

void BGM_MainWindow::on_btnRemove_clicked()
{//移除一个文件
    int pos=ui->listWidget->currentRow();
    QListWidgetItem *item=ui->listWidget->takeItem(pos);
    delete item;//从listWidget里删除

    if (playlist->currentIndex()==pos) //是当前播放的曲目
    {
        int nextPos=0;
        if (pos>=1)
            nextPos=pos-1;

        playlist->removeMedia(pos);//从播放列表里移除
        if (ui->listWidget->count()>0)
        {
            playlist->setCurrentIndex(nextPos);
            onPlaylistChanged(nextPos);
        }
        else
        {
            player->stop();
            ui->LabCurMedia->setText("无曲目");
        }
    }
    else
        playlist->removeMedia(pos);
}

void BGM_MainWindow::on_btnPrevious_clicked()
{//前一文件
    playlist->previous();
}

void BGM_MainWindow::on_btnNext_clicked()
{//下一文件
    playlist->next();
}
