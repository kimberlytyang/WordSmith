#include "../header/parse_advanced.hpp"
#include "../header/parse_intermediate.hpp"
#include "../header/parse_novice.hpp"
#include "../header/parse_random.hpp"
#include "../header/prompt_selector.hpp"
#include "../header/statistics.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//SIMPLE CONSOLE PROGRAM TYPE TEST
//MUST BE RUN IN VSCODE OR OTHER IDE THAT SUPPORTS CTIME
//COMPILE COMMAND:  g++ -std=c++11 src/*.cpp -o sim
int main(){
    std::cout << "Select a type of prompt: " << std::endl;
    std::cout << "[1] Novice " << std::endl;
    std::cout << "[2] Intermediate " << std::endl;
    std::cout << "[3] Advanced " << std::endl;
    std::cout << "[4] Random " << std::endl;

    int choice = 0;
    std::cin >> choice;
    choice--;
    PromptSelector* p = new PromptSelector();
    if(choice == 0){
     p->setDifficulty(new ParseNovice());
    }else if(choice == 1){
     p->setDifficulty(new ParseIntermediate());
    }else if(choice == 2){
     p->setDifficulty(new ParseAdvanced());
    }else if(choice == 3){
     p->setDifficulty(new ParseRandom());
    } else {
     p->setDifficulty(new ParseNovice());
    }

    std::cout << "Type the following fast: " << std::endl;
    srand(time(NULL));
    std::vector<char> prompt = p->parsePrompt(std::rand() % 10 + 1);
    for(unsigned i = 0; i < prompt.size(); i++){
	std::cout << prompt.at(i);
    }
    std::cout << std::endl;
    int t = time(NULL);
    std::string ans = "";
    cin.ignore();
    getline(std::cin, ans);
    t = time(NULL) - t;

    std::cout << "TIME: " << t << " seconds" << std::endl;
    double correct = 0;
    int size = 0;
    if(prompt.size()>ans.size()){
        size = ans.size();
        correct = correct - (prompt.size()-ans.size());
    } else {
        size = prompt.size();
        correct = correct - (ans.size() - prompt.size());
    }
    for(int i = 0; i < size; ++i){
        if(ans.at(i) == prompt.at(i)){
            ++correct;
        } 
    }
    int accuracy = (correct / prompt.size())*100;
    std::cout << "ACCURACY: " << accuracy << std::endl;
    double temp = t * 1.0;
    int WPM = (prompt.size()/5.5)/((temp)/60.0);
    std::cout << "WPM: " << WPM  << std::endl;
    Statistics* s = new Statistics();
    if(WPM < 0 || accuracy > 100 || accuracy < 0){
	return;
    }
    s->readStats();
    s->addStats(choice, WPM, accuracy); 
    s->writeStats();
}
