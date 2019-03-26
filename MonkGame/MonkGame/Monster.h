#pragma once
#pragma once
#include <string>
using namespace std;
class Monster {
private :
	int hitPoints, atkPoints;

public :
	Monster(int hitPoints,int atkPoints);
	void setAtkPoints(int dmg);
	void setHitPoints(int hp);
	int& getHP();
	int& getDMG();


};