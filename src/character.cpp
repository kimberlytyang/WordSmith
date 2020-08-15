#include "../header/character.hpp"

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

void Character::draw() {}

Character* Character::getChild(int i) { return this; }

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
