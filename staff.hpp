#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "weaponBehavior.hpp"
#include <random>
#include <time.h>

class Staff : public WeaponBehavior 
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
        Staff() { srand(time(0)); }

        /*
            Normal Attack:
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
                attacks twice        
        */
        virtual double specialAttack(double attackLvl)
        {
            double damage = minDmg + rand() % (maxDmg - minDmg + 1);
            damage += minDmg + rand() % (maxDmg - minDmg + 1);
            return damage;

        }

         /*
            Special Attack: Fire Ball
                consistent damage output, x7.5 max dmg
            
        */
        virtual double specialMove(double attackLvl)
        {
            double damage = maxDmg * 7.5;
            return damage;
        }

};
#endif
