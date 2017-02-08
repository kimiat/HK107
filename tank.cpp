//
#include "tank.h"
#include "enemy.h"
#include <iostream>
#include <QGraphicsScene>
#include <QDebug>

#define DOWNPANEL_H 80

using namespace std;

Tank::Tank(int x, int y, unsigned int width, unsigned int height, double downSpeed)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

void Tank::move()
{
    this->position.second += downSpeed;
    downSpeed += 0.01;
    bool flag = true;
    if(position.second > HEIGHT - DOWNPANEL_H)
    {
        scene()->removeItem(this);
        delete this;
        flag = false;
        qDebug() << "Fuel removed and deleted!";
    }
    if(flag)
        setPos(position.first, position.second);
}


