#ifndef GAME_HPP
#define GAME_HPP

#include "header/prompt_selector.hpp"
#include "header/parse_novice.hpp"
#include "header/parse_intermediate.hpp"
#include "header/parse_advanced.hpp"
#include "header/parse_random.hpp"
#include "header/parse.hpp"
#include "header/character.hpp"
#include "header/flyweight.hpp"
#include "header/line.hpp"
#include "header/rectangle.hpp"
#include "header/window.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctype.h>

class Game {
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Renderer* renderer1;
	Window* gameWindow;
	int tick = 0;
	clock_t time = 0;
	bool gameStart = false;
	Rectangle* timeblock;
	int ptime;
	int rawprompt = 0;
	int count = 0;
	int correct = 0;
	int mistakes = 0;
	int currChar = 0;
	int diff = 0;
	PromptSelector* ps = nullptr;
	string gameName = "";
	int frame = 0;
	int WPM = 0;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	void diffSelector();
	void updateTimer(SDL_Renderer* r, int t);
	void setDiff(int i) { diff = i; }
	Parse* getDiffG(int i);
	void fill(Flyweight* fw, int &len, int line, char ch, int cy);
	void drawString(string s, int x, int y, int r, int g, int b, int f);
	SDL_Renderer* getRenderer() { return renderer;}
	void cycleImage(string s);
	void drawImage(string path, int x, int y, int w, int h);
};

#endif // !GAME_HPP
