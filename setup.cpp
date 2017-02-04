#include "setup.h"
#include "player.h"
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#define p_height 50
#define p_width 50
int height = 600;
int width = 800;
setup::setup()
{
    scene = new QGraphicsScene();
    player = new Player(width / 2 - p_width/2, height - p_height, p_width, p_height );
    player->setPos(width / 2 - p_width/2, height - p_height);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    view = new QGraphicsView(scene);
    view->setFixedSize(width, height);
    scene->setSceneRect(0,0, width, height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addItem(player);
}

void setup::game()
{
    view->show();
}
