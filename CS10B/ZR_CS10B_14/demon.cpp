#include <iostream>
#include "creature.h"
#include "demon.h"
using namespace std;

namespace cs_creatures {

	Demon::Demon()
	{
		int newStrength = 10;
		int newHitpoints = 10;
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}






	Demon::Demon(const int& newStrength,
		const int& newHitpoints)

		:creature(newStrength, newHitpoints)


	{
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}





	string Demon::getSpecies()
	{
		return "Demon";
	}





	int Demon::getDamage()
	{
		int damage = creature::getDamage();


		if (rand() % 4 == 0) {
			damage += 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}
		return damage;
	}


}