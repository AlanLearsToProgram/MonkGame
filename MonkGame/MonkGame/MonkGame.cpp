// MonkGame.cpp : This file contains the 'main' function.
// This is also the Controller of the game.
//Writen by: Alan Salfij
// Student Number: U1763040


#include "pch.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include"Dungeon.h"
#include <string>
#include <cstdlib>
#include <time.h>


using namespace std;
                              //*The  Combat Controller*\\


//Function that allows the monster class to attack

void monsterAttack(Character player, Monster monster) {
	int playerHealth = player.getHitPoints();
	int monsterDMG = monster.getDMG();
	cout << "The Goblin will make the next move\n";
	srand(time(NULL));
	int msuccess = rand() % 2 + 1; //monster attack success rate
	if (msuccess == 1) {
		int newPlayerHp = playerHealth - monsterDMG;

		cout << "Monster attack was successfull!/n Your current Health is: " << newPlayerHp;
		player.setHitPoints(newPlayerHp);
		cout<<"\nDEBUG HERE " << newPlayerHp << " <----------------";
	}
	else {
		cout << "Goblin's attack was unsuccessfull!" << endl;
		cout << "Current Health is: " << playerHealth << endl;
	}
}


void playerAttack(Character player, Monster monster) {
	int playerHP = player.getHitPoints();
	int monsterHP = monster.getHP();
	int playerATK = player.getAtkPoints();
	srand(time(NULL));
	int success = rand() % 100; // success rate of attack
	if (success > 50) {           //Succsessfull
		int newMonHP = monsterHP - playerATK;
		cout << "You have made a successfull attack\n";
		cout << "Monster hp is now: " << newMonHP << endl;
		monster.setHitPoints(newMonHP);

	}
	else {
		cout << "The attack was unsuccessfull!\n";
		monsterAttack(player, monster);
		
	}
}
void playerDodge(Character player, Monster monster) {
	int playerHP = player.getHitPoints();
	int monsterATK = monster.getDMG();
	int success = rand() % 101; // success rate of dodge

	if (success > 50) {
		cout << "You were able to dodge the attack of the Goblin \n" << endl;
		cout << "Current Health is: " << playerHP << endl;

	}
	else {
		int newHP = playerHP - monsterATK;
		cout << "You failed to Dodge the Attack!\n";
		cout << " You have " << newHP << " Health Points left " << endl;
		player.setHitPoints(newHP);


	}

}
/////////////////////////////////////////////////////////
//Combat function that goes through the fighting process 
void combat(Character player, Dungeon dungeon, int**arr, Monster monster) {
	srand(time(NULL));
	string choice;
	int answer;
	//Player stats getters
	int playerHP = player.getHitPoints();
	//Monster stats getters
	int monsterHP = monster.getHP();

                        
	cout << "Oh no!!! This room has a Goblin, and it's headed towards you!\n";
	
	// Lenght of the battle will be determined by the last man standing
	while (playerHP > 0 && monsterHP > 0) {
	cout << "press '1' to Attack or '2' to Dodge " << endl;
	cin >> choice;
	answer = stoi(choice);
	int round = 0;	
		if (answer == 1) {                // Choosing Attack
			playerAttack(player, monster);

			}
		else if (answer == 2) {           // Choosing Dodge
			playerDodge(player, monster);		

		}
		else {
			cout << "Plese enter a valid response!" << endl;
			cout << "Enter 1 to Attack or 2 to Dodge";
		}
		cout << " \nend of round: " << endl;
		cout << "Monk HP: " << playerHP << " Monster HP: " << monsterHP << endl;
		
		}
	//Winning Outcome
	if (playerHP == 0) {
		cout << " You have lost the fight!\n";
		cout << "The Goblin will make the next move";
		cout << "Press '1' to start again";
	}
	//Losing Outcome
	else if (monsterHP == 0) {
		cout << "You won the Battle!\n The Monk grows stronger with every fight.\n";
		cout << "Current Health is: " << playerHP << " "<< endl;
	}
	

}
//Pray function that allows the player to regain all of his Health
void pray(Character player,Dungeon dungeon, int**arr,Monster monster) {
	player.setHitPoints(10);
	int hp = player.getHitPoints();
	cout << "You have fully healed your current Health is: " << player.getHitPoints() << endl;
	

	
}
//Explore Function that gives the outcomes for different choices the Player makes 
void explore(Character player, Dungeon dungeon, int** arr, Monster monster) {
	int currentlvl = dungeon.getCurrentLvl();
	int DungeonLenght = dungeon.getDungeonLenght();
	int left = dungeon.getLeft();
	int right = dungeon.getRight();

	string move;
	int enter;

	int controller = arr[dungeon.getCurrentLvl()][1];

	//Starting the game 
	if (controller != 0)
	{	//Swictch case for amount of neighboring rooms
		switch (controller)
		{
			//Case for rooms Left and Forward
		case 1:
			dungeon.setLeft(1);
			dungeon.setRight(0);
			cout << "Left and Forward!\n";
			cout << "1 for left, 2 for Forward\n";
			cin >> move;
			enter = stoi(move);
			// Moving Forward
			if (enter == 2) {
				if (arr[dungeon.getCurrentLvl()][0] = 1)// if room type is Monster Room
				{
					combat(player, dungeon, arr, monster);
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					cout << "You have entered level: " << (dungeon.getCurrentLvl() + 1) << "\n";
					explore(player, dungeon, arr, monster);
					

				}
				else {// if room type is empty room 
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					pray(player,dungeon,arr,monster);
					explore(player, dungeon, arr, monster); // calling the functin again to load current state of Dungeon
				}
				
			}
			else if (enter == 1) {
				combat(player, dungeon, arr, monster);
				if (arr[dungeon.getCurrentLvl()][2] = 1) {
					int choice;
					combat(player, dungeon, arr, monster);
					arr[dungeon.getCurrentLvl()][2] = 0;
					cout << "Press 1 to go back.\n";
					cin >> move;
					choice = stoi(move);
					if (choice == 1) {
						explore(player, dungeon, arr, monster);
					}
					else {
						cout << "Please go back by pressing 1!";
						if (choice != 1) {
							cout << ".  ";
							cout << " . ";
							cout << "  .";
						}
					}
				}
				else {
					int choice;
					cout << "Empty Room! You can pray here! \n";
					cout << "Press 1 to Pray, 2 to go back. \n";
					cin >> move;
					choice = stoi(move);
					if (choice == 1) {
						cout << "praying..";
						pray(player,dungeon,arr,monster);
						cout << "press 2 to go back";
						cin >> choice;
						if (choice == 2) {
							explore(player, dungeon, arr, monster);
						}
						else {
							cout << "Please go back by pressing 2!";
							while (choice != 2) {
								cout << ".  ";
								cout << " . ";
								cout << "  .";
								break;
							}
						}
					}

				}
			}break;
		case 2:
			dungeon.setLeft(0);
			dungeon.setRight(1);
			cout << "Right and Forward!\n";
			cout << "1 for Right, 2 for Forward\n";
			cin >> move;
			enter = stoi(move);
			// Moving Forward
			if (enter == 2) {
				if (arr[dungeon.getCurrentLvl()][0] = 1)// if room type is Monster Room
				{
					combat(player, dungeon, arr, monster);
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					cout << "You have entered level: " << (dungeon.getCurrentLvl() + 1) << "\n";
					explore(player, dungeon, arr, monster);

				}
				else {// if room type is empty room 
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					pray(player,dungeon,arr,monster);
				}
				explore(player, dungeon, arr, monster); // calling the functin again to load current state of Dungeon
			}
			else if (enter == 1) {
				combat(player, dungeon, arr, monster);
				if (arr[dungeon.getCurrentLvl()][2] = 1) {
					int choice;
					combat(player, dungeon, arr, monster);
					arr[dungeon.getCurrentLvl()][2] = 0;
					cout << "Press 1 to go back.\n";
					cin >> move;
					choice = stoi(move);
					if (choice == 1) {
						explore(player, dungeon, arr, monster);
					}
					else {
						cout << "Please go back by pressing 1!";
						while (choice != 1) {
							cout << ".  ";
							cout << " . ";
							cout << "  .";
							break;
						}
					}
				}
				else {
					int choice;
					cout << "Empty Room! You can pray here! \n";
					cout << "Press 1 to Pray, 2 to go back. \n";
					cin >> move;
					choice = stoi(move);
					if (choice == 1) {
						cout << "praying..";
						pray(player,dungeon,arr,monster);
						cout << "press 2 to go back";
						cin >> choice;
						if (choice == 2) {
							explore(player, dungeon, arr, monster);
						}
						else {
							cout << "Please go back by pressing 2!";
							while (choice != 2) {
								cout << ".  ";
								cout << " . ";
								cout << "  .";
								break;
							}
						}
					}

				}
			}break;
			// Case for neighboring rooms on both sides 
		case 3:
			dungeon.setLeft(1);
			dungeon.setRight(1);
			cout << "Right, Left and Forward!\n";
			cout << "1 for left, 2 for Right and 3 for Forward\n";
			cin >> move;
			enter = stoi(move);
			// Moving Forward
			if (enter == 3) {
				if (arr[dungeon.getCurrentLvl()][0] = 1)// if room type is Monster Room
				{
					combat(player, dungeon, arr, monster);
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					cout << "You have entered level: " << (dungeon.getCurrentLvl() + 1) << "\n";
					explore(player, dungeon, arr, monster);

				}
				else {// if room type is empty room 
					dungeon.setCurrentLvl(dungeon.getCurrentLvl() + 1);
					explore(player, dungeon, arr, monster);
					pray(player,dungeon,arr,monster);
				}
				explore(player, dungeon, arr, monster); // calling the functin again to load current state of Dungeon
			}
			else if (enter == 1) {
				combat(player, dungeon, arr, monster);
				if (arr[dungeon.getCurrentLvl()][2] = 1) {
					int choice;
					combat(player, dungeon, arr, monster);
					arr[dungeon.getCurrentLvl()][2] = 0;
					cout << "Press 1 to go back.\n";
					cin >> move;
					choice = stoi(move);
					if (choice == 1) {
						explore(player, dungeon, arr, monster);
					}
					else {
						cout << "Please go back by pressing 1!";
						while (choice != 1) {
							cout << ".  ";
							cout << " . ";
							cout << "  .";
						}break;
					}
				}
				else if (enter == 2) {
					combat(player, dungeon, arr, monster);
					if (arr[dungeon.getCurrentLvl()][2] = 1) {
						int choice;
						combat(player, dungeon, arr, monster);
						arr[dungeon.getCurrentLvl()][2] = 0;
						cout << "Press 1 to go back.\n";
						cin >> move;
						choice = stoi(move);
						if (choice == 1) {
							explore(player, dungeon, arr, monster);
						}
						else {
							cout << "Please go back by pressing 1!";
							while (choice != 1) {
								cout << ".  ";
								cout << " . ";
								cout << "  .";
							}
						}
					}
					else {
						int choice;
						cout << "Empty Room! You can pray here! \n";
						cout << "Press 1 to Pray, 2 to go back. \n";
						cin >> move;
						choice = stoi(move);
						if (choice == 1) {
							cout << "praying..";
							pray(player,dungeon,arr,monster);
							cout << "press 2 to go back";
							cin >> choice;
							if (choice == 2) {
								explore(player, dungeon, arr, monster);
							}
							else {
								cout << "Please go back by pressing 2!";
								while (choice != 2) {
									cout << ".  ";
									cout << " . ";
									cout << "  .";
								}
							}
						}

					}
				}break;






			}
		}

	}
}

int main()
{
	
	string name;
	//Charachter Stats
	int atkPoints = 3 , hitPoints = 10, exp = 0;
	//Monster Stats
	Monster monster(10, 3);

	// Dungeon Lvl's and Rooms
	int rooms = rand()%3;

	//Game Intro
	cout << "The game has started\n Choose a Name: \n";
	cin >> name;
	Character player(name,hitPoints,atkPoints,exp);
	cout << "Your name is : " << name<< endl;
	cout << "Your Starts are: \n Health Points: " << hitPoints;
	cout << "\n Attack Points: " << atkPoints<< "\n Experience: "<< exp << "\n";
	///////////////////////////////////////////////////////////////////////
	
	// Generating Dungeon 
	Dungeon dungeon(0);
	int** arr = dungeon.generate();
	dungeon.getCurrentLvl();
	int floor = 0;
	for (int i = 0; i < dungeon.getDungeonLenght(); i++) {
		if (arr[i][0] == 0 || arr[i][0] == 1) {
			floor++;
		}
		
	}
	dungeon.setCurrentLvl(floor);
	explore(player, dungeon, arr, monster);	   
}



