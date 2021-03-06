#include "missile_ui.h"
#include "enemy_ui.h"
#include "tank.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>

void m_ui::set_pos()
{
    setPos(m->get_x(), m->get_y());
}

void m_ui::remove()
{
    scene()->removeItem(this);
    delete this;
}


m_ui::m_ui(int x, int y)
{
    setPixmap(QPixmap(":/images/missile.png"));
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/shoot.wav"));
    sound->play();
    m = new missile(x, y);
    setPos(m->get_x(), m->get_y());
    setScale(0.2);
    connect(m, SIGNAL(m_moved()), this, SLOT(set_pos()));
    connect(m, SIGNAL(m_removed()), this, SLOT(remove()));
}

m_ui::~m_ui()
{
    delete m;
    delete sound;
}
