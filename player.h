#ifndef PLAYER
#define PLAYER

#include "missile.h"
class Player{
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
        missile* shoot();

};

#endif // PLAYER

