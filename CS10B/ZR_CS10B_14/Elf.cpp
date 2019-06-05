#include <iostream>
#include "creature.h"
#include "Elf.h"
using namespace std;

namespace cs_creatures {

	Elf::Elf()
	{
		int newStrength = 10;
		int newHitpoints = 10;
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}






	Elf::Elf(const int& newStrength,
		const int& newHitpoints)

		:creature(newStrength, newHitpoints)


	{
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}





	string Elf::getSpecies()
	{
		return "Elf";
	}





	int Elf::getDamage()
	{
		int damage = creature::getDamage();
	
		if ((rand() % 2) == 0) {
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage *= 2;
		}
		return damage;
	}

}
