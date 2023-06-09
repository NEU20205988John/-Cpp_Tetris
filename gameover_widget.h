#ifndef GAMEOVER_WIDGET_H
#define GAMEOVER_WIDGET_H

#include <QWidget>
#include<QString>

namespace Ui {
class gameover_widget;
}


class gameover_widget : public QWidget
{
    Q_OBJECT

public:
    explicit gameover_widget(QWidget *parent = nullptr);
    ~gameover_widget();
    int myscore;
    QString mynickname;
    void on_pushbutton_clicked();
    Ui::gameover_widget *ui;
};

#endif // GAMEOVER_WIDGET_H
