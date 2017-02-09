#include "enemy_ui.h"
#include "player.h"
#include <QGraphicsScene>
#include <iostream>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>

using namespace std;

e_ui::e_ui() {}

e_ui::e_ui(pair<int, int> position, ObjectType type)
{
//    switch(type)
//    {
//    case SHIP_E:
//        this->enemy = new Ship(position, 0, 3, DOWN, DOWN);
//        break;
//    case HELICOPTER_E:
//        this->enemy = new Helicopter(position, 0, 3, DOWN, DOWN);
//        break;
//    case BALLOON_E:
//        this->enemy = new Balloon(position, 0, 3, DOWN, DOWN);
//        break;
//    case JET_E:
//        this->enemy = new Jet(position, 0, 3, DOWN, DOWN);
//        break;
//    }
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}

void e_ui::changePos()
{
    checkLosing();
    setPos(enemy->getPosition().first, enemy->getPosition().second);
}

void e_ui::remove()
{
    scene()->removeItem(this);
    delete this;
}

void e_ui::checkLosing()
{
    QList<QGraphicsItem*> check = collidingItems();
    int n = check.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(*(check[i])) == typeid(Player))
        {
            cout << "This is a player item!";
            cout << "You LOSE!";
            emit gameover();
//            exit(0);
//            scene()->removeItem(check[i]);
//            scene()->removeItem(this);
//            delete check[i];
//            delete this;
//            return;
        }
    }
}

s_ui::s_ui(pair<int, int> position, ObjectType type)
{
    this->enemy = new Ship(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/shipright.png"));
    setScale(0.11);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}

h_ui::h_ui(pair<int, int> position, ObjectType type)
{
    this->enemy = new Helicopter(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/helicopterleft.png"));
    setScale(0.85);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}


b_ui::b_ui(pair<int, int> position, ObjectType type)
{
    this->enemy = new Balloon(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/balloon.png"));
    setScale(0.06);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}

j_ui::j_ui(pair<int, int> position, ObjectType type)
{
    this->enemy = new Jet(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/jetright.png"));
    setScale(0.13);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}
