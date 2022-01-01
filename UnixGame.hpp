#ifndef UNIXGAME_HPP
#define UNIXGAME_HPP
#include "game.hpp"
#include "game.cpp"

#include <iostream>



class newGame : public Game
{
    public:
        void dialogueType(std::string x);
        void playerSelection();
        void cls()
        {
             std::cout << "\033[2J\033[1;1H";
        }
};


void newGame::dialogueType(std::string x)
{

}

void newGame::playerSelection()
{
    std::string playerName = "0", intInput = "-1";//characterType = "-1", weaponType = "-1";
    bool validated = false;
    Attribute model;
    player = new PlayableCharacter();
    cls();
	std::cout<<"Welcome young warrior, remind me of your name again.\n";
	while(!verifyStringInput(playerName))
	{
		std::cout<<"\tEnter name: ";
		std::getline(std::cin, playerName);
		if(!verifyStringInput(playerName))
			std::cout<<"\tThat is an invalid name, try again.\n";
			std::cout << "\033[F";
			std::cout << "\033[F";
	}
	cls();
	player->setPlayerName(playerName);
	std::cout<<"Ah your name is "<< player->getPlayerName() << ". I've heard great things about you.\n";
	while(verifyIntInput(intInput) == -1 || validated == false)
	{
		std::cout<<"What kind of warrior are you?\n";
		std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
		std::cout<<"\t[1] Wizard\n\t[2] Knight\n\t[3] Rogue\n\t[4] Bob\n";
		std::cout<<"\tEnter choice: ";
		std::getline(std::cin, intInput);
		if(verifyIntInput(intInput)<1 || verifyIntInput(intInput)>4)
		{
				std::cout<<"\tInvalid input. Try again\n";
				validated = false;
		}
		else{
			cls();
			std::cout<<"Player Type: \n"<<std::endl;
			int characterType = verifyIntInput(intInput);
			switch(characterType)
			{
			case 1: model.setBehavior(new Wizard()); break;
			case 2: model.setBehavior(new Knight()); break;
			case 3: model.setBehavior(new Rogue()); break;
			case 4: model.setBehavior(new Bob()); break;
			default: break;
			}
			model.setStats();
			model.printBaseStats();
			switch(characterType)
            {
            case 1:
                std::cout << "\nBACKGROUND: Once an admired people, wizards were persecuted\n"
										"\t    to the point of extinction due to the fear of their power.\n"
										"\t    All high level wizards are now dead and all that remains are a mediocre batch.";
                break;
            case 2: 
                std::cout << "\nBACKGROUND: This knight has went through alot in the battlefield\n"
										"\t    but after the loss of his family, vengance is the only thing\n"
										"\t    on this knight's mind. The target? The government that he works for.";

                break;
            case 3:
				std::cout << "\nBACKGROUND: Coming from a life of poverty,this Rogue has\n" 
										  "\t    gone through quite a troubled past to learn the fine skills of,\n"
										  "\t    amongst other things, lock-picking, stealth, and thievery.";
 
                break;
            case 4:
                std::cout << "\nBACKGROUND: A simpleton. Tax evasion is his secret hidden talent.";
                break;
            default: break;
            }
			std::cout<<"\n\nAre you sure you want to be a "<< model.getModelType() <<"? [1] yes [2] no\n Enter: ";
			std::getline(std::cin, intInput);
			if(verifyIntInput(intInput) == 1)
			{
				cls();
				player->setCharacterType(characterType);
				cls();
               	while(validated==false)
                {
                	std::cout<<"What weapon do you use?\n";
                    std::cout<<"\t[1] Staff\n\t[2] Longsword\n\t[3] Dagger\n\t[4] Broom\n";
                    std::cout<<"\tEnter choice: ";
                    std::getline(std::cin, intInput);
                    if(verifyIntInput(intInput)<1 || verifyIntInput(intInput)>4)
		            {
				        std::cout<<"\tInvalid input. Try again\n";
				        validated = false;
		            }
                    else 
                    { 
                        player ->setWeaponType(verifyIntInput(intInput));
    			        validated = true;
                    }
                }
			}
			else cls();
		}
	}
	cls();
	std::cout<<"Lets begin with your training "<< player->getPlayerName()<<std::endl;
}





#endif //UNIXGAME_HPP

