#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature.h"
#include "Human.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include "Elf.h"
#include "demon.h"
using namespace std;
using namespace cs_creatures;


void battleArena(creature& creature1, creature& creature2);

int main()
{
	srand(static_cast<unsigned>(time(0)));

		Human h(rand() % 40 + 30, rand() % 100 + 200);
		Elf e(rand() % 40 + 30, rand() % 100 + 200);
		Cyberdemon c(rand() % 40 + 30, rand() % 100 + 200);
		Balrog b(rand() % 40 + 30, rand() % 100 + 200);
		Human h2(rand() % 40 + 30, rand() % 100 + 200);
		Elf e2(rand() % 40 + 30, rand() % 100 + 200);
		Cyberdemon c2(rand() % 40 + 30, rand() % 100 + 200);
		Balrog b2(rand() % 40 + 30, rand() % 100 + 200);

		battleArena(e, b);
		battleArena(c, h);
		battleArena(e2, h2);
		battleArena(b2, c2);
}





void battleArena(creature& creature1, creature& creature2)
{
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

/*
Elf vs Balrog
*******************

Elf strength/hitpoints: 51/231
Balrog strength/hitpoints: 46/242

The Elf attacks for 8 points!
 Total damage = 8

The Balrog attacks for 39 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 24 additional damage points!
 Total damage = 113

Elf has 118 hitpoints remaining.
Balrog has 234 hitpoints remaining.



The Elf attacks for 36 points!
 Total damage = 36

The Balrog attacks for 36 points!
Balrog speed attack inflicts 22 additional damage points!
 Total damage = 58

Elf has 60 hitpoints remaining.
Balrog has 198 hitpoints remaining.



The Elf attacks for 42 points!
Magical attack inflicts 42 additional damage points!
 Total damage = 84

The Balrog attacks for 14 points!
Balrog speed attack inflicts 29 additional damage points!
 Total damage = 43

Elf has 17 hitpoints remaining.
Balrog has 114 hitpoints remaining.



The Elf attacks for 27 points!
 Total damage = 27

The Balrog attacks for 46 points!
Balrog speed attack inflicts 22 additional damage points!
 Total damage = 68

Elf has -51 hitpoints remaining.
Balrog has 87 hitpoints remaining.



Balrog has won!

Cyberdemon vs Human
*******************

Cyberdemon strength/hitpoints: 66/213
Human strength/hitpoints: 65/299

The Cyberdemon attacks for 10 points!
 Total damage = 10

The Human attacks for 62 points!
 Total damage = 62

Cyberdemon has 151 hitpoints remaining.
Human has 289 hitpoints remaining.



The Cyberdemon attacks for 9 points!
 Total damage = 9

The Human attacks for 56 points!
 Total damage = 56

Cyberdemon has 95 hitpoints remaining.
Human has 280 hitpoints remaining.



The Cyberdemon attacks for 51 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 101

The Human attacks for 57 points!
 Total damage = 57

Cyberdemon has 38 hitpoints remaining.
Human has 179 hitpoints remaining.



The Cyberdemon attacks for 16 points!
 Total damage = 16

The Human attacks for 52 points!
 Total damage = 52

Cyberdemon has -14 hitpoints remaining.
Human has 163 hitpoints remaining.



Human has won!

Elf vs Human
*******************

Elf strength/hitpoints: 65/250
Human strength/hitpoints: 44/284

The Elf attacks for 47 points!
 Total damage = 47

The Human attacks for 27 points!
 Total damage = 27

Elf has 223 hitpoints remaining.
Human has 237 hitpoints remaining.



The Elf attacks for 14 points!
 Total damage = 14

The Human attacks for 9 points!
 Total damage = 9

Elf has 214 hitpoints remaining.
Human has 223 hitpoints remaining.



The Elf attacks for 5 points!
 Total damage = 5

The Human attacks for 36 points!
 Total damage = 36

Elf has 178 hitpoints remaining.
Human has 218 hitpoints remaining.



The Elf attacks for 45 points!
 Total damage = 45

The Human attacks for 41 points!
 Total damage = 41

Elf has 137 hitpoints remaining.
Human has 173 hitpoints remaining.



The Elf attacks for 8 points!
 Total damage = 8

The Human attacks for 25 points!
 Total damage = 25

Elf has 112 hitpoints remaining.
Human has 165 hitpoints remaining.



The Elf attacks for 17 points!
 Total damage = 17

The Human attacks for 42 points!
 Total damage = 42

Elf has 70 hitpoints remaining.
Human has 148 hitpoints remaining.



The Elf attacks for 36 points!
 Total damage = 36

The Human attacks for 24 points!
 Total damage = 24

Elf has 46 hitpoints remaining.
Human has 112 hitpoints remaining.



The Elf attacks for 32 points!
 Total damage = 32

The Human attacks for 4 points!
 Total damage = 4

Elf has 42 hitpoints remaining.
Human has 80 hitpoints remaining.



The Elf attacks for 28 points!
Magical attack inflicts 28 additional damage points!
 Total damage = 56

The Human attacks for 8 points!
 Total damage = 8

Elf has 34 hitpoints remaining.
Human has 24 hitpoints remaining.



The Elf attacks for 7 points!
 Total damage = 7

The Human attacks for 28 points!
 Total damage = 28

Elf has 6 hitpoints remaining.
Human has 17 hitpoints remaining.



The Elf attacks for 6 points!
Magical attack inflicts 6 additional damage points!
 Total damage = 12

The Human attacks for 3 points!
 Total damage = 3

Elf has 3 hitpoints remaining.
Human has 5 hitpoints remaining.



The Elf attacks for 51 points!
Magical attack inflicts 51 additional damage points!
 Total damage = 102

The Human attacks for 8 points!
 Total damage = 8

Elf has -5 hitpoints remaining.
Human has -97 hitpoints remaining.



The battle ends in a tie!

Balrog vs Cyberdemon
*******************

Balrog strength/hitpoints: 63/272
Cyberdemon strength/hitpoints: 34/217

The Balrog attacks for 32 points!
Balrog speed attack inflicts 47 additional damage points!
 Total damage = 79

The Cyberdemon attacks for 31 points!
 Total damage = 31

Balrog has 241 hitpoints remaining.
Cyberdemon has 138 hitpoints remaining.



The Balrog attacks for 40 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 57 additional damage points!
 Total damage = 147

The Cyberdemon attacks for 5 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 55

Balrog has 186 hitpoints remaining.
Cyberdemon has -9 hitpoints remaining.



Balrog has won!


C:\Users\Zack\source\repos\Project34\Debug\Project34.exe (process 10952) exited
with code 0.
Press any key to close this window . . .




*/