#include "rectangle.hpp"
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
