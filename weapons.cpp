#include "weapons.hpp"
#include "weaponBehavior.hpp"
#include <iostream>

Weapons::~Weapons()
{
	delete behavior;
}

void Weapons::setBehavior(WeaponBehavior* newBehavior)
{
	delete behavior;
	behavior = newBehavior;
}

double Weapons::attack(double attackLvl)
{
	double dmg = behavior->attack(attackLvl);
	//std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}

double Weapons::specialAttack(double attackLvl)
{
	double dmg = behavior->specialAttack(attackLvl);
	//std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}

double Weapons::specialMove(double attackLvl)
{
	double dmg = behavior->specialMove(attackLvl);
	//std::cout << "You dealt " << dmg << " pts of damage" << std::endl;
	return dmg;
}


