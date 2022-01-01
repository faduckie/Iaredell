#include "attribute.hpp"
#include "attributeBehavior.hpp"
#include <iostream>

Attribute::~Attribute() { delete behavior; }

void Attribute::deleteAttribute(){ delete behavior; }

void Attribute::setBehavior(AttributeBehavior* newBehavior)
{
	delete behavior;
	behavior = newBehavior;
}

void Attribute::setStats()
{
	this->defenseStat = behavior->defense(playerLvl);
	this->manaStat = behavior->mana(playerLvl);
	this->hpStat = behavior->health_points(playerLvl);
	this->attackStat = behavior->attack(playerLvl);
	this->model = behavior->modelType();

}

void Attribute::updatedLevel(int newLevel)
{
    this->playerLvl=newLevel;
    setStats();
}

void Attribute::printBaseStats()
{
	std::cout<<"\tTYPE: "<<model<<std::endl;
	std::cout<<"\tHP: "<<hpStat<<std::endl;
	std::cout<<"\tATK: "<<attackStat<<std::endl;
	std::cout<<"\tDEF: "<<defenseStat<<std::endl;
	std::cout<<"\tMANA: "<<manaStat<<std::endl;
}


