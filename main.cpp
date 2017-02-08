//
#include "setup.h"
#include "enemy.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Setup *setup = new Setup();
    setup->start();
    QGraphicsScene *scene = setup->getScene();
//    Ship *enemy1 = new Ship(395, 0, 50, 50, 0, DOWN, DOWN);
//    Jet *enemy2 = new Jet(300, 300, 60, 60, DOWN);
//    scene->addItem(enemy1);
//    scene->addItem(enemy2);
    setup->makeEnemies();
    return a.exec();
}
