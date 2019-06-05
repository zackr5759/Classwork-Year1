#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creatures {
	class Demon: public creature {
	public:
		Demon();
		Demon(const int& newStrength, const int& newHitpoints);
		int getDamage();
		std::string getSpecies();
	};
}

#endif