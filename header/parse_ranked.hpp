#ifndef PARSE_RANKED_HPP
#define PARSE_RANKED_HPP

#include "parse.hpp"

// userRating is set during construction
// promptRating and prompt are set when parse() is called
// userScore is set when calculateScore() is called
// parse() and calculateScore() must be called before calling updateRating()

class ParseRanked : public Parse {
	private:
		double userRating, promptRating;
		vector<char> prompt;
		double userScore;
	public:
		ParseRanked(); //reads and sets userRating
		vector<char> parse(); //finds appropriate difficulty
		double calculateProbability(double userRating, double promptRating); // callculate chance of success (0 to 1)
		void calculateScore(int difficulty, int wpm, int accuracy);
		void updateRating()
		double getUserRating();
		double getPromptRating();
};

#endif
