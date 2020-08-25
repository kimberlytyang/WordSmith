#include "../header/statistics.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <iostream>
#include <sstream>

void Statistics::readStats() {
	ifstream inFS("res/stats.txt");
        if (!inFS.is_open()) {
                cout << "Error opening stats.txt to read." << endl;
		return;
        }

        string statLine = "";
        string statVal = "";
        while (getline(inFS, statLine)) {
                tuple<int, int, int> entry(1, 1, 1);
                istringstream ss(statLine);

                ss >> statVal;
                get<0>(entry) = stoi(statVal);
                ss >> statVal;
                get<1>(entry) = stoi(statVal);
                ss >> statVal;
                get<2>(entry) = stoi(statVal);

                vars.push_back(entry);
        }

        inFS.close();
}

void Statistics::writeStats() {
	ofstream outFS("res/stats.txt");
        if (!outFS.is_open()) {
                cout << "Error opening stats.txt to populate." << endl;
		return;
        }

	unsigned i;
	std::cout << "45" << std::endl;
	for (i = 0; i < vars.size() - 1; ++i) {
		tuple<int, int, int> hold = vars.at(i);
		outFS << to_string(get<0>(hold)) << " " << to_string(get<1>(hold)) << " " << to_string(get<2>(hold)) << endl;
	}
	std::cout << "50" << std::endl;
	tuple<int, int, int> hold = vars.at(i);
	outFS << to_string(get<0>(hold)) << " " << to_string(get<1>(hold)) << " " << to_string(get<2>(hold)) << endl;
	std::cout << "53" << std::endl;
	outFS.close();
}

void Statistics::addStats(int difficulty, int wpm, int accuracy) {
	tuple<int, int, int> newEntry(difficulty, wpm, accuracy);
	vars.push_back(newEntry);
}

vector<tuple<int, int, int>> Statistics::getStats() {
	return vars;
}

vector<string> Statistics::getStatsFormatted() {
	vector<string> formatted;

	if (vars.size() == 0) {
		formatted.push_back("No stats to show.");
		return formatted;
	}

	string entry = "";
	string diff = "";
	for (unsigned i = 0; i < vars.size(); ++i) {
		if (get<0>(vars.at(i)) == 0) {
			diff = "Novice";
		} else if (get<0>(vars.at(i)) == 1) {
			diff = "Intermediate";
		} else if (get<0>(vars.at(i)) == 2) {
			diff = "Advanced";
		} else if(get<0>(vars.at(i)) == 3){
			diff = "Scrambled";
		} else if(get<0>(vars.at(i)) == 4){
			diff = "Campaign";
		} else {
			diff = "unknown";
		}

		entry = "Difficulty: " + diff + " -- WPM: " + to_string(get<1>(vars.at(i))) + " -- Accuracy: " + to_string(get<2>(vars.at(i))) + "%";
		formatted.push_back(entry);
	}

	return formatted;
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
