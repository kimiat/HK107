#include <QObject>
#include "tank.h"
#include "enemy.h"
#include <iostream>
#include <QGraphicsScene>
#include <QDebug>
#include "missile_ui.h"
#include <typeinfo>
#include "player_ui.h"
#include "player.h"

#define DOWNPANEL_H 80

using namespace std;

Tank::Tank(int x, int y, double downSpeed, Player* p)
{
    shot_num = 0;
    player = p;
    this->position.first = x;
    this->position.second = y;
    setPixmap(QPixmap(":/images/gas.png"));
    setScale(0.15);
    setPos(x, y);
    isRemoved = false;
    this->timer = new QTimer();
    check = new QTimer();
    exp = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(exp, SIGNAL(timeout()), this, SLOT(explode()));
    connect(check, SIGNAL(timeout()), this, SLOT(check_c()));
    timer->start(30);
    check->start(1);
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/explode.mp3"));
}

Tank::~Tank()
{
    delete check;
    delete exp;
    delete sound;
    delete timer;
}

void Tank::move()
{
    QList<QGraphicsItem*> items = collidingItems();
    int size = items.size();
    for(int i = 0; i < size; i++)
         if(typeid(*(items[i])) == typeid(p_ui) && isRemoved == false)
         {
             emit getFuel();
         }
         else
             emit stop();
    this->position.second += downSpeed;
    downSpeed += 0.01;
    bool flag = true;
    if(position.second > HEIGHT - DOWNPANEL_H)
    {
        scene()->removeItem(this);
        delete this;
        flag = false;
        qDebug() << "Fuel removed and deleted!";
    }
    if(flag)
        setPos(position.first, position.second);
}

void Tank::check_c()
{
//    cout << "checking " << endl;
    if(isRemoved == false)
    {
        QList<QGraphicsItem*> items = collidingItems();
        int n = items.size();
        for(int i = 0; i < n; i++)
        {
            if(typeid(*(items[i])) == typeid(m_ui))
            {
                isRemoved = true;
                player->addScore(TANK);
                scene()->removeItem(items[i]);
                delete items[i];
                exp->start(100);
                sound->play();
                return;
            }
        }
    }
}

void Tank::explode()
{
    if(shot_num  == 0)
        setPixmap(QPixmap(":/explosion/e1.png"));
    if(shot_num  == 1)
        setPixmap(QPixmap(":/explosion/e2.png"));
    if(shot_num  == 2)
        setPixmap(QPixmap(":/explosion/e3.png"));
    if(shot_num  == 3)
        setPixmap(QPixmap(":/explosion/e4.png"));
    if(shot_num  == 4)
        setPixmap(QPixmap(":/explosion/e5.png"));
    if(shot_num  == 5)
        setPixmap(QPixmap(":/explosion/e6.png"));
    if(shot_num  == 6)
        setPixmap(QPixmap(":/explosion/e7.png"));
    if(shot_num  == 7)
        setPixmap(QPixmap(":/explosion/e8.png"));
    if(shot_num  == 8)
        setPixmap(QPixmap(":/explosion/e9.png"));
    if(shot_num  == 9)
        setPixmap(QPixmap(":/explosion/e10.png"));
    if(shot_num  == 10)
        setPixmap(QPixmap(":/explosion/e11.png"));
    if(shot_num  == 11)
        setPixmap(QPixmap(":/explosion/e12.png"));
    if(shot_num  == 12)
        setPixmap(QPixmap(":/explosion/e13.png"));
    if(shot_num  == 13)
        setPixmap(QPixmap(":/explosion/e14.png"));
    if(shot_num  == 14)
        setPixmap(QPixmap(":/explosion/e15.png"));
    if(shot_num  == 15)
        setPixmap(QPixmap(":/explosion/e16.png"));
    if(shot_num >= 16)
    {
        exp->stop();
        delete this;
    }
    else
    {
        setScale(1.2);
        shot_num++;
    }
}

void Tank::stopMoving()
{
    timer->stop();
    check->stop();
}
