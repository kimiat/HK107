#include "missile.h"
#include <QKeyEvent>
#include<QGraphicsScene>
#include "player.h"
#include<QObject>
#include<QList>
#define speed 5
#define m_height 10
#define m_width 5
#define p_height 700
#define p_width 1000
#define Width 20

#include <iostream>
using namespace std;
//extern int width;
extern int num;
int is_left = 0;
int is_right = 0;

Player::Player(int x, int y)
{
    this->x = x;
    this->y = y;
//    this->height = height;
//    this->width = width;
    fuel = 500;
    score = new Score();
    left_timer = new QTimer();
    right_timer = new QTimer();
    shoot_timer = new QTimer();
    ifuel_timer = new QTimer();
    dfuel_timer = new QTimer();
    connect(right_timer, SIGNAL(timeout()), this, SLOT(move_right()));
    connect(left_timer, SIGNAL(timeout()), this, SLOT(move_left()));
//    connect(shoot_timer, SIGNAL(timeout()), this, SLOT(shoot()));
    connect(shoot_timer, SIGNAL(timeout()), this, SLOT(emit_shoot()));
    connect(ifuel_timer, SIGNAL(timeout()), this, SLOT(inc_fuel()));
    connect(dfuel_timer, SIGNAL(timeout()), this, SLOT(dec_fuel()));
    dfuel_timer->start(100);
}

void Player::move_left()
{
    if(x - speed > 0)
    {
        cout << "x is " << x << endl;
        x -= speed;
        emit positionChanged(x);
    }
}

void Player::move_right()
{
//    cout << "move right " << endl;
//    cout << "width is " <<width<< endl;
    if(x + speed < p_width - Width)
    {
        cout << "x is " << x << endl;
        x += speed;
        emit positionChanged(x);
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

//void Player::shoot()
//{
//    missile* m = new missile(x + 10 - m_width/2, y - m_height, this);
////    connect(m, SIGNAL(m_moved()), this, SLOT(emit_move()));
////    connect(m, SIGNAL(m_removed()), this, SLOT(emit_remove()));
////    m->setPos(m->get_x(), m->get_y());
////    scene()->addItem(m);
//    return;
//}

//void Player::emit_move()
//{
//    emit m_move();
//}

//void Player::emit_remove()
//{
//    emit m_remove();
//}

void Player::keyPress(QKeyEvent *direction)
{
    if(direction->key() == Qt::Key_Left && is_left != 1 && !direction->isAutoRepeat())
    {
        emit changeLeft();
//        setPixmap(QPixmap(":/images/helileft.png"));
        is_left = 1;
//        cout << "must move to the left" << endl;
        left_timer->start(20);
    }
    if(direction->key() == Qt::Key_Right && is_right != 1 && !direction->isAutoRepeat())
    {
        cout << " must move to the right " << endl;
        emit changeRight();
//        setPixmap(QPixmap(":/images/heliright.png"));
        is_right = 1;
        right_timer->start(20);
    }
    if(direction->key() == Qt::Key_Space)
    {
        cout << "num is " << endl;
        if(num <= 0 )
        {
            cout << "must shoot " << endl;

            emit shoot_m();
//            shoot();
            shoot_timer->start(500);
        }
    }
}

void Player::keyRelease(QKeyEvent *direction)
{
    if(direction->key() == Qt::Key_Left && !direction->isAutoRepeat())
    {
        if(!is_right)
            emit straight();
//            setPixmap(QPixmap(":/images/heli.png"));
        is_left = 0;
        left_timer->stop();
    }
    if(direction->key() == Qt::Key_Right && !direction->isAutoRepeat())
    {
        if(!is_left)
            emit straight();
//            setPixmap(QPixmap(":/images/heli.png"));
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

void Player::emit_shoot()
{
    emit shoot_m();
}
