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
//    int height;
//    int width;
    int fuel;
    Score *score;
    QTimer* left_timer;
    QTimer* right_timer;
    QTimer* shoot_timer;
    QTimer* ifuel_timer;
    QTimer* dfuel_timer;
//    missile* m;
public:
    Player(int x, int y);
    int get_x();
    int get_y();
    int get_height();
    int get_width();
//    missile* get_m();
    void keyPress(QKeyEvent *direction);
    void keyRelease(QKeyEvent *direction);
    void addScore(Object destroyed);
    int getScore();
signals:
    void changeLeft();
    void changeRight();
    void straight();
    void positionChanged(int xVal);
    void shoot_m();

//    void m_move();
//    void m_remove();
public slots:
    void emit_shoot();
    void move_left();
    void move_right();
//    void shoot();
//    void emit_move();
//    void emit_remove();
};

#endif
