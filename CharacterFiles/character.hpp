#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
#include <vector>
#include <fstream>
#include "../BaseGameFiles/helperFunction.hpp"

class Character {
protected:
    std::string name, pName;
    std::vector<std::string> dialogue;
    int index = -1;

public:
    Character() {}

    Character(std::string name) { this->name = name; }
    std::string getName() { return name; }
    void setName(std::string n) { name = pName = n; }
    std::string getPlayerName() { return pName;}
    void setPlayerName(std::string playerName)
    {
        name = "Player";
        pName = playerName;
    }

    std::string getLineAt(int index) { return dialogue.at(index); }
    int lineCount() { return dialogue.size(); }
    std::string nextLine() {
        ++index;
        return dialogue.at(index);
    }
    int getIndex() { return index; }

    void populateDialogue(std::ifstream& file) {
        file.clear();
        file.seekg(0, std::ios::beg);   //reset to beginning of file
        std::string findName = Character::getName();
        for (int i = 0; i < findName.size(); i++) {
            findName[i] = toupper(findName[i]);
        }
        while (!file.eof()) {           //while not at end of file
            std::string temp = "";      //create temp string
            getline(file, temp);        //retrieve line 
            std::size_t found = temp.find(findName);
            if (found != std::string::npos) //if name is found in line
                dialogue.push_back(temp.substr(findName.size() + 2));  //add to dialogue vector

        }
    }

    void clearDialogueLines(){
	// for(int i = 0; i < dialogue.size(); i++)
	    dialogue.clear();
	 index = -1;
	 //std::cout << dialogue.size();
    }
};

#endif
