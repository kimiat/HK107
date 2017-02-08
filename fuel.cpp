//
#include "fuel.h"

fuel::fuel(int X, int Y, int Width, int Height)
{
    x = X;
    y = Y;
    width = Width;
    height = Height;
}

void fuel::move_down()
{
    y += 5;
}
