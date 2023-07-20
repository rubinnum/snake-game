#include "Game.h"

Game* game = new Game();

int main(int argc, char* args[]) {
	game->init("SDL2 Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clear();


	return 0;
}