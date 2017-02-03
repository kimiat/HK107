#include "missile.h"
#include "player.h"
Player::Player(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    fuel = 500;
}

void Player::move_left()
{
    x -= 5;
}

void Player::move_right()
{
    x += 5;
}

void Player::inc_fuel()
{
    fuel += 10;
}

void Player::dec_fuel()
{
    fuel -= 3;
}
int Player::get_x()
{
    return x;
}

int Player::get_y()
{
    return y;
}

missile* Player::shoot()
{
    int m_height;
    int m_width;
    missile* m = new missile(x + width/2 - m_width/2, y - m_height, m_width, m_height);
    return m;
}
