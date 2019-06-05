#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creatures {
	class Human: public creature {
	public:
		Human();
		Human(const int& newStrength, const int& newHitpoints);
		std::string getSpecies();
	};
}

#endif