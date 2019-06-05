#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include <iostream>
#include <string>
#include "demon.h"
#include "creature.h"

namespace cs_creatures {
	class Cyberdemon: public Demon {
	public:
		Cyberdemon();
		Cyberdemon(const int& newStrength, const int& newHitpoints);
		std::string getSpecies();
	};
}

#endif