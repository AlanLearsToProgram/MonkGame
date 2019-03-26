#include "pch.h"
#include "Monster.h"
#include "Character.h"


Monster::Monster(int hitPoints, int atkPoints)
{
	setHitPoints(hitPoints);
	setAtkPoints(atkPoints);
}

int& Monster::getHP() {
	return this->hitPoints;
}


int& Monster::getDMG() {
	return atkPoints;
}
void Monster::setHitPoints(int hp)
{
	this->hitPoints = hp;
}
void Monster::setAtkPoints(int dmg) {
	atkPoints = dmg;
}
