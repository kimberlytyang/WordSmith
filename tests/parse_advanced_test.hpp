#ifndef PARSE_ADVANCED_TEST_HPP
#define PARSE_ADVANCED_TEST_HPP

#include "../header/parse_advanced.hpp"
#include <iostream>

// Tests have passed in hammer
// Skipping all tests because GitHub Actions is unable to open prompt.txt correctly

TEST(ParseAdvancedTest, OutOfBoundsPromptNegative) {
	GTEST_SKIP();
        ParseAdvanced* test = new ParseAdvanced();
        
        vector<char> par = test->parse(-10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "I just finished this fascinating book. By the year 2030, there will be computers that can carry out the same amount of functions as an actual human brain. So theoretically, you could download your thoughts and memories into this computer and live forever as a machine!");
}

TEST(ParseAdvancedTest, OutOfBoundsPromptZero) {
	GTEST_SKIP();
        ParseAdvanced* test = new ParseAdvanced();

	vector<char> par = test->parse(0);
	testing::internal::CaptureStdout();
	for (int i = 0; i < par.size(); i++) {
		cout << par.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "I just finished this fascinating book. By the year 2030, there will be computers that can carry out the same amount of functions as an actual human brain. So theoretically, you could download your thoughts and memories into this computer and live forever as a machine!");
}

TEST(ParseAdvancedTest, OutOfBoundsPromptEleven) {
	GTEST_SKIP();
        ParseAdvanced* test = new ParseAdvanced();

        vector<char> par = test->parse(11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "The number nine is not ten. The number eleven is not ten. Although the two numbers are almost ten, they can never be ten. They are untenable. You can add one to nine to make it ten, but it would no longer be nine! It would be ten! Same with eleven! When nine is nine and eleven is eleven, they are untenable! Their possessions are untenable! They have to go.");
}

TEST(ParseAdvancedTest, InBoundsPrompts) {
	GTEST_SKIP();
        ParseAdvanced* test = new ParseAdvanced();

        vector<char> par1 = test->parse(1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output1, "I just finished this fascinating book. By the year 2030, there will be computers that can carry out the same amount of functions as an actual human brain. So theoretically, you could download your thoughts and memories into this computer and live forever as a machine!");

        vector<char> par2 = test->parse(2);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output2, "If I can't find the cure, I'll fix you with my love. No matter what you know, I'll fix you with my love. And if you say you're okay, I'm gonna heal you anyway. Promise I'll always be there, promise I'll be the cure.");

        vector<char> par3 = test->parse(5);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par3.size(); i++) {
                cout << par3.at(i);
        }
        std::string output3 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output3, "Very often research which has deeply interested me while I was investigating it loses its interest for me just after I have the solution, unhappily at a time which coincides with the period when I have to record it. After a while, say a couple of months, I come to a more just appreciation of it.");

        vector<char> par4 = test->parse(8);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par4.size(); i++) {
                cout << par4.at(i);
        }
        std::string output4 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output4, "Are you sure? Fine! Well, you go and have a really good night's sleep then, I'm hoping to get a couple hours later on myself but I'll be up in good time to serve you your breakfast in bed. If you can remember to sleep with your mouth open you won't even have to wake up, I'll just drop in small pieces of lightly buttered kipper when you're breathing in the right direction if that doesn't put you out!");

        vector<char> par5 = test->parse(10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par5.size(); i++) {
                cout << par5.at(i);
        }
        std::string output5 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output5, "The number nine is not ten. The number eleven is not ten. Although the two numbers are almost ten, they can never be ten. They are untenable. You can add one to nine to make it ten, but it would no longer be nine! It would be ten! Same with eleven! When nine is nine and eleven is eleven, they are untenable! Their possessions are untenable! They have to go.");
}

#endif // PARSE_ADVANCED_TEST_HPP
