#include "Core\GameManager.h"
#include <iostream>


int main() {
	
	//The main function calls the init and run functions of the game manager.
	GameManager Game;
	Game.Init();
	Game.Run();



	return 0;
}