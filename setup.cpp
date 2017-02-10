#include "setup.h"
#include "player.h"
#include "enemy.h"
#include "enemy_ui.h"
#include "player_ui.h"
#include "tank.h"
#include "button.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QVector>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsProxyWidget>

#define p_height 50
#define p_width 50

#define down_pannel_h 150
int height = 700;
int width = 1000;

pair<int, int> startingPos = make_pair(50, 950);
pair<int, int> startingTime = make_pair(700, 1500);
pair<int, int> movingPos = make_pair(50, 600);

using namespace std;

Setup::Setup()
{
    scene = new QGraphicsScene();
//    player = new Player(width / 2 - p_width/2, height - p_height - down_pannel_h - 10, p_width, p_height );
    player = new p_ui();
    player->setPos(width / 2 - p_width / 2 , height - p_height - down_pannel_h - 10);
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
    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(newEnemies()));
    timer->start(randTime);
}


void Setup::drawWindow(int x, int y, int width, int height, double opacity, QColor colour)
{
    QGraphicsRectItem *window = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setColor(colour);
    brush.setStyle(Qt::SolidPattern);
    window->setBrush(brush);
    window->setOpacity(opacity);
    scene->addItem(window);
}

void Setup::drawImage(int x, int y)
{
    QGraphicsPixmapItem *window = new QGraphicsPixmapItem();
    window->setPixmap(QPixmap(":/images/background.png"));
    window->setPos(x, y);
    window->setScale(0.32);
    window->setZValue(2);
    scene->addItem(window);
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
    if(randType == 0)
    {
        enemyui = new s_ui(make_pair(randPos, 0), SHIP_E);
        connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    }
    else if(randType == 1)
    {
        enemyui = new h_ui(make_pair(randPos, 0), HELICOPTER_E);
        connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    }
    else if(randType == 2 && moveType == LEFT)
    {
        enemyui = new j_ui(make_pair(randPos, 0), JET_E);
        connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    }
    else if(randType == 2 && moveType == RIGHT)
    {
        enemyui = new j_ui(make_pair(randPos, 0), JET_E);
        connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    }
    else if(randType == 3)
    {
        enemyui = new b_ui(make_pair(randPos, 0), BALLOON_E);
        connect(enemyui, SIGNAL(gameover()), this, SLOT(endGame()));
    }
    if(enemyui != NULL)
        this->scene->addItem(enemyui);
}

void Setup::endGame()
{
    int n = scene->items().size();
    for(int i = 0; i < n; i++)
        scene->items()[i]->setEnabled(false);
    this->timer->stop();
    this->drawWindow(0, 0, 1000, 700, 0.07, Qt::black);
    this->drawWindow(250, 125, 500, 350, 0.2, Qt::lightGray);
    this->drawImage(200, 110);
    Button *playAgain = new Button(362, 353, QString("Play Again"), scene);
    connect(playAgain, SIGNAL(clicked()), this, SLOT(restartGame()));
    playAgain->setPos(350, 350);
    scene->addItem(playAgain);
    Button *quit = new Button(582, 353, QString("Quit"), scene);
    connect(quit, SIGNAL(clicked()), this, SLOT(exitGame()));
    quit->setPos(550, 350);
    scene->addItem(quit);
    QLabel *gameover, *yourscore;
    yourscore = new QLabel();
    gameover = new QLabel();
    gameover->setText("Game Over!");
    yourscore->setText("Your score is: ");

    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
    QFont font;
    font.setPointSize(17);
    gameover->setFont(font);
    proxy = scene->addWidget(gameover);
    proxy->setPos(435, 200);
    gameover->setAttribute(Qt::WA_TranslucentBackground);
    proxy->setZValue(7);

    yourscore->setFont(font);
    proxy = scene->addWidget(yourscore);
    proxy->setPos(435, 260);
    yourscore->setAttribute(Qt::WA_TranslucentBackground);
    proxy->setZValue(7);

//    QPixmap pim(":/images/background.png");
//    scene->setBackgroundBrush(pim.scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
//    scene->setBackgroundBrush(pim.scaled(100, 100, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void Setup::exitGame()
{
    exit(0);
}

void Setup::restartGame()
{
//    delete player->get_p()->score; //should set score to zero
    delete player;
    delete Panel;
    delete timer;
    delete scene;
    delete view;

    scene = new QGraphicsScene();
    player = new p_ui();
    player->setPos(width / 2 - p_width / 2 , height - p_height - down_pannel_h - 10);
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
    view->show();
    this->makeEnemies();
}
