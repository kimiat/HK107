#ifndef PLAYER_H
#define PLAYER_H

#include "score.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QObject>

class missile;

class Player :public QObject{
    Q_OBJECT
private:
    int x;
    int y;
    int fuel;
    Score *score;
    QTimer* left_timer;
    QTimer* right_timer;
    QTimer* shoot_timer;
    QTimer* ifuel_timer;
    QTimer* dfuel_timer;
public:
    Player(int x, int y);
    int get_x();
    int get_y();
    int get_height();
    int get_width();
    bool over;
    void keyPress(QKeyEvent *direction);
    void keyRelease(QKeyEvent *direction);
    void addScore(Object destroyed);
    ~Player();
signals:
    void changeLeft();
    void changeRight();
    void straight();
    void positionChanged(int xVal);
    void shoot_m();
    void scoreChanged();
    void gameover();
public slots:
    void emit_shoot();
    void move_left();
    void move_right();
    int getScore();
    void stopMoving();
};

#endif
