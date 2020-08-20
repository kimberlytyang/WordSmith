#ifndef PARSE_INTERMEDIATE_TEST_HPP
#define PARSE_INTERMEDIATE_TEST_HPP

#include "../header/parse_intermediate.hpp"
#include <iostream>

TEST(ParseIntermediateTest, OutOfBoundsPromptNegative) {
        ParseIntermediate* test = new ParseIntermediate();
        
        vector<char> par = test->parse(-10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");
}

TEST(ParseIntermediateTest, OutOfBoundsPromptZero) {
        ParseIntermediate* test = new ParseIntermediate();

	vector<char> par = test->parse(0);
	testing::internal::CaptureStdout();
	for (int i = 0; i < par.size(); i++) {
		cout << par.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");
}

TEST(ParseIntermediateTest, OutOfBoundsPromptEleven) {
        ParseIntermediate* test = new ParseIntermediate();

        vector<char> par = test->parse(11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "It is not difficult to wield a sword in one hand; the way to learn this is to train with two long swords, one in each hand. It will seem difficult at first, but everything is difficult at first.");
}

TEST(ParseIntermediateTest, InBoundsPrompts) {
        ParseIntermediate* test = new ParseIntermediate();

        vector<char> par1 = test->parse(1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output1, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");

        vector<char> par2 = test->parse(2);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output2, "It's a human sign when things go wrong, when the scent of her lingers and temptation's strong. Into the boundary of each married man, sweet deceit comes calling and negativity lands.");

        vector<char> par3 = test->parse(5);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par3.size(); i++) {
                cout << par3.at(i);
        }
        std::string output3 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output3, "Gold and rose, the color of the dream I had not too long ago. A misty blue and the lilac, too, never to grow old. There you were under the tree of song, sleeping so peacefully. In your hand a flower played, awaiting there for me. I have never laid eyes on you, not before this timeless day, but you walked and you once smiled my name, and you stole my heart away.");

        vector<char> par4 = test->parse(8);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par4.size(); i++) {
                cout << par4.at(i);
        }
        std::string output4 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output4, "It wasn't always so clear, but the Rust programming language is fundamentally about empowerment: no matter what kind of code you are writing now, Rust empowers you to reach farther, to program with confidence in a wider variety of domains than you did before.");

        vector<char> par5 = test->parse(10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par5.size(); i++) {
                cout << par5.at(i);
        }
        std::string output5 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output5, "It is not difficult to wield a sword in one hand; the way to learn this is to train with two long swords, one in each hand. It will seem difficult at first, but everything is difficult at first.");
}

#endif // PARSE_INTERMEDIATE_TEST_HPP
