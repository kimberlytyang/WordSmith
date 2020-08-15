#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "graphic.hpp"
#include <utility>
#include <tuple>

class Rectangle : Graphic {
	private:
		std::pair <int,int> tl;
		std::pair <int,int> br;
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
