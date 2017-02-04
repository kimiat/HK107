#ifndef PLAYER
#define PLAYER

#include<QGraphicsRectItem>
#include "missile.h"

class Player :public QGraphicsRectItem{
    private:
        int x;
        int y;
        int height;
        int width;
        int fuel;
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

#endif // PLAYER

