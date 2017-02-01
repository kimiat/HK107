#include <iostream>
#include "enemy.h"

using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int x, int y)
{
	this->position.first = x;
	this->position.second = y;
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

Ship::Ship(int x, int y)
{
	this->position.first = x;
	this->position.second = y;
}

Jet::Jet(int x, int y)
{
	this->position.first = x;
	this->position.second = y;
}

Helicopter::Helicopter(int x, int y)
{
	this->position.first = x;
	this->position.second = y;
}

Balloon::Balloon(int x, int y)
{
	this->position.first = x;
	this->position.second = y;
}
