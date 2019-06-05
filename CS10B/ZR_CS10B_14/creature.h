/*
Zachary Robinson, CS10B, 5/8/2019, Dave Harden, ZR_CS10B_14

*/
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

namespace cs_creatures {
	class creature {
	public:
		creature();            
		creature(int newStrength, int newHitpoints);
		virtual int getDamage();
		void setStrength(const int newStrength);
		void setHitpoints(const int newHitpoints);
		int getStrength();
		int getHitpoints();
		virtual std::string getSpecies() = 0;

	private:
		int strength;           // how much damage this Creature inflicts
		int hitpoints;          // how much damage this Creature can sustain
	};
}

#endif
