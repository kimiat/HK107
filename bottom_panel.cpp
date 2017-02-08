#include "bottom_panel.h"
#define s_height 700
#define s_width 1000
#define p_height 150

panel::panel()
{
    gauge = new QGraphicsPixmapItem();
    gauge->setPixmap(QPixmap(":/images/F.jpg"));
    gauge->setPos(s_width / 2 - 60, s_height - p_height );
    gauge->setZValue(9);
    gauge->setScale(0.5);
    needle = new QGraphicsPixmapItem();
    needle->setPixmap(QPixmap(":/images/needle.png"));
    needle->setPos(s_width / 2 + 75, s_height - p_height + 25.5 );
    needle->setZValue(10);
    needle->setScale(0.021);
    setPixmap(QPixmap(":/images/b_panel.jpg"));
    setPos(0, s_height - p_height);
    setScale(6);
    setZValue(8);
    amount = new fuel();
    connect(amount, SIGNAL(fuelDec(int)), this, SLOT(set_posl()));
    connect(amount, SIGNAL(fuelInc(int)), this, SLOT(set_posr()));
}

QGraphicsPixmapItem *panel::getGauge()
{
    return gauge;
}

QGraphicsPixmapItem *panel::getNeedle()
{
    return needle;
}

fuel *panel::getFuel()
{
    return amount;
}

void panel::set_posl()
{
    needle->setPos(needle->x() - 1.32, needle->y());
}

void panel::set_posr()
{
    if(needle->x() + 5 < s_width / 2 + 75 )
        needle->setPos(needle->x() + 5, needle->y());
}


