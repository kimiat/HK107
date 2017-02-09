#include "player_ui.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "missile_ui.h"
#include<iostream>
using namespace std;
#define down_pannel_h 150
#define height  700
#define width  1000

p_ui::p_ui()
{
    setPixmap(QPixmap(":/images/heli.png"));
    setScale(0.8);
    p = new Player(width / 2 , height - down_pannel_h - 60);
    setPos(p->get_x(), p->get_y());
    connect(p, SIGNAL(changeLeft()), this, SLOT(setPicLeft()));
    connect(p, SIGNAL(changeRight()), this, SLOT(setPicRight()));
    connect(p, SIGNAL(straight()), this, SLOT(setPicStraight()));
    connect(p, SIGNAL(positionChanged(int)), this, SLOT(changePos()));
    connect(p, SIGNAL(shoot_m()), this, SLOT(create_m()));
//    connect(p->get_m(), SIGNAL(m_moved()), this, SLOT(moveMissile()));
//    connect(p->get_m(), SIGNAL(m_removed()), this, SLOT(removeMissile()));
}

void p_ui::keyPressEvent(QKeyEvent *direction)
{
//    cout << "key is pressed";
    p->keyPress(direction);
}

void p_ui::keyReleaseEvent(QKeyEvent *direction)
{
//    cout <<"key is released";
    p->keyRelease(direction);
}

void p_ui::changePos()
{
//    cout << "in the changepos" << endl;
    cout << "in the changepos " << endl;
    setPos(p->get_x(), p->get_y());
}

void p_ui::setPicLeft()
{
    setPixmap(QPixmap(":/images/helileft.png"));
}

void p_ui::setPicRight()
{
    setPixmap(QPixmap(":/images/heliright.png"));
}

//void p_ui::showMissile()
//{
//    p->get_m()->setRect(0, 0, 10, 20);
//    p->get_m()->setPos(p->get_m()->get_x(), p->get_m()->get_y());
//    scene()->addItem(p->get_m());
//}

void p_ui::create_m()
{
    cout << " missile is createrd" << endl;
    m_ui* Missile = new m_ui(p->get_x() + 20, p->get_y() - 15, p);
    scene()->addItem(Missile);
    cout << " after creating " << endl;
//    p->get_m()->setPos(p->get_m()->get_x(), p->get_m()->get_y());
}

//void p_ui::removeMissile()
//{
//    scene()->removeItem(p->get_m());
//}

void p_ui::setPicStraight()
{
    setPixmap(QPixmap(":/images/heli.png"));
}
