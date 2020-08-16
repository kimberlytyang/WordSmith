#ifndef WINDOW_TEST
#define WINDOW_TEST

#include "../header/window.hpp"
#include "../header/line.hpp"
#include "../header/rectangle.hpp"
#include "../header/character.hpp"


TEST(WindowTest, DefaultConstructor) {
	Window* test = new Window();
	
	EXPECT_EQ(test->getTL().first, 0);
	EXPECT_EQ(test->getTL().second, 0);
	EXPECT_EQ(test->getBR().first, 0);
	EXPECT_EQ(test->getBR().second, 0);
}

TEST(WindowTest, CornersConstructor) {
        Window* test = new Window(10, 30, 250, 270);

        EXPECT_EQ(test->getTL().first, 10);
        EXPECT_EQ(test->getTL().second, 30);
        EXPECT_EQ(test->getBR().first, 250);
        EXPECT_EQ(test->getBR().second, 270);
}

TEST(WindowTest, InsertionRemoval) {
	Window* test = new Window();
	Line* line1 = new Line();
	Line* line2 = new Line();
	Rectangle* rectangle = new Rectangle();
	Character* character = new Character();
	
	test->insert(line1);
	test->insert(line2);
	test->insert(line1);
	test->insert(rectangle);
	test->insert(character);
	ASSERT_EQ(test->getGraphics().size(), 5);
	EXPECT_EQ(test->getChild(0), line1);
	EXPECT_EQ(test->getChild(1), line2);
	EXPECT_EQ(test->getChild(2), line1);
	EXPECT_EQ(test->getChild(3), rectangle);
	EXPECT_EQ(test->getChild(4), character);

	test->remove(line1);
	test->remove(rectangle);
	ASSERT_EQ(test->getGraphics().size(), 3);
        EXPECT_EQ(test->getChild(0), line2);
        EXPECT_EQ(test->getChild(1), line1);
	EXPECT_EQ(test->getChild(2), character);
}

TEST(WindowTest, Mutators) {
	Window* test = new Window();
	
	test->setTL(10, 25);
	test->setBR(300, 335);
	EXPECT_EQ(test->getTL().first, 10);
        EXPECT_EQ(test->getTL().second, 25);
        EXPECT_EQ(test->getBR().first, 300);
        EXPECT_EQ(test->getBR().second, 335);
}

#endif
