#ifndef PLAYER
#define PLAYER

#include "missile.h"
class Player{
    private:
        int x;
        int y;
        int height;
        int width;
    public:
        Player(int x, int y, int width, int height);
        void move_left();
        void move_right();
        int get_x();
        int get_y();
        missile* shoot();

};

#endif // PLAYER

