//SDLL LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include <time.h>
#include <cstring>
#include <iostream>

//COMPOSITEINCLUDES

#include "header/game.hpp"

Game* game = nullptr;





int main(int argc, char** argv) {
	game = new Game();
	game->init("WordSmith", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while (game->running()) {
		game->handleEvents();	
	}
	
	game->clean();
	
	

	return 0;
}