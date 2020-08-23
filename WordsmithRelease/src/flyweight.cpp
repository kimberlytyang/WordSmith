#include "../header/flyweight.hpp"
#include "../header/character.hpp"
#include "../header/graphic.hpp"

#include <unordered_map>
#include <utility>

Character* Flyweight::hash(char c){
	if(CharMap.find(c) == CharMap.end()){
		Character* temp = new Character();
		temp->setC(c);
		CharMap.insert(std::make_pair(c,temp));
	}
	std::unordered_map<char, Character*>::const_iterator got = CharMap.find(c);
	return got->second;
}
