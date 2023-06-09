QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
CONFIG+= console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bgm_mainwindow.cpp \
    chr_mainwindow.cpp \
    duoplayermainwindow.cpp \
    gameover_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    nexttetris.cpp \
    tetris.cpp \
    tetrisbox.cpp \
    widget.cpp

HEADERS += \
    bgm_mainwindow.h \
    chr_mainwindow.h \
    duoplayermainwindow.h \
    gameover_widget.h \
    mainwindow.h \
    nexttetris.h \
    tetris.h \
    tetrisbox.h \
    widget.h

FORMS += \
    bgm_mainwindow.ui \
    chr_mainwindow.ui \
    gameover_widget.ui \
    widget.ui

TRANSLATIONS += \
    samp2_1_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
