#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

using namespace std;

const int HEIGHT = 600;
const int WIDTH = 600;

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
public:
    Enemy();
    Enemy(int x, int y, unsigned int width, unsigned int height, Movement select);
	pair<int, int> getPosition();
    pair<unsigned int, unsigned int> getSize();
	void moveDown();
	void moveRight();
	void moveLeft();
	~Enemy();
public slots:
    void move();
};

//class Ship: public Enemy
//{
//public:
////    Ship(int x, int y, unsigned int width, unsigned int height, int select);
//};

//class Jet: public Enemy
//{
//public:
////    Jet(int x, int y, unsigned int width, unsigned int height, int select);
//};

//class Helicopter: public Enemy
//{
//public:
////    Helicopter(int x, int y, unsigned int width, unsigned int height, int select);
//};

//class Balloon: public Enemy
//{
//public:
////    Balloon(int x, int y, unsigned int width, unsigned int height, int select);
//};

#endif
