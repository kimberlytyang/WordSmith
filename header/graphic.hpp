#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP


class Graphic {
	public:
		Graphic() { };
		virtual void draw() = 0;
		virtual void insert(Graphic* g){};
		virtual void remove(Graphic* g){};
		virtual Graphic* getChild(int i) = 0;
};
#endif
