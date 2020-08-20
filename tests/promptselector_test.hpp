#ifndef PROMPTSELECTOR_TEST_HPP
#define PROMPTSELECTOR_TEST_HPP

#include "gtest/gtest.h"
#include "../header/promptselector.hpp"
#include "../header/parse_novice.hpp"
#include <bits/stdc++.h> 

TEST(PromptSelectorTest, Constructors) {
	PromptSelector ps1;     
	EXPECT_EQ(ps1.getDifficulty(), nullptr);
	
	ParseNovice* p = new ParseNovice();
	PromptSelector ps2(p);
	EXPECT_EQ(ps2.getDifficulty(), p);
}

TEST(PromptSelectorTest, ParsePrompt) {
	PromptSelector test(new ParseNovice());
	std::vector<char> parsedPrompt = test.parsePrompt(3);

	testing::internal::CaptureStdout();
	for (int i = 0; i < parsedPrompt.size(); i++) {
		std::cout << parsedPrompt.at(i);
	}
	std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "Your memory is the glue that binds your life together.");
}

#endif
