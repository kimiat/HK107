//
#include <iostream>

using namespace std;

enum Object {SHIP = 30, HELICOPTER = 60, BALLOON = 60, JET = 100, TANK = 150};

class Score
{
private:
	unsigned int value;
public:
	Score();
	unsigned int getScore();
	void addScore(Object destroyed);
};
