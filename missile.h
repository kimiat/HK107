#ifndef MISSILE_H
#define MISSILE_H
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
//#include "player.h"

class Player;

class missile:public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
private:
    int x;
    int y;
    int height;
    int width;
    QTimer* timer;
    Player *player;
public:
    missile(int x, int y, int width, int height, Player *player);
    int get_x();
    int get_y();
    ~missile();
    int get_height();
public slots:
    void move_up();
};

#endif

