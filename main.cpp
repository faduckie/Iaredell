#if _WIN32
#include "BaseGameFiles/WinGame.hpp"
#elif __linux__
#include "BaseGameFiles/UnixGame.hpp"
#elif __APPLE__
#include "BaseGameFiles/UnixGame.hpp"
#endif
#include <iomanip>




int main(int argc, char* argv[]){
       std::cout << std::fixed << std::showpoint << std::setprecision(2);
       newGame* GameClient = new newGame();
       if (GameClient->mainMenu())
       {
             GameClient->playerSelection();
             GameClient->tutorial();
             GameClient->scene1();
             GameClient->scene2();
	     GameClient->scene3();
       }
       delete GameClient;
       return 0;
}
