#include "../header/window.hpp"

Window::Window() {
	tl = std::make_pair(0, 0);
	br = std::make_pair(0, 0);	
}

Window::Window(int x1, int y1, int x2, int y2) {
        tl = std::make_pair(x1,y1);
        br = std::make_pair(x2, y2);
}

void Window::draw() {};

void Window::insert(Graphic* g) {
	graphics.push_back(g);
}

void Window::remove(Graphic* g) {
	for (auto it = graphics.begin(); it != graphics.end(); ++it) {
		if(*it == g)
			graphics.erase(it);
	}	
}

Graphic* Window::getChild(int i) {
	return graphics.at(i);
}

std::pair<int, int> Window::getTL() { return tl; }

std::pair<int, int> Window::getBR() { return br; }

void Window::setTL(int x, int y) { tl = std::make_pair(x, y); }

void Window::setBR(int x, int y) { br = std::make_pair(x, y); }
