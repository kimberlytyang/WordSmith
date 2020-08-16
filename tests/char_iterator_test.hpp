#ifndef CHAR_ITERATOR_TEST_HPP
#define CHAR_ITERATOR_TEST_HPP

#include "../header/char_iterator.hpp"
#include <iostream>

TEST(CharIteratorTest, OutOfBoundsPromptZero) {
	CharIterator* test = new CharIterator();
	vector<char> par = test->loadPrompt(0);
	testing::internal::CaptureStdout();
	for (int i = 0; i < par.size(); i++) {
		cout << par.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");
}

#endif // CHAR_ITERATOR_TEST_HPP
