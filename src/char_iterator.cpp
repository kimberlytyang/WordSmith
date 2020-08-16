#include "../header/char_iterator.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

vector<char> CharIterator::loadPrompt(int num) {
	vector<char> prompt;
	std::ifstream inFS("../res/prompt.txt", std::ifstream::in);
	if (!inFS.is_open()) {
		cout << "Error opening prompt file." << endl;
		prompt.push_back('!');
		return prompt;
	}

	if (num < 1) {
		num = 1;
	}

	string rawPrompt = "";
	int index = 0;
	while (getline(inFS, rawPrompt)) {
		index++;
		if (index == num) {
			break;
		}
	}

	for (int i = 0; i < rawPrompt.size(); i++) {
		prompt.push_back(rawPrompt.at(i));
	}

	return prompt;
}
