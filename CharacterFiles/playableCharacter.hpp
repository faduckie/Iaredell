#ifndef __PLAYABLE_CHARACTER_HPP__
#define __PLAYABLE_CHARACTER_HPP__

#include "attackCharacter.hpp"
#include <string>
#include <iostream>

class PlayableCharacter: public AttackCharacter {
private:
    int exp = 0, level = 1, expNeeded = 5;
public:
    PlayableCharacter() {}
    PlayableCharacter(int characterClass, std::string playerName, int weaponClass){
        setPlayerName(playerName);
        setCharacterType(characterClass);
        setWeaponType(weaponClass);
    }
    virtual bool selectMove(int move)
    {
        bool valid = false;
        switch(move){
            case 1: valid =  increaseDefense(); break; // defended this turn
            case 2: normalAttack(); valid = true; break; // regular attack
            case 3: valid = specialAttack(); break; // special attack
            case 4: valid = specialMove(); break; // special attack
            default: valid = false; break;
        }
        if(valid) mana+=model.getManaStat()/3;
        return valid;
    }


    void victory(int enemyLvl)
    {
        exp += 5 * enemyLvl;
        displayArt("ArtFiles/victory.txt");
        std::cout<<"\t\t"<<getPlayerName()<<" has gained " << 5 * enemyLvl <<" exp points!"<<std::endl;
        if(exp >= expNeeded)
        {
            level++;
            model.updatedLevel(level);
            resetValues();
            fullHealth();
            hp = model.getHpStat();
            exp-=expNeeded;
            expNeeded+=5;
            std::cout<<"\t\t"<<getPlayerName()<<" you are now level "<< level << "!!"<<std::endl;
            printVitals();
        }
        std::cout<<"\t\t"<<"Current Level: "<< level<<std::endl;
        std::cout<<"\t\t"<<"Current EXP: "<< exp <<std::endl;
        std::cout<<"\t\t"<<"EXP To Next Level: "<< expNeeded-exp <<std::endl;
    }
};

#endif
