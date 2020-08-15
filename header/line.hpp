#ifndef LINE_HPP
#define LINE_HPP

#include "graphic.hpp"
#include <utility>
#include <tuple>

using namespace std;

class Line : public Graphic {
	private: 
		pair<int, int> start;
		pair<int, int> end;
		tuple<int, int, int> color;
	public:
		Line();
		Line(int xS, int yS, int xE, int yE);
		Line(int xS, int yS, int xE, int yE, int r, int g, int b);
		void draw();
		Graphic* getChild(int i);
		pair<int, int> getStart();
		pair<int, int> getEnd();
		tuple<int, int, int> getColor();
		void setStart(int x, int y);
		void setEnd(int x, int y);
		void setColor(int r, int g, int b);
};

#endif // LINE_HPP
