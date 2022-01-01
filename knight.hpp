#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "attributeBehavior.hpp"

class Knight : public AttributeBehavior 
{
    private:
        double def = 10;
        double hp = 14;
        double atk = 12;
        double stam = 1.5;
    public:
        Knight(){}

        virtual double defense(int playerLvl) 
        { 
            return def + (3 * playerLvl) ; 
        }
	    
	    virtual double health_points(int playerLvl)
        {
            return hp + (3 * playerLvl) + (1*playerLvl);
        }

        virtual double attack(int playerLvl)
        {
            return atk + (3* playerLvl);
        }

        virtual double mana(int playerLvl)
        {
            return stam + (playerLvl-1)*.2;
        }

        virtual std::string modelType()
        {
            return "Knight";
        }
       

};
#endif