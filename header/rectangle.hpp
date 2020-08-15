#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "graphic.hpp"
#include <utility>

class Rectangle : Graphic {
	private:
		std::pair <int,int> bl;
		std::pair <int,int> tr;
		std::tuple <int,int,int> rgb;
	public:
		Rectangle();
		Rectangle(int, int, int, int);
		Rectangle(int, int, int, int, int, int, int);
		void draw(){};
		Graphic* getChild(int);
		pair<int,int> getTL();
		pair<int,int> getBR();
		tuple getRGB();
};
#endif
