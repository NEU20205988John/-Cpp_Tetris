#ifndef CHR_MAINWINDOW_H
#define CHR_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CHR_MainWindow;
}

class CHR_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void sortingfunc();
    bool showfunc();
    explicit CHR_MainWindow(QWidget *parent = nullptr);
    ~CHR_MainWindow();

private:
    Ui::CHR_MainWindow *ui;
};

#endif // CHR_MAINWINDOW_H
