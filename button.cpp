//
#include "button.h"
#include <QObject>
#include <QPixmap>
#include <iostream>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>
#include <QGraphicsProxyWidget>

using namespace std;

Button::Button() {}

Button::Button(int x, int y, QString text, QGraphicsScene *scene)
{
    setPixmap(QPixmap(":/images/button.png"));
    setScale(0.35);
    setZValue(5);
    this->label = new QLabel;
    label->setText(text);
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
    QFont font;
    font.setPointSize(11);
    label->setFont(font);
    proxy = scene->addWidget(label);
    proxy->setPos(x, y);
    label->setAttribute(Qt::WA_TranslucentBackground);
    proxy->setZValue(7);
    setAcceptHoverEvents(true);
}

//void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
//{
////    scene()->removeItem(this);
//    setPos(x() + 15, y() - 2);
////    scene()->removeItem(this);
////    scene()->addItem(this);
//}

//void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
//{
//    setPos(x() - 15, y() + 2);
//}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setPixmap(QPixmap(":/images/buttonlight.png"));
    setScale(0.35);
    timer = new QTimer();
    timer->start(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeColour()));
}

void Button::changeColour()
{
    setPixmap(QPixmap(":/images/button.png"));
    setScale(0.35);
    b_timer = new QTimer();
    b_timer->start(100);
    connect(b_timer, SIGNAL(timeout()), this, SLOT(changeColourBack()));
}

void Button::changeColourBack()
{
    emit clicked();
}
