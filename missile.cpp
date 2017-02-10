
#include "missile.h"
#include "enemy.h"
#include "tank.h"
#include "player.h"
#include <QTimer>
#include <iostream>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>

#define speed 5

using namespace std;

int num = 0;

missile::missile(int x, int y)
{
    this->x = x;
    this->y = y;
    num++;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
    timer->start(4);
}

int missile::get_x()
{
    return x;
}

int missile::get_y()
{
    return y;
}

void missile::move_up()
{
    y -= speed;
    emit m_moved();
    if(get_y() < -20)
    {
        emit m_removed();
        delete this;
    }
}

missile::~missile()
{
    delete timer;
    num--;
}

void missile::stopTimer()
{
    timer->stop();
}


