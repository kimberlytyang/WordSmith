#ifndef FLYWEIGHT_HPP
#define FLYWEIGHT_HPP

#include "character.hpp"
#include "graphic.hpp"

#include <unordered_map>

class Character;

class Flyweight{
	private:
		std::unordered_map<char,Character*> CharMap;
	public:
		Character* hash(char c);
};




#endif
