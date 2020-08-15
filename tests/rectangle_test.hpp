#ifndef RECTANGLE_TEST_HPP
#define RECTANGLE_TEST_HPP

#include "../header/rectangle.hpp"
#include <utility>
#include <tuple>

TEST(RectangleTest, getTLTest){
	Rectangle* test = new Rectangle(5,2,0,0);
	std::pair<int,int> tl = test->getTL();
	EXPECT_EQ(tl.first, 5);
	EXPECT_EQ(tl.second,2);
}

TEST(RectangleTest, getBRTest){
	Rectangle* test = new Rectangle(0,0,15,2);
	std::pair<int,int> br = test->getBR();
	EXPECT_EQ(br.first,15);
	EXPECT_EQ(br.second,2);
}



#endif
