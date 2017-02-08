//
#ifndef FUEL_H
#define FUEL_H

class fuel
{
private:
    int x;
    int y;
    int height;
    int width;
public:
    fuel(int X, int Y, int Width, int Height);
    void move_down();
};

#endif

