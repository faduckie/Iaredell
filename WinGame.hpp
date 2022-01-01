#ifndef WINGAME_HPP
#define WINGAME_HPP
#include "game.hpp"
#include "game.cpp"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string.h>

class newGame : public Game
{
    public:
        void dialogueType(std::string x);
        void playerSelection();
        void cls()
        {
             system("cls");
        }
};

void newGame::dialogueType(std::string x)
{
    int i = 0;
    for (i; i < x.size(); i++)
    {
        if (kbhit())         
        {
            if (getch() == 13)
            {
                break;
            }
        }
        std::cout << x[i];
        Sleep(50);
    }
    for (i; i < x.size(); i++)
    {
        std::cout << x[i];
    }
}


void newGame::playerSelection()
{
    system("chcp 65001");
    Attribute model;
    std::string userInput;
    int userKeypress;
    int selectedType;
    player = new PlayableCharacter();

    // PART 1: Name gathering prompt. //
        cls();
        dialogueType("From the deafening silence, you hear a voice.. as if it was calling out to you.");
        std::cout << '\n' << "[Press any Key To Continue...]";
        getch();
        cls();


    while (player->getName().empty() == true)
    {
        userKeypress = 0;
        userInput = "";

        dialogueType("Welcome young warrior, remind me of your name again?");
        std::cout << '\n';
        while(userKeypress != 13)
        {
            userKeypress = getch();
            if (userKeypress == 8)
            {
                if (userInput.empty() == false)
                {
                    userInput.pop_back();
                    cls();
                    std::cout << "Welcome young warrior, remind me of your name again?" << '\n';
                    std::cout << userInput;
                }
            }
            else if (userKeypress >= 20 && userKeypress <= 126)
            {
                userInput.push_back(static_cast<char>(userKeypress));
                std::cout << static_cast<char>(userKeypress);
            }

            // DEBUG MODE: EMERGENCY LOOP BREAK. USE "DEL" KEY. //
            //else if (userKeypress == 127)
            //{
            //    break;
            //}
        }

        while (userInput.size() != 0 && userInput.at(0) == ' ')
        {
            userInput.erase(0, 1);
        }

        cls();
        
        if (userInput.size() != 0)
        {
            dialogueType("Just to make sure, you said your name was " + userInput + " right?" + '\n' + "[a] Yes" + '\n' + "[b] No" + '\n');
            while (1)
            {
                userKeypress = getch();
                if (userKeypress == 'a')
                {
                    player->setPlayerName(userInput);
                    // TEST TO VERIFY NAME HAS BEEN SET //
                    //std::cout << "Name has been successfully set to " << user->getName() << "!" << '\n';
                    //Sleep(5000);
                    break;
                }
                else if (userKeypress == 'b')
                {
                    cls();
                    dialogueType("Okay, let's try this again then...");
                    std::cout << '\n' << "[Press any Key To Continue...]";
                    getch();
                    break;
                }
            }
        }
        else
        {
            dialogueType("I'm sorry, I didn't catch that... Please say that again?");
            std::cout << '\n' << "[Press any Key To Continue...]";
            getch();
        }
        cls();
    }

    // PART 2: Class selection prompt //
    userKeypress = 0;
    selectedType = 0;
    dialogueType("Ah your name is " + player->getPlayerName() + ". I've heard great things about you.\n" + "What kind of warrior are you?\n"); 
    std::cout << '\n' << "[Press any Key To Continue...]";
    getch();
    
    
    
    while(1)
    {
        cls();
        if (selectedType == 0)
        {
             std::cout << "[ROGUE]             " << "WIZARD               " << "KNIGHT               " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[★★★★ ] HP: 13" << '\n' << "[★★★★ ] DEF: 9" << '\n' << "[★★★★ ] ATK: 13" << '\n' << "[★★★★ ] MANA: 1.75" << '\n';             
             std::cout << "BACKGROUND: Coming from a life of poverty, this Rogue has gone through quite a troubled past to learn the fine skills of,\namongst other things, lock-picking, stealth, and thievery.";
        }
        else if (selectedType == 1)
        {
             std::cout << "ROGUE              " << "[WIZARD]              " << "KNIGHT               " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[★★★  ] HP: 12" << '\n' << "[★★★  ] DEF: 8" << '\n' << "[★★★★★] ATK: 15" << '\n' << "[★★★  ] MANA: 1.5" << '\n';             
             std::cout << "BACKGROUND: Once an admired people, wizards were persecuted to the point of extinction due to the fear of their power.\nAll high level wizards are now dead and all that remains are a mediocre batch.";
        }
        else if (selectedType == 2)
        {
             std::cout << "ROGUE               " << "WIZARD              " << "[KNIGHT]              " << "BOB"; 
             std::cout << '\n' << "=================================================================" << '\n';
             std::cout << "STATS:" << '\n' << "[★★★★★] HP: 14" << '\n' << "[★★★★★] DEF: 10" << '\n' << "[★★   ] ATK: 12" << '\n' << "[★★★  ] MANA: 1.5" << '\n';             
             std::cout << "BACKGROUND: This knight has went through alot in the battlefield but after the loss of his family, \nvengance is the only thing on this knight's mind. The target? The government that he works for.";
        }

        else if (selectedType == 3)
        {
            std::cout << "ROGUE               " << "WIZARD               " << "KNIGHT             " << "[BOB]"; 
            std::cout << '\n' << "=================================================================" << '\n';
            std::cout << "STATS:" << '\n' << "[★★   ] HP: 10" << '\n' << "[★    ] DEF: 5" << '\n' << "[★    ] ATK: 10" << '\n' << "[★★★★★] MANA: 2" << '\n';
            std::cout << "BACKGROUND: A simpleton. Tax evasion is his secret hidden talent.";
        }

        userKeypress = getch();
        // KEYPRESS TEST //
        // std::cout << userKeypress;

        if (userKeypress == 77 && selectedType < 3)
        {
            ++selectedType;
        }
        else if (userKeypress == 75 && selectedType > 0)
        {
            --selectedType;
        }

        else if (userKeypress == 13)
        {
            std::cout << '\n';
            std::cout.flush();
            dialogueType("Are you sure you want to pick this class?");
            std::cout << '\n' << "[a] Yes" << '\n' << "[b] No" << '\n';
            while (userKeypress != 'a' && userKeypress != 'b')
            {
                userKeypress = getch();
            }
            if (userKeypress == 'a')
            {
                player->setCharacterType(selectedType + 1);
                break;
            }
        }
    }


    selectedType = 0;
    userKeypress = 0;
    dialogueType("Now, which one of these weapons are yours..?");
    while (1)
    {
        cls();
        if (selectedType == 0)
        {
            std::cout << "Now, which one of these weapons are yours..? \n";
            std::cout << "[STAFF]             " << "LONG SWORD               " << "DAGGER               " << "BROOM\n"; 
        }
        else if (selectedType == 1)
        {
            std::cout << "Now, which one of these weapons are yours..? \n";
            std::cout << "STAFF              " << "[LONG SWORD]              " << "DAGGER               " << "BROOM\n"; 

        }
        else if (selectedType == 2)
        {
            std::cout << "Now, which one of these weapons are yours..? \n";
            std::cout << "STAFF               " << "LONG SWORD              " << "[DAGGER]            " << "BROOM\n"; 
        }
        else if (selectedType == 3)
        {
            std::cout << "Now, which one of these weapons are yours..? \n";
            std::cout << "STAFF               " << "LONG SWORD               " << "DAGGER             " << "[BROOM]\n"; 
        }
        
        userKeypress = getch();

        if (userKeypress == 77 && selectedType < 3)
        {
            ++selectedType;
        }
        else if (userKeypress == 75 && selectedType > 0)
        {
            --selectedType;
        }
        else if (userKeypress == 13)
        {
            std::cout << '\n';
            std::cout.flush();
            dialogueType("Are you sure you want to pick this weapon?");
            std::cout << '\n' << "[a] Yes" << '\n' << "[b] No" << '\n';
            while (userKeypress != 'a' && userKeypress != 'b')
            {
                userKeypress = getch();
            }
            if (userKeypress == 'a')
            {
                player->setWeaponType(selectedType + 1);
                break;
            }
        }
    }
    cls();
    dialogueType("Lets begin with your training...");
    std::cout << '\n' << "[Press any Key To Continue...]";
    getch();
    cls();
}
#endif //WINGAME_HPP
