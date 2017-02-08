//
#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include "enemy.h"

using namespace std;

class Tank: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    pair<int, int> position;
    pair<unsigned int, unsigned int> size;
    QTimer *timer;
public:
    Tank(int x, int y, unsigned int width, unsigned int height, double downSpeed);
public slots:
    void move();
};

#endif
