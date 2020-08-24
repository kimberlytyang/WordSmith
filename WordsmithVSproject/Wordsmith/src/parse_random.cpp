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

	string hold = "";
	while (getline(inFS, hold)) {
		words.push_back(hold);
	}

	inFS.close();

	srand(i);
	int index = 0;
	string addWord = "";
	int promptLength = (rand() % 15) + 16;

	for (unsigned i = 0; i < promptLength; ++i) {
		index = rand() % words.size();
		addWord = words.at(index);
		for (unsigned k = 0; k < addWord.size(); ++k) {
			prompt.push_back(addWord.at(k));
			std::cout << "pushback" << addWord.at(k) << std::endl;
		}
		if (i > 0 && (i % 6 == 0)) {
			prompt.push_back('/');
			std::cout <<"pushback" << '/' << std::endl;
			continue;
		}
		if (i < promptLength - 1) {
			prompt.push_back(' ');
			std::cout << "pushback" << ' ' << endl;
			
		}
	}
	
	return prompt;
}
