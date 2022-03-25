#include <iostream>
#include "creature.h"
#include "Human.h"
using namespace std;

namespace cs_creatures {

	Human::Human()
	{
		int newStrength = 10;
		int newHitpoints = 10;
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}

	Human::Human(const int& newStrength,
			const int& newHitpoints)

	:creature(newStrength, newHitpoints)


	{
		creature::setStrength(newStrength);
		creature::setHitpoints(newHitpoints);
	}

	string Human::getSpecies() 
	{ 
		return "Human";
	}
}