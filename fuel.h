#ifndef FUEL
#define FUEL

#include<QTimer>
#include<QObject>
#include<QGraphicsRectItem>
class fuel:public QObject, public QGraphicsRectItem{
    Q_OBJECT
    private:
        int fuel_amount;
//        QTimer* ifuel_timer;
        QTimer* dfuel_timer;
    signals:
        void fuelInc(int changed_amount);
        void fuelDec(int changed_amount);
    public:
        fuel();
        ~fuel();
    public slots:
        void inc_fuel();
        void dec_fuel();
        void stopTimer();
//        void move_down();
};

#endif

