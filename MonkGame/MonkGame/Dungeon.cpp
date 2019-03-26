#include "pch.h"
#include "Dungeon.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

 Dungeon::Dungeon(int currentLvl) {
	 
	 setCurrentLvl(currentLvl);
 }

 //DUNGEON GENERATOR

	int** Dungeon::generate() {
		srand(time(NULL));
		int levels = rand() % 10 + 5;
		int** arr = 0;
		arr = new int*[levels];// Creating an array to hold the levels
		for (int i = 0; i < levels; i++) {
			cout << "Generating room... \n";
			int rooms = rand() % 3; // number of neighbouring rooms
			int monster = rand() % 2; // type of room (empty or with a monster)
			switch (rooms) {
				
				//Case for a room with no neighbouring rooms
			case 1: 
				arr[i] = new int[2];
				arr[i][0] = monster;
				arr[i][1] = rooms;
				//Case for a room with 1 neighbouring room
			case 2:
				arr[i] = new int[3];
				arr[i][0] = monster;
				arr[i][1] = rooms;
				arr[i][2] = monster;
				//Case for a room with two neighbouring rooms
			case 3:
				arr[i] = new int[4];
				arr[i][0] = monster;
				arr[i][1] = rooms;
				arr[i][2] = monster;
				arr[i][3] = monster;
				
				{ 
			default:
				break;
				}
			}
			
		}
		//Treasure room 
		arr[levels] = new int[1];
		setTreasureRoom(levels);
		arr[levels][0] = 2;
		cout << "\nDungeon generated! \n";
		return arr;
}
	void Dungeon::setTreasureRoom(int troom) {
		treasureRoom = troom;

	}
	void Dungeon::setCurrentLvl(int currentRoom) {
		currentLvl = currentRoom;
	}

	int Dungeon::getCurrentLvl(){
		
		return currentLvl;
	}

	void Dungeon::setDungeonLenght(int dl) {
		lenght = dl;

	}

	int Dungeon::getDungeonLenght()
	{
		return lenght;
	}

	void Dungeon::setLeft(int sl)
	{
		left = sl;
	}

	void Dungeon::setRight(int sr)
	{
		right = sr;
	}

	int Dungeon::getLeft()
	{
		return left;
	}

	int Dungeon::getRight()
	{
		return right;
	}

	
