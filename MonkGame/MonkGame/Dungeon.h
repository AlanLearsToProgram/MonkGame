#pragma once


class Dungeon {
private:
	int levels,rooms;
	int** arr;
	int lenght;
	int lvl;
	int treasureRoom;
	int currentLvl;
	int left, right;
	
	
public:
	
	int** generate();
	Dungeon(int);
	void setTreasureRoom(int);
	
	//Dungeon lengh:

	void setDungeonLenght(int);
	int getDungeonLenght();
	//Movement: 

	void setCurrentLvl(int);
	int getCurrentLvl();
	void setLeft(int);
	void setRight(int);
	int getLeft();
	int getRight();



};