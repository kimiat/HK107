#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QWidget>
#include <QObject>

class Setup: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    Player* player;
    QGraphicsView* view;
public:
    Setup();
    QGraphicsScene *getScene();
    void start();
    void makeEnemies();
public slots:
    void newEnemies();
};

#endif
