#include "chr_mainwindow.h"
#include "ui_chr_mainwindow.h"
#include<QFile>
#include<QDir>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include<QPalette>
#include<QTextCodec>
struct rank {
    QString name;
    int score;
};

CHR_MainWindow::CHR_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CHR_MainWindow)
{
    ui->setupUi(this);
    QDir d;
    d.cdUp();
    d.cd("./samp2_1/BackGroundPic");
    QString str = d.absolutePath();

    sortingfunc();
    showfunc();
    QPalette palette=this->palette();
    setAutoFillBackground(true);
    palette.setBrush(QPalette::Background,QBrush(QPixmap(str+"/4.jpg").scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    setPalette(palette); // 至此, 已给widget加上了背景图.

}

CHR_MainWindow::~CHR_MainWindow()
{
    delete ui;
}

bool CHR_MainWindow::showfunc(){
    QDir d;
    d.cdUp();
    d.cd("./samp2_1");
    QString str = d.absolutePath();
    QFile file(str+"/score.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    ui->plainTextEdit->setPlainText(file.readAll());
    file.close();
    return true;
}

void CHR_MainWindow::sortingfunc() {



    QDir d;
    d.cdUp();
    d.cd("./samp2_1");
    QString str = d.absolutePath();
    QFile file1(str+"/score.txt");
    file1.open(QIODevice::ReadOnly| QIODevice::Text);
    QTextStream tsfile1(&file1);
    tsfile1.setAutoDetectUnicode(true);
    int count = 0;
    while (!tsfile1.readLine().isNull()) {
        count++;
    }
    count++;
    file1.close();
    QFile file2(str+"/score.txt");
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream tsfile2(&file2);
    //tsfile2 = QTextStream(&file2);
    int k = count / 2;
    //qDebug() << k;
    rank r[k];
    for (int i = 0; i < k; i++) {
        //r[i].name = tsfile1.readLine();
        //r[i].score = tsfile1.readLine().toInt();
        tsfile2 >> r[i].name;
        tsfile2>> r[i].score;
    }
    for (int i = 0; i < k-1; i++) {
        for (int j = i + 1; j < k; j++){
            if(r[i].score<r[j].score){
                //qDebug() << r[i].name << r[i].score;
                rank temp=r[i];
                r[i]=r[j];
                r[j]=temp;

            }
        }
    }
    file1.close();
    //QFile file1(str+"/score.txt");
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    if(k>10)
        k=10;
    for (int i = 0; i < k; i++) {
        //QByteArray strBytes = r[i].name.toUtf8();
        //file3.write(strBytes,strBytes.length());
        //QString str = str.number(r[i].score);
        tsfile1<< r[i].name << Qt::endl;
        //QByteArray intBytes = str.toUtf8();
        //file3.write(intBytes,intBytes.length());
        tsfile1 << r[i].score << Qt::endl;
        //qDebug()<<r[i].name<<r[i].score;
        //qDebug()<<strBytes<<intBytes;
    }
    file1.close();
}
