#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include "enemy.h"
#include <QMediaPlayer>
#include "player.h"

using namespace std;

class Tank: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer* check;
    QTimer* exp;
    Player* player;
    QMediaPlayer* sound;
    pair<int, int> position;
    QTimer *timer;
    bool isRemoved;
    int shot_num;
signals:
    void getFuel();
    void stop();
public:
    Tank(int x, int y,double downSpeed, Player* p);
public slots:
    void move();
    void check_c();
    void explode();
};

#endif
