#ifndef PARSE_RANDOM_TEST_HPP
#define PARSE_RANDOM_TEST_HPP

#include "../header/parse_random.hpp"
#include <iostream>

// Tests have passed in hammer
// Skipping all tests because GitHub Actions is unable to open prompt.txt correctly

TEST(ParseRandomTest, DifferentSeed) {
	GTEST_SKIP();
	ParseRandom* test = new ParseRandom();

	vector<char> par1 = test->parse(2);
	testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();

	vector<char> par2 = test->parse(3);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_NE(output1, output2);
}

TEST(ParseRandomTest, SameSeed) {
	GTEST_SKIP();
        ParseRandom* test = new ParseRandom();

        vector<char> par1 = test->parse(12);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par1.size(); i++) {
                cout << par1.at(i);
        }
        std::string output1 = testing::internal::GetCapturedStdout();

        vector<char> par2 = test->parse(12);
        testing::internal::CaptureStdout();
        for (int i = 0; i < par2.size(); i++) {
                cout << par2.at(i);
        }
        std::string output2 = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output1, output2);
}

#endif // PARSE_RANDOM_TEST_HPP
