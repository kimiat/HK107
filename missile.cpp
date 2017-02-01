#include "missile.h"

missile::missile(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int missile::get_x()
{
    return x;
}

int missile::get_y()
{
    return y;
}

void missile::move_up()
{
    y -= 5;
}
