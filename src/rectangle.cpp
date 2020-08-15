#include "../header/rectangle.hpp"
#include "../header/graphic.hpp"

#include <utility>
#include <tuple>

Rectangle::Rectangle(){
	tl = std::make_pair(0,0);
	br = std::make_pair(0,0);
	rgb = std::make_tuple(0,0,0);
}

Rectangle::Rectangle(int tlx, int tly, int brx, int bry){
        tl = std::make_pair(tlx,tly);
        br = std::make_pair(brx,bry);
        rgb = std::make_tuple(0,0,0);

}

Rectangle::Rectangle(int tlx, int tly, int brx, int bry, int r, int g, int b){
        tl = std::make_pair(tlx,tly);
        br = std::make_pair(brx,bry);
        rgb = std::make_tuple(r,g,b);

}

Graphic* Rectangle::getChild(int i){
	return this;
}

std::pair<int,int> Rectangle::getTL(){
	return tl;
}

std::pair<int,int> Rectangle::getBR(){
	return br;
}

std::tuple<int,int,int> Rectangle::getRGB(){
	return rgb;
}

void Rectangle::setTL(int x, int y){
	tl = std::make_pair(x,y);
}

void Rectangle::setBR(int x, int y){
	br = std::make_pair(x,y);
}

void Rectangle::setColor(int r, int g, int b){
	rgb = std::make_tuple(r,g,b);
}
