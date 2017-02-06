#include "missile.h"
#include "enemy.h"
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

missile::missile(int x, int y, int width, int height)
{
    setRect(0, 0, width, height);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    num++;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
    timer->start(8);
}

int missile::get_x()
{
    return x;
}

int missile::get_y()
{
    return y;
}

int missile::get_height()
{
    return height;
}

int get_num()
{
    return num;
}

void missile::move_up()
{
    QList<QGraphicsItem*> destroyedEnemies = collidingItems();
    int n = destroyedEnemies.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(*(destroyedEnemies[i])) != typeid(Player))
        {
            qDebug() << "this is a destroyed item!";
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
    }
    y -= speed;
    setPos(get_x(), get_y() - 10);
    if(get_y() < 0 - get_height())
    {
        scene()->removeItem(this);
        delete this;
    }
}

missile::~missile()
{
    delete timer;
    num--;
}

