#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creatures {
	class Elf: public creature {
	public:
		Elf();
		Elf(const int& newStrength, const int& newHitpoints);
		int getDamage();
		std::string getSpecies();
	};
}

#endif