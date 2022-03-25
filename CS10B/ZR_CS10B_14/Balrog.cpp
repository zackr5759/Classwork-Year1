#include <iostream>
#include "demon.h"
#include "Balrog.h"
using namespace std;

namespace cs_creatures {

	Balrog::Balrog()
	{
		int newStrength = 10;
		int newHitpoints = 10;
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}

	Balrog::Balrog(const int& newStrength,
		const int& newHitpoints)

		:Demon(newStrength, newHitpoints)


	{
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}

	string Balrog::getSpecies()
	{
		return "Balrog";
	}

	int Balrog::getDamage()
	{

		int damage = Demon::getDamage();
		int damage2 = (rand() % creature::getStrength()) + 1;

		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage += damage2;
		return damage;
	}

}