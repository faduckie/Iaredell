
#ifndef __BROOM_HPP__
#define __BROOM_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>

class Broom : public WeaponBehavior 
{
    private:
        //min dmg weapon deals
        int minDmg = 3;
        //max dmg weapon deals
        int maxDmg = 5;
        //scale dmg based on player lvl
        double scale = 3;

    public:
        //constructor
        Broom(){ srand(time(0)); }

        /*
            Normal Attack: Bonk
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
            Special Attack:
                deals 1.75x damage
        */
        virtual double specialAttack(double attackLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += (attackLvl - 1) * scale;
            //x1.75 damage bc of special attack
            damage *= 1.75;
            //return damage
            return damage;
        }

        /*
            Special Move: Elixir of ?
                deals 2.5x damage
        */
        virtual double specialMove(double attackLvl)
        {
            //calculate damage within range
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            //scale damage dealt
            damage += (attackLvl - 1) * scale;
            //x2.5 damage bc of special move
            damage *= 2.5;
            //return damage
            return damage;
        }

};
#endif

