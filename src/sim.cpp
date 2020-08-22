#include "../header/graphic.hpp"
#include "../header/character.hpp"
#include "../header/line.hpp"
#include "../header/rectangle.hpp"
#include "../header/window.hpp"

#include <iostream>
#include <string>
#include <ctime>

//SIMPLE CONSOLE PROGRAM TYPE TEST
//MUST BE RUN IN VSCODE OR OTHER IDE THAT SUPPORTS CTIME

int main(){
    
    std::string prompt = "the fitness gram pacer test is a multi stage test";
    std::cout << "Type the following fast: " << std::endl;
    std::cout << prompt << std::endl;
    int t = time(NULL);
    std::string ans = "";
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
    std::cout << "ACCURACY: " <<( correct / prompt.size() )*100<< std::endl;
    double temp = t * 1.0;
    std::cout << "WPM: " << (prompt.size()/5.5)/((temp)/60.0) << std::endl;
}
