#include "bottom_panel.h"
#define s_height 700
#define s_width 1000
#define p_height 80
#include<iostream>
#include<QMediaPlayer>
#include <QFrame>

using namespace std;
panel::panel(Player* p)
{
    over = false;
    player = p;
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
    score = new QLCDNumber(8);
    score->setSegmentStyle(QLCDNumber::Flat);
    score->display(0);
    lcd_palette.setBrush(QPalette::Background,QBrush(QImage::Format_Grayscale8));
    lcd_palette.setColor(QPalette::WindowText, QColor(246, 246, 70));
    score->setPalette(lcd_palette);
//    proxy = new QGraphicsProxyWidget();
//    proxy = scene()->addWidget(score);
    setPixmap(QPixmap(":/images/b_panel.jpg"));
    setPos(0, s_height - p_height);
    setScale(6);
    setZValue(8);
    fuel_sound = new QMediaPlayer();
    fuel_sound->setMedia(QUrl("qrc:/sound/getFuel.wav"));
    amount = new fuel();
    connect(amount, SIGNAL(fuelDec(int)), this, SLOT(set_posl()));
    connect(amount, SIGNAL(fuelInc(int)), this, SLOT(set_posr()));
    connect(player, SIGNAL(scoreChanged()), this, SLOT(setScore()));
}

QGraphicsPixmapItem *panel::getGauge()
{
    return gauge;
}

QGraphicsPixmapItem *panel::getNeedle()
{
    return needle;
}

QGraphicsProxyWidget* panel::getScore()
{
    return proxy;
}

void panel::addScore()
{
    proxy = new QGraphicsProxyWidget;
    proxy = scene()->addWidget(score);
    proxy->setPos(60, 630);
    proxy->setScale(2.5);
    proxy->setZValue(20);
//    proxy->setFrameShadow(Raised);
}

fuel *panel::getFuel()
{
    return amount;
}

panel::~panel()
{
    delete gauge;
    cout << "after1" << endl;
    delete needle;
    cout << "after2" << endl;
    delete score;
    cout << "after3" << endl;
//    delete proxy;
    cout << "after4" << endl;
    delete amount;
    cout << "after5" << endl;
    delete fuel_sound;
    cout << "afterthis " << endl;
}


void panel::set_posl()
{
    if(needle->x() > s_width/2 - 55)
    {
//        cout << " je"
        needle->setPos(needle->x() - 2, needle->y());
//        cout << "x is " << needle->x() << endl;
    }
    else if(over == false)
    {
        emit gameover();
        over = true;
//        cout << " it is game over ddddddddddddddd" << endl;
    }
//    cout << "pos is " << needle->x() << endl;
}

void panel::set_posr()
{
//    QMediaPlayer* sound = new QMediaPlayer();

//    sound->play();
    if(needle->x() + 5 < s_width / 2 + 75 )
        needle->setPos(needle->x() + 5, needle->y());
    //    sound->stop();
}

void panel::play_sound()
{
//    if(fuel_sound->state() == QMediaPlayer::Stopped)
        fuel_sound->play();
}

void panel::stop_sound()
{
    fuel_sound->stop();
}

void panel::setScore()
{
    score->display(player->getScore());
}

void panel::stopMoving()
{
    amount->stopTimer();
}

