#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) == 0) {
		Uint32 flags = 0;
		if (fullscreen) {
			flags = 1;
		}
		std::cout << "The game was successfully initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "The window was successfully created" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // background
			if (renderer) {
				std::cout << "The renderer was successfully created" << std::endl;
			}
			isRunning = true;
		}
	}
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clear() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "The game was successfully finished" << std::endl;
}

