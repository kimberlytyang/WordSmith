#ifndef CHAR_ITERATOR_TEST_HPP
#define CHAR_ITERATOR_TEST_HPP

#include "../header/char_iterator.hpp"
#include <iostream>

TEST(CharIteratorTest, OutOfBoundsPromptNegative) {
        CharIterator* test = new CharIterator();
        vector<char> par = test->loadPrompt(-10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");
}

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

TEST(CharIteratorTest, OutOfBoundsPromptSix) {
        CharIterator* test = new CharIterator();
        vector<char> par = test->loadPrompt(6);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "Gold and rose, the color of the dream I had not too long ago. A misty blue and the lilac, too, never to grow old. There you were under the tree of song, sleeping so peacefully. In your hand a flower played, awaiting there for me. I have never laid eyes on you, not before this timeless day, but you walked and you once smiled my name, and you stole my heart away.");
}

TEST(CharIteratorTest, InBoundsPrompts) {
        CharIterator* test = new CharIterator();
        vector<char> par1 = test->loadPrompt(1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output1, "You have the power to heal your life, and you need to know that.");

        vector<char> par2 = test->loadPrompt(2);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output2, "If you have to ask you will never know, if you know you need only ask.");

        vector<char> par3 = test->loadPrompt(3);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par3.size(); i++) {
                cout << par3.at(i);
        }
        std::string output3 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output3, "Your memory is the glue that binds your life together.");

        vector<char> par4 = test->loadPrompt(4);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par4.size(); i++) {
                cout << par4.at(i);
        }
        std::string output4 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output4, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");

        vector<char> par5 = test->loadPrompt(5);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par5.size(); i++) {
                cout << par5.at(i);
        }
        std::string output5 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output5, "Gold and rose, the color of the dream I had not too long ago. A misty blue and the lilac, too, never to grow old. There you were under the tree of song, sleeping so peacefully. In your hand a flower played, awaiting there for me. I have never laid eyes on you, not before this timeless day, but you walked and you once smiled my name, and you stole my heart away.");
}

#endif // CHAR_ITERATOR_TEST_HPP
