/*  Created by Zachary Robinson Spring of 2019
	Edited by Zachary Robinson in Spring of 2022

	This program was created for a class assignment at the Santa Rosa Junior College. This quick exercise on inheritance defines 4 different types of
	creatures with different abilities. The main program will loop to prompt the user to select two fighters from the list of creatures and will then have 
	the two creatures "attack" each other until either one or both creatures have fallen.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include "creature.h"
#include "Human.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include "Elf.h"
#include "demon.h"

using namespace std;
using namespace cs_creatures;


void battleArena(creature& creature1, creature& creature2);
void setUpArena(int one, int two);

int main()
{
	srand(static_cast<unsigned>(time(0)));
		char inputOne, inputTwo;
		string fighters[4] = {"Human", "Elf", "Cyberdemon", "Balrog"};

		while(true){
			cout << "\nWelcome to the Battle Arena! Fighters will have random values for strength (30-70) and health (200-300)\n" << "\nOptions for fighters:" << endl;
			cout << "1: Human\n" << "2: Elf\n" << "3: Cyberdemon\n" << "4: Balrog\n" << endl;
			cout << "Enter a number for the first fighter, then the second to start a battle (q to quit)"<< endl;
			cin >> inputOne;
			//Check to make sure input is either 1-4 or a 'q'
			if(inputOne == 'q')
				break;
			else if (isdigit(inputOne) && int(inputOne) > 48 && int(inputOne) < 53)
			{
				inputOne -= 48;
				cout << "Selected " << fighters[inputOne-1] << " for fighter one" << endl;
				cin >> inputTwo;

				//Check to make sure input is either 1-4 or a 'q'
				if(inputTwo == 'q')
					break;
				else if (isdigit(inputTwo) && int(inputTwo) > 48 && int(inputTwo) < 53)
				{
					inputTwo -= 48;
					cout << "Selected " << fighters[inputTwo-1] << " for fighter two" << endl;

					cout << "The battle between a(n) " << fighters[inputOne-1] << " and a(n) " << fighters[inputTwo-1] << " is about to start!" << endl << endl;
					Sleep(3000);
					setUpArena(inputOne, inputTwo);

				}else{
					cout << "Please only enter 1-4 for the fighters or q to quit" << endl;
				}
			}else {
				cout << "Please only enter 1-4 for the fighters or q to quit" << endl;
			}
		}

}

void setUpArena(int one, int two){
	//make two randomzied fighters of each type
	Human H1 = Human 			(rand() % 40 + 30, rand() % 100 + 200);
	Elf E1 = Elf 				(rand() % 40 + 30, rand() % 100 + 200);
	Cyberdemon C1 = Cyberdemon 	(rand() % 40 + 30, rand() % 100 + 200);
	Balrog B1 = Balrog 			(rand() % 40 + 30, rand() % 100 + 200);
	Human H2 = Human 			(rand() % 40 + 30, rand() % 100 + 200);
	Elf E2 = Elf 				(rand() % 40 + 30, rand() % 100 + 200);
	Cyberdemon C2 = Cyberdemon 	(rand() % 40 + 30, rand() % 100 + 200);
	Balrog B2 = Balrog 			(rand() % 40 + 30, rand() % 100 + 200);

	// Now we have a super fun 16 case switch statement because I didn't figure out how to place all the creatures together under the type Creature
	// and therefore cant group them together and just pick on based on the input.
	switch(one){
		case 1:
			switch(two){
				case 1:
					battleArena(H1, H2);
					break;
				case 2:
					battleArena(H1, E2);
					break;
				case 3:
					battleArena(H1, C2);
					break;
				case 4:
					battleArena(H1, B2);
					break;
					
			}
		break;
		case 2:
			switch(two){
				case 1:
					battleArena(E1, H2);
					break;
				case 2:
					battleArena(E1, E2);
					break;
				case 3:
					battleArena(E1, C2);
					break;
				case 4:
					battleArena(E1, B2);
					break;
					
			}
		break;
		case 3:
			switch(two){
				case 1:
					battleArena(C1, H2);
					break;
				case 2:
					battleArena(C1, E2);
					break;
				case 3:
					battleArena(C1, C2);
					break;
				case 4:
					battleArena(C1, B2);
					break;
					
			}
		break;
		case 4:
			switch(two){
				case 1:
					battleArena(B1, H2);
					break;
				case 2:
					battleArena(B1, E2);
					break;
				case 3:
					battleArena(B1, C2);
					break;
				case 4:
					battleArena(B1, B2);
					break;
			}
		break;
	}
}

void battleArena(creature& creature1, creature& creature2)

{	cout << "*******************" << endl;
	cout << creature1.getSpecies() << " vs " << creature2.getSpecies() << endl;
	cout << "*******************" << endl;
	cout << endl;

	cout << creature1.getSpecies() << " strength/hitpoints: " << creature1.getStrength() << "/" << creature1.getHitpoints() << endl;
	cout << creature2.getSpecies() << " strength/hitpoints: " << creature2.getStrength() << "/" << creature2.getHitpoints() << endl;
	cout << endl;

	while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0)
	{
		int damage1 = creature1.getDamage();
		cout << " Total damage = " << damage1 << endl;
		cout << endl;
		int damage2 = creature2.getDamage();
		cout << " Total damage = " << damage2 << endl;
		cout << endl;
		creature1.setHitpoints((creature1.getHitpoints() - damage2));
		creature2.setHitpoints((creature2.getHitpoints() - damage1));

		cout << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints remaining." << endl;
		cout << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hitpoints remaining." << endl;
		cout << endl << endl << endl;
		
	}

	if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() > 0)
	{
		cout << creature2.getSpecies() << " has won!" << endl;
		cout << endl;
	}
	if (creature1.getHitpoints() > 0 && creature2.getHitpoints() <= 0)
	{
		cout << creature1.getSpecies() << " has won!" << endl;
		cout << endl;
	}
	if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
	{
		cout << "The battle ends in a tie!" << endl;
		cout << endl;
	}
	
}