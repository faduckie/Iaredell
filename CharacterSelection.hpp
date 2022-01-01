#ifndef CHARACTERSELECTION_HPP
#define CHARACTERSELECTION_HPP

#include <iostream>
#include <string>

class Character
{
    private:
        std::string name;
    public:
        std::string getName();
        void setName(std::string n);
};

std::string Character::getName()
{
    return name;
}

void Character::setName(std::string n)
{
    name = n;
}

#endif //CHARACTERSELECTION_HPP