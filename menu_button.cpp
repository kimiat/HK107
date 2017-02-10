#include "menu_button.h"
#include <QObject>
#include <QPixmap>
#include <iostream>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QGraphicsProxyWidget>

using namespace std;

menu_button::menu_button() {}

menu_button::menu_button(int x, int y, BtnType type, qreal rotate)
{
    if(type == PLAY)
        setPixmap(QPixmap(":/images/play.png"));
    else if(type == HIGHSCORES)
        setPixmap(QPixmap(":/images/highscores.png"));
    else if(type == CREDITS)
        setPixmap(QPixmap(":/images/credits.png"));
    else if(type == EXIT)
        setPixmap(QPixmap(":/images/exit.png"));
    else if(type == BACK)
        setPixmap(QPixmap(":/images/back.png"));
    this->type = type;
    setRotation(rotate);
    setPos(x, y);
    setScale(0.3);
    setZValue(13);
    setAcceptHoverEvents(true);
    timer = b_timer = NULL;
}

void menu_button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(type == PLAY)
        setPixmap(QPixmap(":/images/playlight.png"));
    else if(type == HIGHSCORES)
        setPixmap(QPixmap(":/images/highscoreslight.png"));
    else if(type == CREDITS)
        setPixmap(QPixmap(":/images/creditslight.png"));
    else if(type == EXIT)
        setPixmap(QPixmap(":/images/exitlight.png"));
    else if(type == BACK)
        setPixmap(QPixmap(":/images/backlight.png"));
    setScale(0.3);
    timer = new QTimer();
    timer->start(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeColour()));
}

void menu_button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(type == PLAY)
        setPixmap(QPixmap(":/images/playlight.png"));
    else if(type == HIGHSCORES)
        setPixmap(QPixmap(":/images/highscoreslight.png"));
    else if(type == CREDITS)
        setPixmap(QPixmap(":/images/creditslight.png"));
    else if(type == EXIT)
        setPixmap(QPixmap(":/images/exitlight.png"));
    else if(type == BACK)
        setPixmap(QPixmap(":/images/backlight.png"));
}

void menu_button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(type == PLAY)
        setPixmap(QPixmap(":/images/play.png"));
    else if(type == HIGHSCORES)
        setPixmap(QPixmap(":/images/highscores.png"));
    else if(type == CREDITS)
        setPixmap(QPixmap(":/images/credits.png"));
    else if(type == EXIT)
        setPixmap(QPixmap(":/images/exit.png"));
    else if(type == BACK)
        setPixmap(QPixmap(":/images/back.png"));
}

menu_button::~menu_button()
{
    if(timer != NULL)
        delete timer;
    if(b_timer != NULL)
        delete b_timer;
}

void menu_button::changeColour()
{
    if(type == PLAY)
        setPixmap(QPixmap(":/images/play.png"));
    else if(type == HIGHSCORES)
        setPixmap(QPixmap(":/images/highscores.png"));
    else if(type == CREDITS)
        setPixmap(QPixmap(":/images/credits.png"));
    else if(type == EXIT)
        setPixmap(QPixmap(":/images/exit.png"));
    else if(type == BACK)
        setPixmap(QPixmap(":/images/back.png"));
    setScale(0.3);
    b_timer = new QTimer();
    b_timer->start(100);
    connect(b_timer, SIGNAL(timeout()), this, SLOT(changeColourBack()));
}

void menu_button::changeColourBack()
{
    if(type == PLAY)
        emit playclicked();  //setup->makeEnemies();
    else if(type == HIGHSCORES)
        emit scoresclicked();
    else if(type == CREDITS)
        emit creditsclicked();
    else if(type == EXIT)
        emit exitclicked();
    else if(type == BACK)
        emit backclicked();
}
