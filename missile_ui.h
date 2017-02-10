#ifndef MISSILE_UI
#define MISSILE_UI
#include <QObject>
#include <QGraphicsPixmapItem>
#include "missile.h"
#include "player.h"
#include "enemy_ui.h"
#include <QMediaPlayer>
class m_ui: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    missile* m;
    QMediaPlayer* sound;
    QTimer* explosion;
//    int shot_num;
public:
    m_ui(int x, int y);
    ~m_ui();
public slots:
    void set_pos();
    void remove();
//    void explode();

};

#endif // MISSILE_UI

