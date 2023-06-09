#ifndef BGM_MAINWINDOW_H
#define BGM_MAINWINDOW_H

#include <QMainWindow>
#include    <QMediaPlayer>
#include    <QMediaPlaylist>

namespace Ui {
class BGM_MainWindow;
}

class BGM_MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMediaPlayer    *player;//播放器
    QMediaPlaylist  *playlist;//播放列表

    QString  durationTime;//总长度
    QString  positionTime;//当前播放到位置
public:
    explicit BGM_MainWindow(QWidget *parent = 0);
    ~BGM_MainWindow();

private slots:
//自定义槽函数
    void onStateChanged(QMediaPlayer::State state);

    void onPlaylistChanged(int position);

    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);


    void on_btnAdd_clicked();

    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_btnStop_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_btnClear_clicked();

    void on_sliderVolumn_valueChanged(int value);

    void on_btnSound_clicked();

//    void on_sliderPosition_valueChanged(int value);

//    void on_sliderPosition_sliderMoved(int position);

    void on_sliderPosition_valueChanged(int value);

    void on_btnRemove_clicked();

    void on_btnPrevious_clicked();

    void on_btnNext_clicked();

private:
    Ui::BGM_MainWindow *ui;
};

#endif // BGM_MAINWINDOW_H
