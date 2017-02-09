#include "setup.h"
#include "player.h"
#include "enemy.h"
#include "enemy_ui.h"
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

#define down_pannel_h 150
int height = 700;
int width = 1000;

pair<int, int> startingPos = make_pair(100, 500);
pair<int, int> startingTime = make_pair(700, 1500);
pair<int, int> movingPos = make_pair(50, 500);

using namespace std;

Setup::Setup()
{
    scene = new QGraphicsScene();
    player = new Player(width / 2 - p_width/2, height - p_height - down_pannel_h - 10, p_width, p_height );
    player->setPos(width / 2 - p_width/2 , height - p_height - down_pannel_h - 10);
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
    scene->addItem(Panel->getGauge());
    scene->addItem(Panel->getNeedle());
//    scene->addItem(Panel->getNeedle());
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
//    if(downSpeed <= 12)
//        downSpeed += 0.3;
    int randPos, randMove, randType, randStart, randWay, randTank;
    Movement moveType;
    randPos = rand() % (startingPos.second - startingPos.first) + startingPos.first;
    randStart = rand() % (movingPos.second - movingPos.first) + movingPos.first;
    randType = rand() % 4;
    randWay = rand() % 2;
    randTank = rand() % 3;
    randMove = rand() % 10;
    if(!randTank)
    {
        Tank *tank = new Tank(randPos, 0, 20, 60, downSpeed);
        connect(tank, SIGNAL(getFuel()), Panel->getFuel(), SLOT(inc_fuel()));
        this->scene->addItem(tank);
        return;
    }
    if(randWay && randMove > 6)
        moveType = LEFT;
    else if(!randWay && randMove > 6)
        moveType = RIGHT;
    else
        moveType = DOWN;
    e_ui *enemyui = NULL;
//    connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    if(randType == 0)
        enemyui = new s_ui(make_pair(randPos, 0), SHIP_E);
//        enemy = new Ship(make_pair(randPos, 0), randStart, downSpeed, DOWN, moveType);
    else if(randType == 1)
        enemyui = new h_ui(make_pair(randPos, 0), HELICOPTER_E);
//        enemy = new Helicopter(make_pair(randPos, 0), randStart, downSpeed, DOWN, moveType);
    else if(randType == 2 && moveType == LEFT)
        enemyui = new j_ui(make_pair(randPos, 0), JET_E);
//        enemy = new Jet(make_pair(600, randPos), randStart, downSpeed, moveType, moveType);
    else if(randType == 2 && moveType == RIGHT)
        enemyui = new j_ui(make_pair(randPos, 0), JET_E);
//        enemy = new Jet(make_pair(600, randPos), randStart, downSpeed, moveType, moveType);
    else if(randType == 3)
        enemyui = new b_ui(make_pair(randPos, 0), BALLOON_E);
//        enemy = new Balloon(make_pair(randPos, 0), randStart, downSpeed, DOWN, DOWN);
    if(enemyui != NULL)
        this->scene->addItem(enemyui);
}

void Setup::endGame()
{
    cout << "end game!";
    exit(0);
}
