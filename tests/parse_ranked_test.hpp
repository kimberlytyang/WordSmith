#ifndef PARSE_RANKED_TEST_HPP
#define PARSE_RANKED_TEST_HPP

#include "../header/parse_ranked.hpp"
#include <iostream>
#include <fstream>

TEST(ParseRankedTest, DefaultConstructor) {
	ofstream outFS("res/user_cache.txt");
	if (!outFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }
        outFS << endl << "1.25";
	outFS.close();
	
	ParseRanked* test = new ParseRanked();
	EXPECT_EQ(test->getUserRating(), 1.25);
}

TEST(ParseRankedTest, ParseNoviceRank) {
	ofstream outFS("res/user_cache.txt");
        if (!outFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }
	outFS << endl << "1.00";
	outFS.close();	

	ParseRanked* test = new ParseRanked();
	vector<char> prompt = test->parse(2);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "If you have to ask you will never know, if you know you need only ask.");
	
	prompt = test->parse(-11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");
	
	prompt = test->parse(10);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "When we remember we only get a version of the last time we remember it.");
}

TEST(ParseRankedTest, ParseIntermediateRank) {
        ofstream outFS("res/user_cache.txt");
        if (!outFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }
        outFS << endl << "2.00";
	outFS.close();

        ParseRanked* test = new ParseRanked();
        vector<char> prompt = test->parse(3);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "I sit at my table and wage war on myself. It seems like it's all, it's all for nothing. I know the barricades and I know the mortar in the wall breaks. I recognize the weapons, I used them well. This is my mistake. Let me make it good. I raised the wall and I will be the one to knock it down.");

        prompt = test->parse(-11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");

	prompt = test->parse(11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
	
        EXPECT_EQ(output, "It is not difficult to wield a sword in one hand; the way to learn this is to train with two long swords, one in each hand. It will seem difficult at first, but everything is difficult at first.");
}

TEST(ParseRankedTest, ParseAdvancedRank) {
        ofstream outFS("res/user_cache.txt");
        if (!outFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }
        outFS << endl << "3.00";
	outFS.close();

        ParseRanked* test = new ParseRanked();
        vector<char> prompt = test->parse(4);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "Well, isn't this great, we've all learned something. Tony can't choose who his sister's gonna fall for, Monica can't choose who she's gonna fall for, and I think that I've learned the greatest lesson of all. I love being lifted.");

        prompt = test->parse(-11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "I just finished this fascinating book. By the year 2030, there will be computers that can carry out the same amount of functions as an actual human brain. So theoretically, you could download your thoughts and memories into this computer and live forever as a machine!");
	
	prompt = test->parse(11);
        testing::internal::CaptureStdout();
        for (int i = 0; i < prompt.size(); i++) {
                cout << prompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "The number nine is not ten. The number eleven is not ten. Although the two numbers are almost ten, they can never be ten. They are untenable. You can add one to nine to make it ten, but it would no longer be nine! It would be ten! Same with eleven! When nine is nine and eleven is eleven, they are untenable! Their possessions are untenable! They have to go.");
	
}


#endif
