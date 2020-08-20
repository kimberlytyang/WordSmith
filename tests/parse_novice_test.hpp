#ifndef PARSE_NOVICE_TEST_HPP
#define PARSE_NOVICE_TEST_HPP

#include "../header/parse_novice.hpp"
#include <iostream>

TEST(ParseNoviceTest, OutOfBoundsPromptNegative) {
        ParseNovice* test = new ParseNovice();
        
        vector<char> par = test->parse(-10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");
}

TEST(ParseNoviceTest, OutOfBoundsPromptZero) {
        ParseNovice* test = new ParseNovice();

	vector<char> par = test->parse(0);
	testing::internal::CaptureStdout();
	for (int i = 0; i < par.size(); i++) {
		cout << par.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");
}

TEST(ParseNoviceTest, OutOfBoundsPromptEleven) {
        ParseNovice* test = new ParseNovice();

        vector<char> par = test->parse(11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par.size(); i++) {
                cout << par.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "When we remember we only get a version of the last time we remember it.");
}

TEST(ParseNoviceTest, InBoundsPrompts) {
        ParseNovice* test = new ParseNovice();

        vector<char> par1 = test->parse(1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output1, "You have the power to heal your life, and you need to know that.");

        vector<char> par2 = test->parse(2);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output2, "If you have to ask you will never know, if you know you need only ask.");

        vector<char> par3 = test->parse(5);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par3.size(); i++) {
                cout << par3.at(i);
        }
        std::string output3 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output3, "You can't use the fire exit because you're not made of fire.");

        vector<char> par4 = test->parse(8);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par4.size(); i++) {
                cout << par4.at(i);
        }
        std::string output4 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output4, "It's easy not to abuse your power when you don't actually have any power.");

        vector<char> par5 = test->parse(10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par5.size(); i++) {
                cout << par5.at(i);
        }
        std::string output5 = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output5, "When we remember we only get a version of the last time we remember it.");
}

#endif // PARSE_NOVICE_TEST_HPP
