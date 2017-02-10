#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

using namespace std;

const int HEIGHT = 700;
const int WIDTH = 800;

static double downSpeed = 3;

enum Movement {DOWN = 1, LEFT = 2, RIGHT = 3};

class Enemy: public QObject
{
	Q_OBJECT
protected:
	pair<int, int> position; //x and y
	// int speed; //how much should it move per millisecond
	QTimer *timer;
	Movement select;
	Movement newSelect;
	int movingPos;
public:
	Enemy();
	Enemy(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect);
	pair<int, int> getPosition();
    int getMovingPos();
    Movement getSelect();
    Movement getNewSelect();
    void stopTimer();
	~Enemy();
signals:
	void moved();
	void destroyed();
public slots:
	void moveDown();
};

class Ship: public Enemy
{
public:
    Ship(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect);
};

class Helicopter: public Enemy
{
public:
    Helicopter(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect);
};

class Balloon: public Enemy
{
public:
    Balloon(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect);
};

class Jet: public Enemy
{
public:
    Jet(pair<int, int> position, int movingPos, double downSpeed, Movement select, Movement newSelect);
};

#endif
