#pragma once
#include <string>
using namespace std;
class Character {
private:
	
	string playerName;
	int hitPoints, atkPoints, position, exp;

public:
	
	Character(string,int,int,int);
	void setName(string name);
	void setAtkPoints(int atkP);
	void setHitPoints(int HP);
	void setEXP(int exp);
	string getName();
	int getHitPoints();
	int getAtkPoints();
	int getExp();
	
};


