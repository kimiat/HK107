#ifndef SETUP_H
#define SETUP_H

#include<QGraphicsScene>
#include<QGraphicsView>
#include<player.h>
#include<QKeyEvent>
#include<QWidget>

class setup
{
private:
    QGraphicsScene* scene;
    Player* player;
    QGraphicsView* view;
public:
    setup();
    void game();
};

#endif
