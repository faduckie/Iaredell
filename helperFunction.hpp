#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include<fstream>
//----------------

extern bool verifyStringInput( std::string input);
extern int verifyIntInput(std::string input);
extern void validateInput(std::string prompt, int& userInput, int expected);
extern void validateInput(std::string prompt, int& userInput, int expected1, int expected2);
extern void displayArt(std::string fileName);

#endif