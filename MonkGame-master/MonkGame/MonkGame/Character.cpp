#include "pch.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;
Character::Character(string name,int hitPoints,int atkPoints, int exp )
{
	setName(name);
	setEXP(exp);
	setHitPoints(hitPoints);
	setAtkPoints(atkPoints);
}


void Character::setName(string name)
{
	playerName = name;
}
string Character::getName() {
	return playerName;
}
int Character::getHitPoints()
{
	return hitPoints;
}
int Character::getAtkPoints()
{
	return atkPoints;
}
int Character::getExp()
{
	return exp;
}
void Character::setAtkPoints(int atkP)
{
	atkPoints = atkP;
}

void Character::setHitPoints(int HP)
{
	hitPoints = HP;
}

void Character::setEXP(int exp)
{
	exp = exp;
}

