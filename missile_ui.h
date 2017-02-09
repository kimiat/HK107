#ifndef MISSILE_UI
#define MISSILE_UI
#include <QObject>
#include <QGraphicsPixmapItem>
#include "missile.h"
#include "player.h"
class m_ui: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    missile* m;
public:
    m_ui(int x, int y, Player* player);
    ~m_ui();
public slots:
    void set_pos();
    void remove();

};

#endif // MISSILE_UI

