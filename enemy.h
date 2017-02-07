#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

using namespace std;

const int HEIGHT = 600;
const int WIDTH = 800;

enum Movement {DOWN = 1, LEFT = 2, RIGHT = 3};

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
protected:
	pair<int, int> position; //x and y
	pair<unsigned int, unsigned int> size; //width and height
	int speed; //how much should it move per millisecond
    QTimer *timer;
    Movement select;
    Movement newSelect;
    int movingPos;
public:
    Enemy();
    Enemy(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect);
	pair<int, int> getPosition();
    pair<unsigned int, unsigned int> getSize();
    bool moveDown();
    bool moveRight();
    bool moveLeft();
    void checkLosing();
	~Enemy();
public slots:
    void move();
};

class Ship: public Enemy
{
public:
    Ship(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect);
};

class Jet: public Enemy
{
public:
    Jet(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect);
};

class Helicopter: public Enemy
{
public:
    Helicopter(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect);
};

class Balloon: public Enemy
{
public:
    Balloon(int x, int y, unsigned int width, unsigned int height, int movingPos, Movement select, Movement newSelect);
};

#endif
