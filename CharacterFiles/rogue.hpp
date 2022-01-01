#ifndef __ROGUE_HPP__
#define __ROGUE_HPP__

#include "attributeBehavior.hpp"

class Rogue : public AttributeBehavior 
{
    private:
        double def = 9;
        double hp = 13;
        double atk = 13;
        double stam = 1.75;
    public:
        Rogue(){}

       virtual double defense(int playerLvl) 
        { 
            return def + (3 * playerLvl) + (.5 * playerLvl); 
        }

	    virtual double health_points(int playerLvl)
        {
            return hp + (3 * playerLvl);
        }

        virtual double attack(int playerLvl)
        {
            return atk + (3* playerLvl) + (.5 * playerLvl);
        }
        
        virtual double mana(int playerLvl)
        {
            return stam + (playerLvl-1)*.2;
        }

        virtual std::string modelType()
        {
            return "Rogue";
        }
       

};
#endif