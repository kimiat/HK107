#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "score.h"
#include <QTimer>
#include <QObject>

class missile;

class Player :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int x;
    int y;
    int height;
    int width;
    int fuel;
    Score *score;
    QTimer* left_timer;
    QTimer* right_timer;
    QTimer* shoot_timer;
    QTimer* ifuel_timer;
    QTimer* dfuel_timer;
public:
    Player(int x, int y, int width, int height);
    int get_x();
    int get_y();
    int get_height();
    int get_width();
    void keyPressEvent(QKeyEvent *direction);
    void keyReleaseEvent(QKeyEvent *direction);
    void addScore(Object destroyed);
    int getScore();
public slots:
    void move_left();
    void move_right();
    void shoot();
};

#endif
