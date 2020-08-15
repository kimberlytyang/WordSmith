#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "graphic.hpp"
#include <utility>
#include <tuple>

class Character : public Graphic {
	private:
		char c;
		int size;
		std::pair<int, int> location;
		std::tuple<int, int, int> color;
	public:
		Character();
		Character(char c);
		Character(char c, int x, int y);
		Character(char c, int x, int y, int r, int g, int b);

		void draw();

		Character* getChild(int i); 
		char getC();
		int getSize();
		std::pair<int, int> getLocation();
		std::tuple<int, int, int> getColor();
		void setC(char c);
		void setSize(int size);
		void setLocation(int x, int y);
		void setColor(int r, int g, int b);
};

#endif
