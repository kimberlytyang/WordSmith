#ifndef LINE_TEST_HPP
#define LINE_TEST_HPP

#include "../header/line.hpp"

TEST(LineTest, DefaultConstructorGettersTest) {
	Line* test = new Line();
	EXPECT_EQ(test->getStart().first, 0);
	EXPECT_EQ(test->getStart().second, 0);
	EXPECT_EQ(test->getEnd().first, 0);
        EXPECT_EQ(test->getEnd().second, 0);
	EXPECT_EQ(get<0>(test->getColor()), 0);
	EXPECT_EQ(get<1>(test->getColor()), 0);
	EXPECT_EQ(get<2>(test->getColor()), 0);
}

TEST(LineTest, CoordinateConstructorGettersTest) {
        Line* test = new Line(4, 15, 17, 15);
        EXPECT_EQ(test->getStart().first, 4);
        EXPECT_EQ(test->getStart().second, 15);
        EXPECT_EQ(test->getEnd().first, 17);
        EXPECT_EQ(test->getEnd().second, 15);
        EXPECT_EQ(get<0>(test->getColor()), 0);
        EXPECT_EQ(get<1>(test->getColor()), 0);
        EXPECT_EQ(get<2>(test->getColor()), 0);
}

TEST(LineTest, FullConstructorGettersTest) {
        Line* test = new Line(4, 15, 17, 15, 100, 215, 75);
        EXPECT_EQ(test->getStart().first, 4);
        EXPECT_EQ(test->getStart().second, 15);
        EXPECT_EQ(test->getEnd().first, 17);
        EXPECT_EQ(test->getEnd().second, 15);
        EXPECT_EQ(get<0>(test->getColor()), 100);
        EXPECT_EQ(get<1>(test->getColor()), 215);
        EXPECT_EQ(get<2>(test->getColor()), 75);
}

#endif // LINE_TEST_HPP
