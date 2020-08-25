#ifndef PARSE_RANKED_TEST_HPP
#define PARSE_RANKED_TEST_HPP

#include "../header/parse_ranked.hpp"
#include <iostream>

TEST(ParseRankedTest, DefaultConstructor) {
	ParseRanked* test = new ParseRanked();
	EXPECT_EQ(test->getUserRating(), 1.0);
}

#endif
