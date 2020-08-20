#ifndef PROMPTSELECTOR_TEST_HPP
#define PROMPTSELECTOR_TEST_HPP

#include "gtest/gtest.h"
#include "../header/promptselector.hpp"
#include "../header/parse_novice.hpp"
#include "../header/parse_intermediate.hpp"
#include "../header/parse_advanced.hpp"
#include <bits/stdc++.h> 

TEST(PromptSelectorTest, Constructors) {
	PromptSelector ps1;     
	EXPECT_EQ(ps1.getDifficulty(), nullptr);
	
	ParseNovice* p = new ParseNovice();
	PromptSelector ps2(p);
	EXPECT_EQ(ps2.getDifficulty(), p);
}

TEST(PromptSelectorTest, ParsePromptNovice) {
	PromptSelector test(new ParseNovice());
	
	std::vector<char> parsedPrompt = test.parsePrompt(3);
	testing::internal::CaptureStdout();
	for (int i = 0; i < parsedPrompt.size(); i++) {
		std::cout << parsedPrompt.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Your memory is the glue that binds your life together.");

	parsedPrompt = test.parsePrompt(-1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "You have the power to heal your life, and you need to know that.");

	parsedPrompt = test.parsePrompt(999);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "When we remember we only get a version of the last time we remember it.");
}

TEST(PromptSelectorTest, ParsePromptIntermediate) {
        PromptSelector test(new ParseIntermediate());

        std::vector<char> parsedPrompt = test.parsePrompt(3);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "I sit at my table and wage war on myself. It seems like it's all, it's all for nothing. I know the barricades and I know the mortar in the wall breaks. I recognize the weapons, I used them well. This is my mistake. Let me make it good. I raised the wall and I will be the one to knock it down.");

        parsedPrompt = test.parsePrompt(-1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Most of all I want to sleep. I want to sleep like I slept when I was a boy. Give me that. Just one time. That's why I won't allow that punk out there to get the best of me. Let alone the last of me.");

        parsedPrompt = test.parsePrompt(999);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "It is not difficult to wield a sword in one hand; the way to learn this is to train with two long swords, one in each hand. It will seem difficult at first, but everything is difficult at first.");
}

TEST(PromptSelectorTest, ParsePromptAdvanced) {
        PromptSelector test(new ParseAdvanced());

        std::vector<char> parsedPrompt = test.parsePrompt(6);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Really knowing is good. Not knowing, or refusing to know, is bad, or amoral, at least. You can't act if you don't know. Acting without knowing takes you right off the cliff.");

        parsedPrompt = test.parsePrompt(-1);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "I just finished this fascinating book. By the year 2030, there will be computers that can carry out the same amount of functions as an actual human brain. So theoretically, you could download your thoughts and memories into this computer and live forever as a machine!");

        parsedPrompt = test.parsePrompt(999);
        testing::internal::CaptureStdout();
        for (int i = 0; i < parsedPrompt.size(); i++) {
                std::cout << parsedPrompt.at(i);
        }
        output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "The number nine is not ten. The number eleven is not ten. Although the two numbers are almost ten, they can never be ten. They are untenable. You can add one to nine to make it ten, but it would no longer be nine! It would be ten! Same with eleven! When nine is nine and eleven is eleven, they are untenable! Their possessions are untenable! They have to go.");
}



#endif
