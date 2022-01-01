
#ifndef __BASICWEAPON_HPP__
#define __BASICWEAPON_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>

class BasicWeapon : public WeaponBehavior 
{
    private:
        //min dmg weapon deals
        int minDmg = 3;
        //max dmg weapon deals
        int maxDmg = 6;
        //scale dmg based on player lvl
        double scale = 3;

    public:
        //constructor
        BasicWeapon(){ srand(time(0)); }

        /*
            Normal Attack
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
            Special Attack
                deals 1.25x damage
        */
        virtual double specialAttack(double attackLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += (attackLvl - 1) * scale;
            //x1.25 damage bc of special attack
            damage *= 1.25;
            //return damage
            return damage;
        }

        /*
            Special Move
                deals 2x damage
        */
        virtual double specialMove(double attackLvl)
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

};
#endif