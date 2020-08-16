#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphic.hpp"
#include <vector>

class Window : public Graphic {
	private:
		std::pair <int,int> tl;
		std::pair <int,int> br;
		vector<Graphic*> graphics;
	public:
		Graphic();
		Graphic(int x1, int y2, int x2, int y2);
		
		void draw();
		void insert(Graphic* g);
		void remove(Graphic* g);
		Graphic* getChild(int i);
};

#endif
