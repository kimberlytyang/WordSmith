#ifndef WINDOW_TEST
#define WINDOW_TEST

#include "../header/window.hpp"

TEST(WindowTest, DefaultConstructor) {
	Window* test = new Window();
	
	EXPECT_EQ(test->getTL().first, 0);
	EXPECT_EQ(test->getTL().second, 0);
	EXPECT_EQ(test->getBR().first, 0);
	EXPECT_EQ(test->getBR().second, 0);

}

#endif
