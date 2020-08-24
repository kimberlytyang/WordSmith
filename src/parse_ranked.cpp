#include "../header/parse_ranked.hpp"

#include <string>
#include <fstream>
#include <iostream>

ParseNovice::ParseNovice() {
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

	userRating = atoi(data);	
}

vector<char> ParseNovice::parse(int i) {}
