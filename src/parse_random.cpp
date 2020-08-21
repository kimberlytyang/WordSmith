#include "../header/parse_random.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

vector<char> ParseRandom::parse(int i) {
	vector<char> prompt;
	vector <string> words;

	ifstream inFS("res/random.txt");
	if (!inFS.is_open()) {
                cout << "Error opening random.txt file to extract words." << endl;
                prompt.push_back('!');
                return prompt;
        }

	int wordCount = 0;
	string hold = "";
	while (getline(inFS, hold)) {
		wordCount++;
		words.push_back(hold);
	}

	inFS.close();

	srand(i);
	int index = 0;
	string addWord = "";
	int promptLength = 30;

	for (unsigned i = 0; i < promptLength; ++i) {
		index = (rand() % 300);
		addWord = words.at(index);
		for (unsigned k = 0; k < addWord.size(); ++k) {
			prompt.push_back(addWord.at(k));
		}
		if (i < promptLength - 1) {
			prompt.push_back(' ');
		}
	}

	return prompt;
}
