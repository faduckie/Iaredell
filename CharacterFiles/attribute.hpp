#ifndef __ATTRIBUTE_HPP__
#define __ATTRIBUTE_HPP__
#include "attributeBehavior.hpp"
#include "../WeaponsFiles/weapons.hpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/broom.hpp"
#include "../WeaponsFiles/basicWeapon.hpp"

class AttributeBehavior;

class Attribute{
	private:
		AttributeBehavior* behavior = nullptr;
		double defenseStat;
		double manaStat;
		double attackStat;
		double hpStat;
		int playerLvl=1;
		std::string model;

	public:
		//constructors
		Attribute(){}
		~Attribute();
        void deleteAttribute();
		void setBehavior(AttributeBehavior* newBehavior);
		void updatedLevel(int newLevel);
		void setStats();
		void printBaseStats();

		int getLevel() const {return this->playerLvl;}
		double getDefenseStat(){ return this->defenseStat;}
		double getManaStat() {return this->manaStat;}
		double getHpStat(){ return this->hpStat;}
		double getAttackStat(){ return this->attackStat;}
		std::string getModelType() { return this->model;}

		
};
#endif