#ifndef __BOB_HPP__
#define __BOB_HPP__

#include "attributeBehavior.hpp"

class Bob : public AttributeBehavior 
{
    private:
        double def = 5;
        double hp = 10;
        double atk = 10;
        double stam = 2;
    public:
        Bob(){}

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
            return atk + (3 * playerLvl);
        }

        virtual double mana(int playerLvl)
        {
            return stam + (playerLvl-1) * .2;
        }

        virtual std::string modelType()
        {
            return "Bob";
        }
       

};
#endif