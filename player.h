#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsRectItem>
#include "missile.h"
#include "score.h"

class Player: public QGraphicsRectItem
{
private:
    int x;
    int y;
    int height;
    int width;
    int fuel;
    Score *score;
public:
    Player(int x, int y, int width, int height);
    void move_left();
    void move_right();
    void inc_fuel();
    void dec_fuel();
    int get_x();
    int get_y();
    int get_height();
    int get_width();
    void shoot();
    void keyPressEvent(QKeyEvent *direction);
};

#endif

