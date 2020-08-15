#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <utility>
#include <tuple>

class Graphic {
	public:
		Graphic() {}
		virtual void draw() = 0;
		virtual void insert(Graphic*) {}
		virtual void remove(Graphic*) {}
		virtual Graphic* getChild(int i) = 0;
		virtual char getC() { return '0'; }
		virtual int getSize() { return 0; }
		virtual std::pair<int, int> getLocation() { return std::make_pair(0, 0); }
		virtual std::tuple<int, int, int> getColor() { return std::make_tuple(0, 0, 0); }
		virtual void setC(char) {}
		virtual void setSize(int size) {}
		virtual void setLocation(int, int) {}
		virtual void setColor(int, int, int) {}
		virtual std::pair<int, int> getTL() { return std::make_pair(0, 0); }
		virtual std::pair<int, int> getBR() { return std::make_pair(0, 0); }
		virtual void setTL(int, int) {}
		virtual void setBR(int, int) {}
		virtual std::pair<int, int> getStart() { return std::make_pair(0, 0); }
		virtual std::pair<int, int> getEnd() { return std::make_pair(0, 0); }
		virtual void setStart(int, int) {}
		virtual void setEnd(int, int) {}
};

#endif
