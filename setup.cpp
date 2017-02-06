#include "setup.h"
#include "player.h"
#include "enemy.h"
#include "tank.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>
#include <QDebug>

#define p_height 50
#define p_width 50
#define down_pannel_h 80

int height = 600;
int width = 800;

pair<int, int> startingPos = make_pair(100, 500);
pair<int, int> startingTime = make_pair(700, 1500);
pair<int, int> movingPos = make_pair(50, 500);

using namespace std;

Setup::Setup()
{
    scene = new QGraphicsScene();
    player = new Player(width / 2 - p_width/2, height - p_height - down_pannel_h, p_width, p_height );
    player->setPos(width / 2 - p_width/2 , height - p_height - down_pannel_h);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    view = new QGraphicsView(scene);
    view->setFixedSize(width, height);
    scene->setSceneRect(0,0, width, height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addItem(player);
    Panel = new panel();
    scene->addItem(Panel);
}

QGraphicsScene *Setup::getScene()
{
    return this->scene;
}

void Setup::start()
{
    view->show();
}

void Setup::makeEnemies()
{
    int randTime;
    srand(time(NULL));
    randTime = rand() % (startingTime.second - startingTime.first) + startingTime.first;
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(newEnemies()));
    timer->start(randTime);
}

void Setup::newEnemies()
{
    srand(time(NULL));
    int randPos, randMove, randType, randStart, randWay, randTank;
    Movement moveType;
    randPos = rand() % (startingPos.second - startingPos.first) + startingPos.first;
    randStart = rand() % (movingPos.second - movingPos.first) + movingPos.first;
    randType = rand() % 2;
    randWay = rand() % 2;
    randTank = rand() % 2;
    randMove = rand() % 10;
    if(randTank)
    {
        Tank *tank = new Tank(randPos, 0, 20, 60);
        this->scene->addItem(tank);
        return;
    }
    if(randWay && randMove > 6)
        moveType = LEFT;
    else if(!randWay && randMove > 6)
        moveType = RIGHT;
    else
        moveType = DOWN;
    Enemy *enemy;
    if(randType)
    {
        enemy = new Ship(randPos, 0, 40, 80, randStart, DOWN, moveType);
    }
    else
    {
        enemy = new Helicopter(randPos, 0, 60, 60, randStart, DOWN, moveType);
    }
    this->scene->addItem(enemy);
}
