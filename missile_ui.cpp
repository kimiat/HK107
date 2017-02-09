#include "missile_ui.h"
#include "enemy_ui.h"
#include "tank.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>

void m_ui::set_pos()
{
    QList<QGraphicsItem*> destroyedEnemies = collidingItems();
    int n = destroyedEnemies.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(*(destroyedEnemies[i])) == typeid(s_ui))
        {
            qDebug() << "The ship has been destroyed!";
            this->m->getPlayer()->addScore(SHIP);
            qDebug() << this->m->getPlayer()->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(h_ui))
        {
            qDebug() << "The helicopter has been destroyed!";
            this->m->getPlayer()->addScore(HELICOPTER);
            qDebug() << this->m->getPlayer()->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(j_ui))
        {
            qDebug() << "The jet has been destroyed!";
            this->m->getPlayer()->addScore(JET);
            qDebug() << this->m->getPlayer()->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(b_ui))
        {
            qDebug() << "The balloon has been destroyed!";
            this->m->getPlayer()->addScore(BALLOON);
            qDebug() << this->m->getPlayer()->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
        else if(typeid(*(destroyedEnemies[i])) == typeid(Tank))
        {
            qDebug() << "The tank has been destroyed!";
            this->m->getPlayer()->addScore(TANK);
            qDebug() << this->m->getPlayer()->getScore();
            scene()->removeItem(destroyedEnemies[i]);
            scene()->removeItem(this);
            delete destroyedEnemies[i];
            delete this;
            return;
        }
    }
    setPos(m->get_x(), m->get_y());
}

void m_ui::remove()
{
    scene()->removeItem(this);
    delete this;
}


m_ui::m_ui(int x, int y, Player* player)
{
    setPixmap(QPixmap(":/images/missile.png"));
    m = new missile(x, y, player);
    setPos(m->get_x(), m->get_y());
    setScale(0.2);
    connect(m, SIGNAL(m_moved()), this, SLOT(set_pos()));
    connect(m, SIGNAL(m_removed()), this, SLOT(remove()));
}

m_ui::~m_ui()
{
}
