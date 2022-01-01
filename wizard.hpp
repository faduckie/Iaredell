#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include "attributeBehavior.hpp"

class Wizard : public AttributeBehavior 
{
    private:
        double def = 8;
        double hp = 12;
        double atk = 15;
        double stam = 1.5;
    public:
        Wizard(){}

        virtual double defense(int playerLvl) 
        { 
            return def + (3 * playerLvl) ; 
        }
	    
	    virtual double health_points(int playerLvl)
        {
            return hp + (3 * playerLvl);
        }

        virtual double attack(int playerLvl)
        {
            return atk + (3 * playerLvl) + (1 * playerLvl);
        }

        virtual double mana(int playerLvl)
        {
            return stam + (playerLvl-1)*.2;
        }
        virtual std::string modelType()
        {
            return "Wizard";
        }

};
#endif
