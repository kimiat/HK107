#include <iostream>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect)
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
    this->position.second += 3;
    bool flag = true;
    if(position.second > HEIGHT)
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

Enemy::~Enemy() {}

void Enemy::move()
{
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
    {
        setPos(position.first, position.second);
//        qDebug() << movingPos << "  " << "  " << position.first << "  " << position.second;
    }
    if(position.second >= movingPos && select != newSelect)
    {
//        qDebug() << "Enemy should move now...";
//        qDebug() << select << " and " << newSelect;
        select = newSelect;
    }
}

Ship::Ship(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect)
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
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Jet::Jet(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect)
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
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Helicopter::Helicopter(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect)
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
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

Balloon::Balloon(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect)
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
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}
