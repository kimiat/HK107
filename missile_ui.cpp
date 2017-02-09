#include "missile_ui.h"
#include <QGraphicsScene>
void m_ui::set_pos()
{
    setPos(m->get_x(), m->get_y());
//    setPos(m->get_y());
}

void m_ui::remove()
{
    cout << " helloo" << endl;
    scene()->removeItem(this);
    cout << " this is here  " << endl;
//    delete m;
    delete this;
}


m_ui::m_ui(int x, int y, Player* player)
{
    setPixmap(QPixmap(":/images/missile.png"));
    m = new missile(x, y, player);
    setPos(m->get_x(), m->get_y());
    setScale(0.2);
//    cout << " this is here " << endl;
//    scene()->addItem(this);
//    cout << " this is after " << endl;
    connect(m, SIGNAL(m_moved()), this, SLOT(set_pos()));
    connect(m, SIGNAL(m_removed()), this, SLOT(remove()));
}

m_ui::~m_ui()
{
    cout << " in the destructor" << endl;
//    delete m;
}
