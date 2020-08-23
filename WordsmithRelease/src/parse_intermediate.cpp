#include "../header/parse_intermediate.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

vector<char> ParseIntermediate::parse(int i) {
	vector<char> prompt;

	ifstream inCount("res/prompt.txt");
	if (!inCount.is_open()) {
                cout << "Error opening prompt file to count lines." << endl;
                prompt.push_back('!');
                return prompt;
        }

	string hold = "";
	while (getline(inCount, hold)) {
		if (hold == "breakmedium") {
			break;
		}
	}

	int lineCount = 0;
	while (getline(inCount, hold)) {
		if (hold == "breakhard") {
			break;
		}
		lineCount++;
	}

	inCount.close();

	ifstream inFS("res/prompt.txt");
	if (!inFS.is_open()) {
		cout << "Error opening prompt file to extract." << endl;
		prompt.push_back('!');
		return prompt;
	}

	while (getline(inFS, hold)) {
                if (hold == "breakmedium") {
                        break;
                }
        }

	if (i < 1) {
		i = 1;
	} else if (i > lineCount) {
		i = lineCount;
	}

	string rawPrompt = "";
	int index = 0;
	while (index < i) {
		getline(inFS, rawPrompt);
		index++;
	}

	inFS.close();

	for (int i = 0; i < rawPrompt.size(); i++) {
		prompt.push_back(rawPrompt.at(i));
	}

	return prompt;
}
