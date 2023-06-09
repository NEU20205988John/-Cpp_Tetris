#include "gameover_widget.h"
#include "ui_gameover_widget.h"
#include<QString>
#include<QFile>
#include<QDebug>
#include<string>
#include<QDir>
#include <QIODevice>
#include <QCoreApplication>
#include<QTextCodec>
#include<QMessageBox>

gameover_widget::gameover_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover_widget)
{

    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&gameover_widget::on_pushbutton_clicked);
}

gameover_widget::~gameover_widget()
{
    delete ui;
}

void gameover_widget::on_pushbutton_clicked(){
    mynickname = ui->textEdit->toPlainText();
    if(mynickname.isEmpty()){
        close();
        return;
    }
    QString str1 = mynickname;
    bool b = str1.contains(QRegExp("[\\x4e00-\\x9fa5]+"));
    if(b)
    {   QString str;//输出结束提示
        str += QString("Do Not Enter Chinese charaacters!");
        QMessageBox::information(this, tr("Warning"), str);
        close();
        return;
    }
    /*std::string myStr = mynickname.toStdString();
    const char* myChar = myStr.c_str();
    qDebug()<<myChar;
    qDebug()<<myscore;*/
    //QFile file("score.txt");
    //if(!file.open(QIODevice::Append))
        //qDebug()<<file.errorString();
    // 测试数据
    // 获取当前执行路径
    QDir d;
    d.cdUp();
    d.cd("./samp2_1");
    // 输出当前路径
    //qDebug() << d;
    // 创建文件指针
    QString str = d.absolutePath();
    QFile file(str+"/score.txt");
    bool ok =file.open(QIODevice::ReadWrite | QIODevice::Append);
    // 打开文件，读写与追加
    // 如果文件没有被占用可以打开
    if(ok){
        // 输出debug信息
        //qDebug() << "write";
        // 创建stream
        QTextStream txtOutput(&file);
       //txtOutput.setAutoDetectUnicode(true);
        // 在stream追加数据，并换行
        txtOutput << mynickname << Qt::endl;
        txtOutput << myscore   <<Qt::endl;
    }
    // 关闭文件, 保存数据
    file.close();
    close();
}
