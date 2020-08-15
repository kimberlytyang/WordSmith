#ifndef CHARACTER_TEST
#define CHARACTER_TEST

#include "../header/character.hpp"

TEST(CharacterTest, DefaultConstructor) {
	Character* test = new Character();

	EXPECT_EQ(test->getC(), 0);
	EXPECT_EQ(test->getSize(), 12);
	EXPECT_EQ(test->getLocation().first, 0);
	EXPECT_EQ(test->getLocation().second, 0);
	EXPECT_EQ(get<0>(test->getColor()), 0);
	EXPECT_EQ(get<1>(test->getColor()), 0);
	EXPECT_EQ(get<2>(test->getColor()), 0);
}

TEST(CharacterTest, CharConstructor) {
        Character* test = new Character('a');

        EXPECT_EQ(test->getC(), 'a');
        EXPECT_EQ(test->getSize(), 12);
        EXPECT_EQ(test->getLocation().first, 0);
        EXPECT_EQ(test->getLocation().second, 0);
        EXPECT_EQ(get<0>(test->getColor()), 0);
        EXPECT_EQ(get<1>(test->getColor()), 0);
        EXPECT_EQ(get<2>(test->getColor()), 0);
}

TEST(CharacterTest, CoordinateConstructor) {
        Character* test = new Character('?', 3, 6);

        EXPECT_EQ(test->getC(), '?');
        EXPECT_EQ(test->getSize(), 12);
        EXPECT_EQ(test->getLocation().first, 3);
        EXPECT_EQ(test->getLocation().second, 6);
        EXPECT_EQ(get<0>(test->getColor()), 0);
        EXPECT_EQ(get<1>(test->getColor()), 0);
        EXPECT_EQ(get<2>(test->getColor()), 0);
}

TEST(CharacterTest, ColorConstructor) {
        Character* test = new Character('8', 3, 6, 15, 55, 95);

        EXPECT_EQ(test->getC(), '8');
        EXPECT_EQ(test->getSize(), 12);
        EXPECT_EQ(test->getLocation().first, 3);
        EXPECT_EQ(test->getLocation().second, 6);
        EXPECT_EQ(get<0>(test->getColor()), 15);
        EXPECT_EQ(get<1>(test->getColor()), 55);
        EXPECT_EQ(get<2>(test->getColor()), 95);
}

TEST(CharacterTest, SetterTests) {
        Character* test = new Character();
	test->setC('a');	
	test->setSize(6);
	test->setLocation(4, 8);
	test->setColor(55, 155, 255);

        EXPECT_EQ(test->getC(), 'a');
        EXPECT_EQ(test->getSize(), 6);
        EXPECT_EQ(test->getLocation().first, 4);
        EXPECT_EQ(test->getLocation().second, 8);
        EXPECT_EQ(get<0>(test->getColor()), 55);
        EXPECT_EQ(get<1>(test->getColor()), 155);
        EXPECT_EQ(get<2>(test->getColor()), 255);

        test->setLocation(-7, -20);
	EXPECT_EQ(test->getLocation().first, -7);
        EXPECT_EQ(test->getLocation().second, -20);
}

TEST(CharacterTest, GetChild) {
	Character* test1 = new Character();
	Character* test2 = new Character('a', 4, 5);

	EXPECT_EQ(test1->getChild(0), test1);
	EXPECT_EQ(test2->getChild(0), test2);
	EXPECT_EQ(test2->getChild(0)->getC(), test2->getC());
}

#endif


