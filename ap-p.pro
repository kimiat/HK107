#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T14:05:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ap-p
TEMPLATE = app


SOURCES += main.cpp \
    fuel.cpp \
    enemy.cpp \
    bottom_panel.cpp \
    player.cpp \
    missile.cpp \
    tank.cpp \
    setup.cpp \
    score.cpp \
    player_ui.cpp \
    missile_ui.cpp

HEADERS  += \
    fuel.h \
    enemy.h \
    bottom_panel.h \
    player.h \
    tank.h \
    setup.h \
    score.h \
    player_ui.h \
    missile.h \
    missile_ui.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
