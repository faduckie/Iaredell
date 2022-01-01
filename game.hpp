#ifndef GAME_HPP
#define GAME_HPP

#ifdef __unix__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#elif _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#elif __APPLE__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#endif

#include "helperFunction.cpp"
#include "../WeaponsFiles/weapons.cpp"
#include "../WeaponsFiles/weaponBehavior.hpp"
#include "../WeaponsFiles/longSword.hpp"
#include "../WeaponsFiles/dagger.hpp"
#include "../WeaponsFiles/staff.hpp"
#include "../WeaponsFiles/broom.hpp"
#include "../CharacterFiles/attribute.cpp"
#include "../CharacterFiles/attributeBehavior.hpp"
#include "../CharacterFiles/wizard.hpp"
#include "../CharacterFiles/rogue.hpp"
#include "../CharacterFiles/bob.hpp"
#include "../CharacterFiles/knight.hpp"
#include "../CharacterFiles/attackCharacter.hpp"
#include "../CharacterFiles/character.hpp"
#include "../CharacterFiles/playableCharacter.hpp"
#include "../CharacterFiles/npAttackCharacter.hpp"
#include <fstream>
#include <iostream>

class Game
{
    protected:
        PlayableCharacter* player;

    public:
        Game(){}
        ~Game(){ delete player; }
        virtual void dialogueType(std::string x) = 0;
        virtual void playerSelection() = 0;
        virtual void cls() = 0;
        void BatlleScene(NPAttackCharacter* npc);
        void MustWinBattleScene(NPAttackCharacter* npc);
        bool ConditionalBattleScene(NPAttackCharacter* npc);
        void tutorial();
        void scene1();
        void scene2();
        void scene3();
	bool mainMenu();
};

#endif //GAME_HPP
