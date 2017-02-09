//
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

missile::missile(int x, int y, Player *player)
{
//    setRect(0, 0, width, height);
    this->x = x;
    this->y = y;
    this->player = player;
    num++;
//    cout << "num is cons " << num;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
    timer->start(4);
}

int missile::get_x()
{
    return x;
}

//int missile::get_num()
//{
//    return num;
//}

int missile::get_y()
{
    return y;
}

//int missile::get_height()
//{
//    return height;
//}

//int get_num()
//{
//    return num;
//}

void missile::move_up()
{
//    QList<QGraphicsItem*> destroyedEnemies = collidingItems();
//    int n = destroyedEnemies.size();
//    for(int i = 0; i < n; i++)
//    {
//        if(typeid(*(destroyedEnemies[i])) == typeid(Ship))
//        {
//            qDebug() << "The ship has been destroyed!";
//            this->player->addScore(SHIP);
//            qDebug() << this->player->getScore();
//            scene()->removeItem(destroyedEnemies[i]);
//            scene()->removeItem(this);
//            delete destroyedEnemies[i];
//            delete this;
//            return;
//        }
//        else if(typeid(*(destroyedEnemies[i])) == typeid(Helicopter))
//        {
//            qDebug() << "The helicopter has been destroyed!";
//            this->player->addScore(HELICOPTER);
//            qDebug() << this->player->getScore();
//            scene()->removeItem(destroyedEnemies[i]);
//            scene()->removeItem(this);
//            delete destroyedEnemies[i];
//            delete this;
//            return;
//        }
//        else if(typeid(*(destroyedEnemies[i])) == typeid(Jet))
//        {
//            qDebug() << "The jet has been destroyed!";
//            this->player->addScore(JET);
//            qDebug() << this->player->getScore();
//            scene()->removeItem(destroyedEnemies[i]);
//            scene()->removeItem(this);
//            delete destroyedEnemies[i];
//            delete this;
//            return;
//        }
//        else if(typeid(*(destroyedEnemies[i])) == typeid(Balloon))
//        {
//            qDebug() << "The balloon has been destroyed!";
//            this->player->addScore(BALLOON);
//            qDebug() << this->player->getScore();
//            scene()->removeItem(destroyedEnemies[i]);
//            scene()->removeItem(this);
//            delete destroyedEnemies[i];
//            delete this;
//            return;
//        }
//        else if(typeid(*(destroyedEnemies[i])) == typeid(Tank))
//        {
//            qDebug() << "The tank has been destroyed!";
//            this->player->addScore(TANK);
//            qDebug() << this->player->getScore();
//            scene()->removeItem(destroyedEnemies[i]);
//            scene()->removeItem(this);
//            delete destroyedEnemies[i];
//            delete this;
//            return;
//        }
//    }
    y -= speed;
//    cout << "it is moving up "<< endl;
    emit m_moved();
//    setPos(get_x(), get_y() - 10);
    if(get_y() < -20)
    {
        cout << "it is going to be removed "<< endl;
        emit m_removed();
//        cout << " bullet is destryped" << endl;
//        scene()->removeItem(this);
        delete this;
    }
}

missile::~missile()
{
    cout << "in the desstructor "<< endl;
    delete timer;
    num--;
}
