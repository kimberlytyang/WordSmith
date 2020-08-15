#include "../header/rectangle.hpp"
#include "../header/graphic.hpp"

#include <utility>
#include <tuple>

Rectangle::Rectangle(){
	tl = std::make_pair(0,0);
	br = std::make_pair(0,0);
	color = std::make_tuple(0,0,0);
}

Rectangle::Rectangle(int tlx, int tly, int brx, int bry){
        tl = std::make_pair(tlx,tly);
        br = std::make_pair(brx,bry);
        color = std::make_tuple(0,0,0);

}

Rectangle::Rectangle(int tlx, int tly, int brx, int bry, int r, int g, int b){
        tl = std::make_pair(tlx,tly);
        br = std::make_pair(brx,bry);
        color = std::make_tuple(r,g,b);

}

Rectangle* Rectangle::getChild(int i){
	return this;
}

std::pair<int,int> Rectangle::getTL(){
	return tl;
}

std::pair<int,int> Rectangle::getBR(){
	return br;
}

std::tuple<int,int,int> Rectangle::getColor(){
	return color;
}

void Rectangle::setTL(int x, int y){
	tl = std::make_pair(x,y);
}

void Rectangle::setBR(int x, int y){
	br = std::make_pair(x,y);
}

void Rectangle::setColor(int r, int g, int b){
	color = std::make_tuple(r,g,b);
}
