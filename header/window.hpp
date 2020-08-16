#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphic.hpp"
#include <vector>

class Window : public Graphic {
	private:
		std::pair<int, int> tl;
		std::pair<int, int> br;
		std::vector<Graphic*> graphics;
	public:
		Window();
		Window(int x1, int y1, int x2, int y2);
		
		void draw();
		void insert(Graphic* g);
		void remove(Graphic* g);
		Graphic* getChild(int i);
		std::pair<int, int> getTL();
		std::pair<int, int> getBR();
		void setTL(int x, int y);
		void setBR(int x, int y);
};

#endif
