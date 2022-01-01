#ifndef __DAGGER_HPP__
#define __DAGGER_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>

class Dagger : public WeaponBehavior 
{
    private:
        //min dmg weapon deals
        int minDmg = 2;
        //max dmg weapon deals
        int maxDmg = 5;
        //scale damage based on player lvl
        double scale = 3;

    public:
        //constructor
        Dagger(){ srand(time(0)); }

        /*
            Normal Attack: Swipe
                deals normal damage
        */
        virtual double attack(double attackLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage
            damage += (attackLvl - 1) * scale;
            //return damage
            return damage;
        }

        /*
            Special Attack: Backstab
                deal 2x damage
        */
        virtual double specialAttack(double attackLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += (attackLvl - 1) * scale;
            //x2 damage bc of special attack
            damage *= 2;
            //return damage
            return damage;
        }

        /*
            Special Move: Stroke of Luck
                15% chance to deal 3x damage
        */
        virtual double specialMove(double attackLvl)
        {
            //calculate chance that this move will hit
            double chance = rand() % 101;
            //calculate base damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage
            damage += (attackLvl - 1) * scale;
            //if chance is 15% or less, deal 3x damage
            if(chance <= 15)
                damage *= 3;
            //return damage
            return damage;
        }

};
#endif