#include "../header/parse_campaign.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

vector<char> ParseCampaign::parse(int i) {
	ifstream inFile("res/user_cache.txt");
        if (!inFile.is_open()) {
                cout << "Error opening user_cache.txt file to check progress." << endl;
		prompt.push_back('!');
                return prompt;
        }
	string campaign = "";
	string rank = "";
	getline(inFile, campaign);
	getline(inFile, rank);
	inFile.close();
	int campaignVal = stoi(campaign);

	vector<char> prompt;

	ifstream inCount("res/prompt.txt");
	if (!inCount.is_open()) {
                cout << "Error opening prompt.txt to count number of prompts." << endl;
                prompt.push_back('!');
                return prompt;
        }

	int promptCount = 0;
	string hold = "";
	while (getline(inCount, hold)) {
		if (hold == "breakmedium" || hold == "breakhard") {
			continue;
		}
		promptCount++;
	}
	inCount.close();

	if (campaignVal < 1) {
		campaignVal = 1;
		ofstream outOverride("res/user_cache.txt");
		if (!outOverride.is_open()) {
			cout << "Error opening user_cache.txt to set campaignVal in bounds." << endl;
			prompt.push_back('!');
			return prompt;
		}
		outOverride << "1" << endl << rank;
		outOverride.close();
	} else if (campaignVal > promptCount) {
		cout << "Campaign has been completed." << endl;
		prompt.push_back(' ');
		return prompt;
	}

	ifstream inFS("res/prompt.txt");
	if (!inFS.is_open()) {
		cout << "Error opening prompt.txt to extract." << endl;
		prompt.push_back('!');
		return prompt;
	}

	string rawPrompt = "";
	int index = 0;
	while (index < campaignVal) {
		getline (inFS, rawPrompt);
		if (rawPrompt == "breakmedium" || rawPrompt == "breakhard") {
			continue;
		}
		index++;
	}
	inFS.close();

	for (int i = 0; i < rawPrompt.size(); ++i) {
		prompt.push_back(rawPrompt.at(i));
	}

	return prompt;
}

void ParseCampaign::incrementProgress() {
	ifstream inFS("res/user_cache.txt");
	if (!inFS.is_open()) {
                cout << "Error opening user_cache.txt file to update campaign." << endl;
                return;
        }
	string campaign = "";
	string rank = "";
	getline(inFS, campaign);
	getline(inFS, rank);
	inFS.close();

	int campaignVal = stoi(campaign) + 1;
	ofstream outFS("res/user_cache.txt");
        if (!outFS.is_open()) {
		cout << "Error opening user_cache.txt file to update campaign." << endl;
                return;
	}
	outFS << to_string(campaignVal) << endl << rank;
	outFS.close();
}

void ParseCampaign::resetCampaign() {
	ifstream inFS("res/user_cache.txt");
        if (!inFS.is_open()) {
                cout << "Error opening user_cache.txt file reset campaign." << endl;
                return;
        }
	string rank = "";
	getline(inFS, rank);
	getline(inFS, rank);
	inFS.close();

	ofstream outFS("res/user_cache.txt");
	if (!outFS.is_open()) {
                cout << "Error opening user_cache.txt to reset campaign." << endl;
		return;
        }
	outFS << "1" << endl << rank;
	outFS.close();
}
