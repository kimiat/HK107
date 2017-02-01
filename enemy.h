#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

using namespace std;

const int HEIGHT = 600;
const int WIDTH = 600;

class Enemy
{
protected:
	pair<int, int> position; //x and y
	pair<unsigned int, unsigned int> size; //width and height
	int speed; //how much should it move per millisecond
public:
	Enemy();
	Enemy(int x, int y);
	void moveDown();
	void moveRight();
	void moveLeft();
	~Enemy();
};

class Ship: public Enemy
{
public:
	Ship(int x, int y);
};

class Jet: public Enemy
{
public:
	Jet(int x, int y);
};

class Helicopter: public Enemy
{
public:
	Helicopter(int x, int y);
};

class Balloon: public Enemy
{
public:
	Balloon(int x, int y);
};

#endif