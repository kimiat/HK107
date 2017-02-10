#include "enemy_ui.h"
#include "missile_ui.h"
#include "player.h"
#include <QGraphicsScene>
#include <iostream>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>
using namespace std;

e_ui::e_ui() {
    shot_num = 0;
    check = new QTimer();
    connect(check, SIGNAL(timeout()), this, SLOT(check_c()));
    exp = new QTimer();
    connect(exp, SIGNAL(timeout()), this, SLOT(explode()));
    check->start(1);
    isRemoved = false;
    gameOver = false;
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/explode.mp3"));
}

e_ui::e_ui(pair<int, int> position, Player* p)
{
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

void e_ui::check_c()
{
    if(isRemoved == false)
    {
        QList<QGraphicsItem*> items = collidingItems();
        int n = items.size();
        for(int i = 0; i < n; i++)
        {
            if(typeid(*(items[i])) == typeid(m_ui))
            {
                isRemoved = true;
                if(type == SHIP_E)
                {
                    player->addScore(SHIP);
                }
                if(type == HELICOPTER_E)
                {
                    player->addScore(HELICOPTER);
                }
                if(type == JET_E)
                {
                    player->addScore(JET);
                }
                if(type == BALLOON_E)
                {
                    player->addScore(BALLOON);
                }
                scene()->removeItem(items[i]);
                delete items[i];
                exp->start(100);
                sound->play();
                return;
            }
        }
    }
}

void e_ui::explode()
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

void e_ui::stopMoving()
{
    enemy->stopTimer();
}

void e_ui::checkLosing()
{
    if(isRemoved == false)
    {
        QList<QGraphicsItem*> check = collidingItems();
        int n = check.size();
        for(int i = 0; i < n; i++)
        {
            if(typeid(*(check[i])) == typeid(p_ui) && !gameOver)
            {
                cout << "This is a player item!";
                cout << "You LOSE!";
                emit gameover();
                gameOver = true;
    //            exit(0);
    //            scene()->removeItem(check[i]);
    //            scene()->removeItem(this);
    //            delete check[i];
    //            delete this;
    //            return;
            }
        }
    }
}

Player *e_ui::getPlayer()
{
    return player;
}

e_ui::~e_ui()
{
    delete enemy;
    delete check;
    delete exp;
    delete sound;
//    cout << "it is over " << endl;
}

s_ui::s_ui(pair<int, int> position, Player* p)
{
    type = SHIP_E;
    player = p;
    cout << " ship is made " << endl;
    this->enemy = new Ship(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/shipright.png"));
    setScale(0.11);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}

h_ui::h_ui(pair<int, int> position, Player* p)
{
    type = HELICOPTER_E;
    player = p;
    this->enemy = new Helicopter(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/helicopterleft.png"));
    setScale(0.85);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}


b_ui::b_ui(pair<int, int> position, Player* p)
{
    type = BALLOON_E;
    player = p;
    this->enemy = new Balloon(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/balloon.png"));
    setScale(0.06);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}

j_ui::j_ui(pair<int, int> position, Player* p)
{
    type = JET_E;
    player = p;
    this->enemy = new Jet(position, 0, 3, DOWN, DOWN);
    setPixmap(QPixmap(":/images/jetright.png"));
    setScale(0.13);
    setPos(position.first, position.second);
    connect(enemy, SIGNAL(moved()), this, SLOT(changePos()));
    connect(enemy, SIGNAL(destroyed()), this, SLOT(remove()));
}
