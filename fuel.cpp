#include "fuel.h"
#include <iostream>
using namespace std;

fuel::fuel()
{
//    ifuel_timer = new QTimer();
    dfuel_timer = new QTimer();
    fuel_amount = 500;
//    connect(ifuel_timer, SIGNAL(timeout()), this, SLOT(inc_fuel()));
    connect(dfuel_timer, SIGNAL(timeout()), this, SLOT(dec_fuel()));
    dfuel_timer->start(300);
}

void fuel::inc_fuel()
{
    if(fuel_amount < 480)
    {
        cout << " fue increased;"<<endl;
        fuel_amount += 20;
        emit fuelInc(fuel_amount);
    }
}

void fuel::dec_fuel()
{
    if(fuel_amount > 5)
    {
        fuel_amount -= 5;
        emit fuelDec(fuel_amount);
    }
//    x = fuel_amount / 10;
//    setPos(get_x(), get_y());
}
