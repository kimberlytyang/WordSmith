#include "../header/statistics.hpp"

#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <iostream>

Statistics::Statistics() {
	ifstream inFS("res/stats.txt");
	if (!inFS.is_open()) {
		cout << "Error opening stats.txt to extract." << endl;
	}

	

	inFS.close();
}

void Statistics::readStats() {

}

void Statistics::writeStats() {

}

void Statistics::addStats(int difficulty, int wpm, int accuracy) {

}

vector<tuple<int, int, int>> Statistics::getStats() {

}

vector<string> Statistics::getStatsFormatted() {

}

void Statistics::clearStats() {
	ofstream outFS;
	outFS.open("res/stats.txt", ofstream::out | ofstream::trunc);
	outFS.close();
}

void Statistics::sort(Filter f) {

}
