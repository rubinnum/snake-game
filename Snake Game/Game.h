#pragma once
#include <SDL.h>
#include <SDL_image.h> 
#include <iostream>

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clear();
	bool running() { return isRunning; }
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning = false;
};