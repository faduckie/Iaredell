#ifndef __WEAPONS_HPP__
#define __WEAPONS_HPP__
#include <string>
#include "weaponBehavior.hpp"

class WeaponBehavior;

class Weapons{
	private:
		//std::string name;
		WeaponBehavior* behavior = nullptr;
	public:
		//constructors
		Weapons(){}
		//Weapons(std::string name):name(name){}
		//destructor
		~Weapons();
		void setBehavior(WeaponBehavior* newBehavior);
		//void setName(std::string weaponName) { name = weaponName; }
		//std::string getName(){ return name; }
		
		double attack(double attackLvl);
		double specialAttack(double attackLvl);
		double specialMove(double attackLvl);
};
#endif
