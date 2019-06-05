#ifndef BALROG_H
#define BALROG_H

#include <iostream>
#include <string>
#include "demon.h"
#include "creature.h"

namespace cs_creatures {
	class Balrog : public Demon {
	public:
		Balrog();
		Balrog(const int& newStrength, const int& newHitpoints);
		int getDamage();
		std::string getSpecies();
	};
}

#endif