#include "missile.h"
#include <QTimer>
#include<iostream>
#include<QGraphicsScene>
#define speed 5
using namespace std;
int num = 0;
missile::missile(int x, int y, int width, int height)
{
    setRect(0, 0, width, height);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    num++;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up()));
    timer->start(10);
}

int missile::get_x()
{
    return x;
}

int missile::get_y()
{
    return y;
}

int missile::get_height()
{
    return height;
}

int get_num()
{
    return num;
}

void missile::move_up()
{
    y -= speed;
    setPos(get_x(), get_y() - 10);
    if(get_y() < 0 - get_height())
    {
        scene()->removeItem(this);
        delete this;
    }

}

missile::~missile()
{
    delete timer;
    num--;
}

