#include "mainwindow.h"
#include "setup.h"
#include "enemy.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Setup *setup = new Setup();
    setup->game();
    QGraphicsScene *scene = setup->getScene();
    Enemy *enemy = new Enemy(0, 0, 80, 80, RIGHT);
    scene->addItem(enemy);
    return a.exec();
}
