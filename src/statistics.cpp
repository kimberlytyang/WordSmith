#include "../header/statistics.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

Statistics::Statistics() {
	ifstream inFS("res/stats.txt");
	if (!inFS.is_open()) {
		cout << "Error opening stats.txt to extract." << endl;
	}

	string hold = "";
	while (getline(inFS, hold)) {
		stats.push_back(hold);
	}

	inFS.close();
}

void Statistics::addStats(string difficulty, int wpm, int accuracy) {
	string entry = "Difficulty: " + difficulty + " -- WPM: " + wpm + " -- Accuracy: " + accuracy;
	stats.push_back(entry);

	ofstream outFS("res/stats.txt");
	if (!outFS.is_open()) {
		cout << "Error opening stats.txt to populate." << endl;
	}

	unsigned i;
	for (i = 0; i < stats.size() - 1; ++i) {
		outFS << stats.at(i) << endl;
	}
	outFS << stats.at(i);
}

vector<string> getStats() {
	return stats;
}
