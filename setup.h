#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include "bottom_panel.h"

class Setup: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    Player* player;
    QGraphicsView* view;
    panel* Panel;
public:
    Setup();
    QGraphicsScene *getScene();
    void start();
    void makeEnemies();
public slots:
    void newEnemies();
};

#endif
