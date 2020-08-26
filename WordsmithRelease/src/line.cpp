#include "../header/line.hpp"
#include <utility>
#include <tuple>


Line::Line() {
	start = make_pair(0, 0);
	end = make_pair(0, 0);
	color = make_tuple(0, 0, 0);
}

Line::Line(int xS, int yS, int xE, int yE) {
	start = make_pair(xS, yS);
        end = make_pair(xE, yE);
        color = make_tuple(0, 0, 0);
}

Line::Line(int xS, int yS, int xE, int yE, int r, int g, int b) {
	start = make_pair(xS, yS);
        end = make_pair(xE, yE);
        color = make_tuple(r, g, b);
}

void Line::draw(SDL_Renderer* r) {
	SDL_SetRenderDrawColor(r, get<0>(this->getColor()), get<1>(this->getColor()), get<2>(this->getColor()), 255);
	SDL_RenderDrawLine(r, this->getStart().first,this->getStart().second, this->getEnd().first, this->getEnd().second);
	//std::cout << this->getStart().first << " " << this->getStart().second << std::endl;

	SDL_RenderPresent(r);
}

Graphic* Line::getChild(int i) {
	return this;
}

pair<int, int> Line::getStart() {
	return start;
}

pair<int, int> Line::getEnd() {
	return end;
}

tuple<int, int, int> Line::getColor() {
	return color;
}

void Line::setStart(int x, int y) {
	start = make_pair(x, y);
}

void Line::setEnd(int x, int y) {
	end = make_pair(x, y);
}

void Line::setColor(int r, int g, int b) {
	color = make_tuple(r, g, b);
}
