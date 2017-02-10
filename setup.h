#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player_ui.h"
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
    p_ui* player;
    QGraphicsView* view;
    panel* Panel;
    QTimer *timer;
public:
    Setup();
    QGraphicsScene *getScene();
    void start();
    void makeEnemies();
    void drawWindow(int x, int y, int width, int height, double opacity, QColor colour);
    void drawImage(int x, int y);
public slots:
    void newEnemies();
    void endGame();
    void restartGame();
    void exitGame();
};

#endif
