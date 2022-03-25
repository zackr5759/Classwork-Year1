#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

namespace cs_creatures {

	creature::creature()
	{
		strength = 10;
		hitpoints = 10;
	}

	creature::creature(int newStrength, int newHitpoints)
	{
		strength = newStrength;
		hitpoints = newHitpoints;
	}

	std::string creature::getSpecies()
	{ 
		return "Creature";
	}

	int creature::getHitpoints() 
	{ 
		return hitpoints;
	}

	int creature::getStrength()
	{ 
		return strength;
	}

	int creature::getDamage() 
	{ 
		int damage = (rand() % strength) + 1; 
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		return damage;
	}

	void creature::setStrength(const int newStrength)
	{
		strength = newStrength;
	}

	void creature::setHitpoints(const int newHitpoints)
	{
		hitpoints = newHitpoints;
	}

}