#ifndef MENU_H
#define MENU_H

#include "menu_button.h"
#include "setup.h"
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

using namespace std;

class Menu: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    menu_button *buttons[4];
    Setup *setup;
public:
    Menu();
    QGraphicsScene *getScene();
public slots:
    void play();
    void score();
    void credits();
    void quit();
};

#endif
