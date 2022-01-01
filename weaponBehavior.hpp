
#ifndef __WEAPONBEHAVIOR_HPP__
#define __WEAPONBEHAVIOR_HPP__

class WeaponBehavior
{
	public:
		virtual ~WeaponBehavior() = default;
		virtual double attack(double attackLvl) = 0;
		virtual double specialAttack(double attackLvl) = 0;
		virtual double specialMove(double attackLvl) = 0;

};

#endif
