#include <iostream>
#include <QGraphicsScene>
#include "enemy.h"

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int x, int y, unsigned int width, unsigned int height, Movement select)
{
    this->position.first = x;
    this->position.second = y;
    this->size.first = width;
    this->size.second = height;
    this->select = select;
    setRect(0, 0, width, height);
    this->timer = new QTimer();
    this->speed = 10;
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

void Enemy::moveDown()
{
	this->position.second += speed;
}

void Enemy::moveRight()
{
	this->position.first += speed;
}

void Enemy::moveLeft()
{
	this->position.first -= speed;
}

Enemy::~Enemy() {}

void Enemy::move()
{
    switch(this->select)
    {
    case DOWN:
        this->moveDown();
        break;
    case LEFT:
        this->moveLeft();
        break;
    case RIGHT:
        this->moveRight();
        break;
    }
    setPos(position.first, position.second);
}

//Ship::Ship(int x, int y, unsigned int width, unsigned int height, int select)
//{
//	this->position.first = x;
//	this->position.second = y;
//    this->size.first = width;
//    this->size.second = height;
//    this->timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move(select)));
//    timer->start(50);
//}

//Jet::Jet(int x, int y, unsigned int width, unsigned int height, int select)
//{
//	this->position.first = x;
//	this->position.second = y;
//    this->size.first = width;
//    this->size.second = height;
//    this->timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move(select)));
//    timer->start(50);
//}

//Helicopter::Helicopter(int x, int y, unsigned int width, unsigned int height, int select)
//{
//	this->position.first = x;
//	this->position.second = y;
//    this->size.first = width;
//    this->size.second = height;
//    this->timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move(select)));
//    timer->start(50);
//}

//Balloon::Balloon(int x, int y, unsigned int width, unsigned int height, int select)
//{
//	this->position.first = x;
//	this->position.second = y;
//    this->size.first = width;
//    this->size.second = height;
//    this->timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move(select)));
//    timer->start(50);
//}
