#include "missile.h"
#include <QKeyEvent>
#include<QGraphicsScene>
#include "player.h"
#include<QObject>
#include<QList>
#define speed 5
#define m_height 10
#define m_width 5
//
#define p_height 700
#define p_width 1000
#include <iostream>
using namespace std;
extern int width;
extern int num;
int is_left = 0;
int is_right = 0;

Player::Player(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    setRect(0,0, width, height);
    fuel = 500;
    score = new Score();
    left_timer = new QTimer();
    right_timer = new QTimer();
    shoot_timer = new QTimer();
    ifuel_timer = new QTimer();
    dfuel_timer = new QTimer();
    connect(right_timer, SIGNAL(timeout()), this, SLOT(move_right()));
    connect(left_timer, SIGNAL(timeout()), this, SLOT(move_left()));
    connect(shoot_timer, SIGNAL(timeout()), this, SLOT(shoot()));
    connect(ifuel_timer, SIGNAL(timeout()), this, SLOT(inc_fuel()));
    connect(dfuel_timer, SIGNAL(timeout()), this, SLOT(dec_fuel()));
    dfuel_timer->start(100);
}

void Player::move_left()
{
    if(x - speed > 0)
    {
        x -= speed;
        setPos(get_x(), get_y());
    }
}

void Player::move_right()
{
    if(x + speed < p_width - width)
    {
        x += speed;
        setPos(get_x(), get_y());
    }
}

int Player::get_x()
{
    return x;
}

int Player::get_y()
{
    return y;
}

void Player::shoot()
{
    missile* m = new missile(x + width/2 - m_width/2, y - m_height, m_width, m_height, this);
    m->setPos(m->get_x(), m->get_y());
    scene()->addItem(m);
    return;
}

void Player::keyPressEvent(QKeyEvent *direction)
{
    if(direction->key() == Qt::Key_Left && is_left != 1 && !direction->isAutoRepeat())
    {
        is_left = 1;
        left_timer->start(20);
    }
    if(direction->key() == Qt::Key_Right && is_right != 1 && !direction->isAutoRepeat())
    {
        is_right = 1;
        right_timer->start(20);
    }
    if(direction->key() == Qt::Key_Space)
    {
        if(num <= 0 )
        {
            shoot();
            shoot_timer->start(500);
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *direction)
{
    if(direction->key() == Qt::Key_Left && !direction->isAutoRepeat())
    {
        is_left = 0;
        left_timer->stop();
    }
    if(direction->key() == Qt::Key_Right && !direction->isAutoRepeat())
    {
        is_right = 0;
        right_timer->stop();
    }
    if(direction->key() == Qt::Key_Space && !direction->isAutoRepeat())
    {
        is_right = 0;
        shoot_timer->stop();
    }
}

void Player::addScore(Object destroyed)
{
    score->addScore(destroyed);
}

int Player::getScore()
{
    return score->getScore();
}
