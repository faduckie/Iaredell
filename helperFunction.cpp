#include "helperFunction.hpp"
#include <limits.h>



int verifyIntInput(std::string input) // returns -1 if inproper input
{
    // erasing whitespace incase user enters " 1" instead of "1" by mistake
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	bool isNumber = true;
	int x;
	for (int i = 0; i < input.length(); i++) // checking each character in string
		if (!isdigit(input[i])) isNumber = false; // checking if all characters input are digits

	if (isNumber == true) // if string is an integer
	{
		std::stringstream num(input);
		num >> x; // storing string to an int
	}
	else x = -1; // if string is not an int return value of -2
	return x;
}

bool verifyStringInput(std::string input)
{
    bool isValid = true;
	if (isalpha(input[0])) // checking is name starts with a letter
	{
		for (int unsigned i = 0; i < input.length(); i++)
			if (!(isalnum(input[i]) || isspace(input[i]))) // checking is name is only alphanumeric and white space
				isValid = false;
	}
	else isValid = false;
	return isValid;
}


void validateInput(std::string prompt, int& userInput, int expected) {
   

	while (userInput != expected) {
        std::cout << "\033[F";
        std::cout << prompt << " ";
		std::cin >> userInput;
		if (std::cin.fail() == true)
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
    }
    std::cout << std::endl;
    std::cin.get();
}

void validateInput(std::string prompt, int& userInput, int expected1, int expected2) {

    while (userInput != expected1 && userInput != expected2) {
        std::cout << "\033[F";
        std::cout << prompt << " ";
		std::cin >> userInput;
		if (std::cin.fail() == true)
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
    }
    std::cout << std::endl;
    std::cin.get();
}

void displayArt(std::string fileName){
	std::ifstream file;
	file.open(fileName);
	if(file.fail())
		std::cout << "Failed to open ASCII file";
	
		
	std::cout << std::endl;
	std::string temp;
	while(!file.eof()){
		getline(file, temp);
		std::cout << "\t\t\t"  << temp << std::endl;
	}

	std::cout << std::endl;

	file.clear();
	file.seekg(0, std::ios::beg);
}
