#include <iostream>
#include "demon.h"
#include "Cyberdemon.h"
using namespace std;

namespace cs_creatures {

	Cyberdemon::Cyberdemon()
	{
		int newStrength = 10;
		int newHitpoints = 10;
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}






	Cyberdemon::Cyberdemon(const int& newStrength,
		const int& newHitpoints)

		:Demon(newStrength, newHitpoints)


	{
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}





	string Cyberdemon::getSpecies()
	{
		return "Cyberdemon";
	}

}