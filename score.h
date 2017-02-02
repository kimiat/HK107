#include <iostream>

using namespace std;

enum Object {SHIP, HELICOPTER, JET, BALLOON};

class Score
{
private:
	int value;
public:
	Score();
	int getScore();
	void addScore(Object destroyed);
};