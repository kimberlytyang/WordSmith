#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "graphic.hpp"
#include <utility>
#include <tuple>

class Rectangle : public Graphic {
	private:
		std::pair <int,int> tl;
		std::pair <int,int> br;
		std::tuple <int,int,int> color;
	public:
		Rectangle();
		Rectangle(int, int, int, int);
		Rectangle(int, int, int, int, int, int, int);
		void draw(SDL_Renderer*);
		Graphic* getChild(int);
		std::pair<int,int> getTL();
		std::pair<int,int> getBR();
		std::tuple<int,int,int> getColor();
		void setTL(int,int);
		void setBR(int,int);
		void setColor(int, int, int);
};
#endif
