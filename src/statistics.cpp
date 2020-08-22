#include "../header/statistics.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <iostream>

Statistics::Statistics() {
}

void Statistics::readStats() {

}

void Statistics::writeStats() {

}

void Statistics::addStats(int difficulty, int wpm, int accuracy) {
	tuple<int, int, int> newEntry(difficulty, wpm, accuracy);
	vars.push_back(newEntry);
}

vector<tuple<int, int, int>> Statistics::getStats() {
	return vars;
}

vector<string> Statistics::getStatsFormatted() {

}

void Statistics::clearStats() {
	ofstream outFS;
	outFS.open("res/stats.txt", ofstream::out | ofstream::trunc);
	outFS.close();
}

void Statistics::sort(Filter f) {
	int statsCurr[3];
	int statsNext[3];
	for (int i = 0; i < vars.size()-1; i++) {
		for (int j = 0; j < vars.size()-i-1; j++) {
			std::tie(statsCurr[0], statsCurr[1], statsCurr[2]) = vars.at(j);
			std::tie(statsNext[0], statsNext[1], statsNext[2]) = vars.at(j+1);
			if (statsCurr[f] > statsNext[f])
				std::iter_swap(vars.begin()+j, vars.begin()+j+1);				
		}
	}
}
