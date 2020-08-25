#include "../header/parse_ranked.hpp"
#include "../header/parse_novice.hpp"
#include "../header/parse_intermediate.hpp"
#include "../header/parse_advanced.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

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
	if (userRating < .75) {
		ParseNovice* diff = new ParseNovice();
		prompt = diff->parse(i);
	} else if (userRating < 1.75) {
		ParseIntermediate* diff = new ParseIntermediate();
		prompt = diff->parse(i);
	} else {
		ParseAdvanced* diff = new ParseAdvanced();
		prompt = diff->parse(i);
	}
	calculatePromptRating(prompt);
	return prompt;	
}

double ParseRanked::calculateProbability(double userRating, double promptRating) {
	return 1.0 / (1.0 + pow(10, (userRating - promptRating) / 400));
}

void ParseRanked::calculateScore(int wpm, int accuracy) {
	userScore = ((wpm/70.0)*(.25)) + ((accuracy/100.0)*(.35));	
}

void ParseRanked::updateRating() {
	userRating = userRating + (userScore - calculateProbability(userRating, promptRating));

	ifstream inFS("res/user_cache.txt");
	if (!inFS.is_open()) {
                cout << "Error opening user_cache.txt file to update campaign." << endl;
                return;
        }
	string campaign = "";
	getline(inFS, campaign);
	inFS.close();
	
	if (campaign == "") {
                campaign = "0";
        }

	ofstream outFS("res/user_cache.txt");
        if (!outFS.is_open()) {
		cout << "Error opening user_cache.txt file to update campaign." << endl;
                return;
	}
	outFS << campaign << endl << to_string(userRating);
	outFS.close();
}

double ParseRanked::getUserRating() { return userRating; }

double ParseRanked::getPromptRating() { return promptRating; }

double ParseRanked::getUserScore() { return userScore; }

void ParseRanked::calculatePromptRating(vector<char> v) {
	if (v.size() == 0)
		promptRating = 0;

	int wordCount = getWordCount(v);
	double weight;
	if (userRating < .75) {
		weight = wordCount/12.0;
	} else if (userRating < 1.75) {
		weight = wordCount/42.0;
	} else {
		weight = wordCount/46.0;
	} 
	promptRating = weight * userRating;
}

int ParseRanked::getWordCount(vector<char> v) {
	if (v.empty())
		return 0.0;
	
	int count = 1;
	for (int i = 1; i < v.size(); ++i) {
		if (v.at(i) == ' ') {	
			count++;
		}
	}	
	return count;
}


