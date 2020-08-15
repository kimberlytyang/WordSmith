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

TEST(LineTest, SettersTestPositive) {
	Line* test = new Line();
	test->setStart(12, 7);
	test->setEnd(15, 21);
	test->setColor(250, 120, 35);

	EXPECT_EQ(test->getStart().first, 12);
	EXPECT_EQ(test->getStart().second, 7);
	EXPECT_EQ(test->getEnd().first, 15);
	EXPECT_EQ(test->getEnd().second, 21);
	EXPECT_EQ(get<0>(test->getColor()), 250);
	EXPECT_EQ(get<1>(test->getColor()), 120);
	EXPECT_EQ(get<2>(test->getColor()), 35);
}

TEST(LineTest, SettersTestNegative) {
	Line* test = new Line();
	test->setStart(-12, -7);
	test->setEnd(-15, -21);
	test->setColor(250, 120, 35);

	EXPECT_EQ(test->getStart().first, -12);
	EXPECT_EQ(test->getStart().second, -7);
	EXPECT_EQ(test->getEnd().first, -15);
	EXPECT_EQ(test->getEnd().second, -21);
	EXPECT_EQ(get<0>(test->getColor()), 250);
	EXPECT_EQ(get<1>(test->getColor()), 120);
	EXPECT_EQ(get<2>(test->getColor()), 35);
}

TEST(LineTest, GetChildTest) {
	Line* test1 = new Line();
	Line* test2 = new Line(1, 2, 3, 4);
	Line* test3 = new Line(12, 15, 17, 15, 100, 100, 100);

	EXPECT_EQ(test1->getChild(0), test1);
	EXPECT_EQ(test2->getChild(0), test2);
	EXPECT_EQ(test3->getChild(0), test3);
}

#endif // LINE_TEST_HPP
