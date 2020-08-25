#include "../header/parse_ranked.hpp"
#include "../header/parse_novice.hpp"
#include "../header/parse_intermediate.hpp"
#include "../header/parse_advanced.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

ParseRanked::ParseRanked() {
	ifstream inFS("res/user_cache.txt");
	if (!inFS.is_open()) {
		cout << "Error opening user cache file to extract." << endl;
		prompt.push_back('!');
		return;
	}

	string data = "";
	for (int i = 0; i < 2; i++) {
		getline(inFS, data);	
	}

	inFS.close();
	
	if (data == "") {
		data == "1.00";
	}

	userRating = stod(data);	
}

vector<char> ParseRanked::parse(int i) {
	if (userRating < 1.50) {
		ParseNovice* diff = new ParseNovice();
		return diff->parse(i);
	} else if (userRating < 2.50) {
		ParseIntermediate* diff = new ParseIntermediate();
		return diff->parse(i);
	} else {
		ParseAdvanced* diff = new ParseAdvanced();
		return diff->parse(i);
	}		
}

double ParseRanked::calculateProbability(double userRating, double promptRating) {
	return 1.0 / (1.0 + pow(10, (userRating - promptRating) / 400));
}

void ParseRanked::calculateScore(int wpm, int accuracy) {
	userScore = ((wpm/70.0)*(.25)) + ((accuracy/100.0)*(.35));	
}

void ParseRanked::updateRating() {}

double ParseRanked::getUserRating() { return userRating; }

double ParseRanked::getPromptRating() { return promptRating; }

double ParseRanked::getUserScore() { return userScore; }
