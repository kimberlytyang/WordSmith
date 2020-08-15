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

TEST(RectangleTest, getColorTest){
	Rectangle* test = new Rectangle(0,0,0,0,123,222,231);
	std::tuple<int,int,int> color = test->getColor();
	EXPECT_EQ(std::get<0>(color),123);
	EXPECT_EQ(std::get<1>(color),222);
	EXPECT_EQ(std::get<2>(color),231);
}

TEST(RectangleTest, setColorTest){
	Rectangle* test = new Rectangle(0,0,0,0,0,0,0);
	test->setColor(123,212,211);
	EXPECT_EQ(std::get<0>(test->getColor()),123);
	EXPECT_EQ(std::get<1>(test->getColor()),212);
	EXPECT_EQ(std::get<2>(test->getColor()),211);
}

TEST(RectangleTest, setTLTest){
        Rectangle* test = new Rectangle(0,0,0,0,0,0,0);
	test->setTL(555,635);
	EXPECT_EQ(test->getTL().first,555);
	EXPECT_EQ(test->getTL().second,635);
}

TEST(RectangleTest, setBRTest){
        Rectangle* test = new Rectangle(0,0,0,0,0,0,0);
	test->setBR(849,928);
	EXPECT_EQ(test->getBR().first,849);
	EXPECT_EQ(test->getBR().second,928);
}

TEST(RectangleTest, getChild){
	Rectangle* test = new Rectangle(661,714,027,766,171,402,776);
	EXPECT_EQ(((test->getChild(1))->getTL()).first,(test->getTL()).first);
	EXPECT_EQ(((test->getChild(1))->getTL()).second,(test->getTL()).second);
	EXPECT_EQ(((test->getChild(1))->getBR()).first,(test->getBR()).first);
	EXPECT_EQ(((test->getChild(1))->getBR()).second,(test->getBR()).second);
	EXPECT_EQ(std::get<0>((test->getChild(1))->getColor()),std::get<0>(test->getColor()));
        EXPECT_EQ(std::get<1>((test->getChild(1))->getColor()),std::get<1>(test->getColor()));
        EXPECT_EQ(std::get<2>((test->getChild(1))->getColor()),std::get<2>(test->getColor()));

}

#endif
