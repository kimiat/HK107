#include <iostream>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "player.h"
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>

#define DOWNPANEL_H 80

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int x, int y, unsigned int width, unsigned int height, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    this->newSelect = newSelect;
    this->movingPos = movingPos;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
    this->speed = 15;
//    this->downSpeed = downSpeed;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

pair<int, int> Enemy::getPosition()
{
    return position;
}

pair<unsigned int, unsigned int> Enemy::getSize()
{
    return size;
}

bool Enemy::moveDown()
{
    this->position.second += downSpeed;
    bool flag = true;
    if(position.second > HEIGHT - DOWNPANEL_H)
    {
        scene()->removeItem(this);
        delete this;
        flag = false;
        qDebug() << "Enemy removed and deleted!";
    }
    return flag;
}

bool Enemy::moveRight()
{
    bool flag = true;
    if(position.first <= WIDTH + 2 * size.first)
        this->position.first += speed;
    else
    {
        scene()->removeItem(this);
        delete this;
        flag = false;
        qDebug() << "Enemy removed and deleted!";
    }
    return flag;
}

bool Enemy::moveLeft()
{
    bool flag = true;
    if(position.first + size.first > 0)
        this->position.first -= speed;
    else
    {
        scene()->removeItem(this);
        delete this;
        flag = false;
        qDebug() << "Enemy removed and deleted!";
    }
    return flag;
}

void Enemy::checkLosing()
{
    QList<QGraphicsItem*> check = collidingItems();
    int n = check.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(*(check[i])) == typeid(Player))
        {
            qDebug() << "This is a player item!";
            qDebug() << "You LOSE!";
            exit(0);
            scene()->removeItem(check[i]);
            scene()->removeItem(this);
            delete check[i];
            delete this;
//            exit(0);
            return;
        }
    }
}

Enemy::~Enemy() {}

void Enemy::move()
{
    this->checkLosing();
    downSpeed += 0.01;
    bool flag;
    switch(this->select)
    {
    case DOWN:
        flag = this->moveDown();
        break;
    case LEFT:
        flag = this->moveLeft() && this->moveDown();
        break;
    case RIGHT:
        flag = this->moveRight() && this->moveDown();
        break;
    }
    if(flag)
        setPos(position.first, position.second);
    if(position.second >= movingPos && select != newSelect)
        select = newSelect;
}

Ship::Ship(int x, int y, unsigned int width, unsigned int height, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    this->newSelect = newSelect;
    this->movingPos = movingPos;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
    this->speed = 15;
//    this->downSpeed = downSpeed;
//    this->downSpeed = 4;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

Jet::Jet(int x, int y, unsigned int width, unsigned int height, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    this->newSelect = newSelect;
    this->movingPos = movingPos;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
    this->speed = 15;
//    this->downSpeed = downSpeed;
//    this->downSpeed = 4;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

Helicopter::Helicopter(int x, int y, unsigned int width, unsigned int height, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    this->newSelect = newSelect;
    this->movingPos = movingPos;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
//    this->downSpeed = downSpeed;
    this->speed = 15;
//    this->downSpeed = 4;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

Balloon::Balloon(int x, int y, unsigned int width, unsigned int height, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    this->newSelect = newSelect;
    this->movingPos = movingPos;
    setRect(0, 0, width, height);
    setPos(x, y);
    this->timer = new QTimer();
//    this->downSpeed = downSpeed;
    this->speed = 15;
//    this->downSpeed = 4;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}
