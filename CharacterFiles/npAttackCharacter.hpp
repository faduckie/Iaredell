#ifndef __NP_ATTACK_CHARACTER__
#define __NP_ATTACK_CHARACTER__

#include "attackCharacter.hpp"

class NPAttackCharacter: public AttackCharacter
{
public:
    NPAttackCharacter(int characterClass, std::string npcName, int weaponClass, int level){
        setName(npcName);
        switch(characterClass){
        case 1: model.setBehavior(new Wizard()); break; // Wizard model
        case 2: model.setBehavior(new Knight()); break; // Knight model
        case 3: model.setBehavior(new Rogue()); break; // Rogue model
        case 4: model.setBehavior(new Bob()); break; // Bob model
        default: break;
        }
        model.updatedLevel(level);
        switch (weaponClass){
        case 1: weapon.setBehavior(new Staff()); break; // staff model 
        case 2: weapon.setBehavior(new LongSword()); break; // longsword model
        case 3: weapon.setBehavior(new Dagger()); break; // dagger model
        case 4: weapon.setBehavior(new Broom()); break; // broom model
        default: break;
        }
        model.setStats(); damageGiven = 0;
        hp = model.getHpStat(); defense = model.getDefenseStat();
        attack = model.getAttackStat(); mana = model.getManaStat();
    }
    NPAttackCharacter(){}

    virtual bool selectMove(int i)
    {
        bool hasSelecteMove = false;

        if(mana >= 3) // special attack
        {
            if( (rand() % 100) < 30){
                specialAttack();
                hasSelecteMove = true;
            }
        }
        if( mana >= 5 && hasSelecteMove == false) // special move
        {
            if( (rand() % 100) < 75){
                specialMove();
                hasSelecteMove = true;
            }
        }
        if( defense < model.getDefenseStat() * 2 && hasSelecteMove == false) // increase defense
        {
            if( (rand() % 100) < 10){
                increaseDefense();
                hasSelecteMove = true;
            }
        }
        if( hasSelecteMove == false ) // normal attack
        {
            normalAttack();
        }
        mana += model.getManaStat()/3;

        return true;
    }
    
};


#endif