#include "missile.h"
#include <QKeyEvent>
#include<QGraphicsScene>
#include "player.h"
#define speed 5
#define m_height 10
#define m_width 5
#define p_height 600
#define p_width 800
#include<iostream>
using namespace std;
extern int width;
extern int num;
Player::Player(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    setRect(0,0, width, height);
    fuel = 500;
}

void Player::move_left()
{
    if(x - speed > 0)
        x -= speed;
}

void Player::move_right()
{
    if(x + speed < p_width - width)
        x += speed;
}

void Player::inc_fuel()
{
    fuel += 10;
}

void Player::dec_fuel()
{
    fuel -= 3;
}
int Player::get_x()
{
    return x;
}

int Player::get_y()
{
    return y;
}

//int Player::get_height()
//{
//    return height;
//}

//int Player::get_width()
//{
//    return width;
//}

void Player::shoot()
{
    missile* m = new missile(x + width/2 - m_width/2, y - m_height, m_width, m_height);
    m->setPos(m->get_x(), m->get_y());
    scene()->addItem(m);
    return;
}

void Player::keyPressEvent(QKeyEvent *direction)
{
    if(direction->key() == Qt::Key_Left)
    {
        move_left();
        setPos(get_x(), get_y());
    }
    if(direction->key() == Qt::Key_Right)
    {
        move_right();
        setPos(get_x(), get_y());
    }
    if(direction->key() == Qt::Key_Space)
    {
        if(num <= 1)
            shoot();
    }
}
