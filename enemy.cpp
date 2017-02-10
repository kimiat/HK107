#include <iostream>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "player.h"
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>

#define DOWNPANEL_H 80

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
	this->position = position;
	this->select = select;
	this->newSelect = newSelect;
	this->movingPos = movingPos;
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
	timer->start(20);
}

pair<int, int> Enemy::getPosition() { return position; }

int Enemy::getMovingPos() { return this->movingPos; }

Movement Enemy::getSelect() { return this->select; }

Movement Enemy::getNewSelect() { return this->newSelect; }

void Enemy::moveDown()
{
    this->position.second += downSpeed;
    if(position.second > HEIGHT - DOWNPANEL_H)
    {
        emit destroyed();
//        qDebug() << "Enemy removed and deleted!";
        delete this;
        return;
    }
	emit moved();
}

Enemy::~Enemy() {}

Ship::Ship(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
	this->position = position;
	this->select = select;
	this->newSelect = newSelect;
	this->movingPos = movingPos;
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
	timer->start(20);
}

Helicopter::Helicopter(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
	this->position = position;
	this->select = select;
	this->newSelect = newSelect;
	this->movingPos = movingPos;
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
	timer->start(20);

}

Balloon::Balloon(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
	this->position = position;
	this->select = select;
	this->newSelect = newSelect;
	this->movingPos = movingPos;
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
	timer->start(20);

}

Jet::Jet(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect)
{
	this->position = position;
	this->select = select;
	this->newSelect = newSelect;
	this->movingPos = movingPos;
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
	timer->start(20);

}
