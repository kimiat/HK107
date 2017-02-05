#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <player.h>
#include <QKeyEvent>
#include <QWidget>

class Setup
{
private:
    QGraphicsScene* scene;
    Player* player;
    QGraphicsView* view;
public:
    Setup();
    QGraphicsScene *getScene();
    void game();
};

#endif
