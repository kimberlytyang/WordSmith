#include "../header/rectangle.hpp"

#include <utility>
#include <tuple>
#include <iostream>

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

void Rectangle::draw(SDL_Renderer* r) {
	//SDL_RenderClear(r);

	SDL_Rect temp;
	temp.x = this->getTL().first;
	temp.y = this->getTL().second;
	temp.w = (this->getBR().first - this->getTL().first);
	temp.h = (this->getBR().second - this->getTL().second);
	std::cout << temp.x << " " << temp.y << " " << temp.w <<" " <<  temp.h << std::endl;
	
	SDL_SetRenderDrawColor(r, std::get<0>(this->getColor()), std::get<1>(this->getColor()), std::get<2>(this->getColor()), 255);
	SDL_RenderFillRect(r, &temp);
	//SDL_SetRenderDrawColor(r, 255, 255, 255, 255);

	SDL_RenderPresent(r);

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
