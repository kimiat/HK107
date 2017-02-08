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

missile::missile(int x, int y, int width, int height, Player *player)
{
    setRect(0, 0, width, height);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->player = player;
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
        if(typeid(*(destroyedEnemies[i])) == typeid(Ship))
        {
            qDebug() << "The ship has been destroyed!";
            qDebug() << this->player->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            this->player->addScore(SHIP);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(Helicopter))
        {
            qDebug() << "The helicopter has been destroyed!";
            qDebug() << this->player->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            this->player->addScore(HELICOPTER);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(Jet))
        {
            qDebug() << "The jet has been destroyed!";
            qDebug() << this->player->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            this->player->addScore(JET);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(Balloon))
        {
            qDebug() << "The balloon has been destroyed!";
            qDebug() << this->player->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            this->player->addScore(BALLOON);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(Tank))
        {
            qDebug() << "The tank has been destroyed!";
            qDebug() << this->player->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            this->player->addScore(TANK);
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

