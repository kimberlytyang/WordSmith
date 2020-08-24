#include "../header/parse_ranked.hpp"

#include <string>
#include <fstream>
#include <iostream>

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

	userRating = stoi(data);	
}

vector<char> ParseRanked::parse() {}

double ParseRanked::calculateProbability(double userRating, double promptRating) {}

void ParseRanked::calculateScore(int difficulty, int wpm, int accuracy) {}

void ParseRanked::updateRating() {}

double ParseRanked::getUserRating() { return userRating; }

double ParseRanked::getPromptRating() { return promptRating; }
