#ifndef PROMPTSELECTOR_TEST_HPP
#define PROMPTSELECTOR_TEST_HPP

#include "gtest/gtest.h"
#include "../header/promptselector.hpp"
#include "../header/parse_novice.hpp"

TEST(PromptSelectorTest, Constructors) {
	PromptSelector ps1;     
	EXPECT_EQ(ps1.getDifficulty, nullptr);
	
	ParseNovice* p = new ParseNovice();
	PromptSelector ps2(p);
	EXPECT_EQ(ps2.getDifficulty, p)
}

#endif
