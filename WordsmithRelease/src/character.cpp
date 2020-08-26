#include "../header/character.hpp"
#include <string>

Character::Character() {
	c = 0;
	size = 12;
	location = std::make_pair(0, 0);
	color = std::make_tuple(0, 0, 0);
}

Character::Character(char c) {
	this->c = c;
        size = 12;
        location = std::make_pair(0, 0);
        color = std::make_tuple(0, 0, 0);
}

Character::Character(char c, int x, int y) {
	this->c = c;
        size = 12;
        location = std::make_pair(x, y);
        color = std::make_tuple(0, 0, 0);
}

Character::Character(char c, int x, int y, int r, int g, int b) {
	this->c = c;
        size = 12;
        location = std::make_pair(x, y);
        color = std::make_tuple(r, g, b);
}

void Character::draw(SDL_Renderer* r) {
	//std::cout << "drawing " << this->getC();
	if (this->getC() == ' ') {
		this->setC('_');
	}
	TTF_Font* font = TTF_OpenFont("res/courbd.ttf", 20);
	SDL_Color color = { std::get<0>(this->getColor()),std::get<0>(this->getColor()),std::get<0>(this->getColor()) };
	std::string temp(1, this->getC());
	if (this->getC() == '/') {
		temp = "_";
	}
	SDL_Surface* surface = TTF_RenderText_Solid(font, temp.c_str() , color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(r, surface);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { this->getLocation().first, this->getLocation().second, texW, texH };
	SDL_RenderCopy(r, texture, NULL, &dstrect);
	SDL_RenderPresent(r);
	TTF_CloseFont(font);

}

Graphic* Character::getChild(int i) { return this; }

char Character::getC() { return c; }

int Character::getSize() { return size; }

std::pair<int, int> Character::getLocation() { return location; }

std::tuple<int, int, int> Character::getColor() { return color; }

void Character::setC(char c) { this->c = c; }

void Character::setSize(int size) { this->size = size; }

void Character::setLocation(int x, int y) {
	location.first = x;
	location.second = y;
}

void Character::setColor(int r, int g, int b) {
	std::get<0>(color) = r;
	std::get<1>(color) = g;
	std::get<2>(color) = b;
} 
