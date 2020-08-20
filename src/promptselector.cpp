#include "../header/promptselector.hpp"

PromptSelector::PromptSelector(Parse* difficulty) {
        this->difficulty = difficulty;
}

vector<char> PromptSelector::findParse(int i) {
        difficulty->parse(i);
}

void PromptSelector::setDifficulty(Parse* p) {
        difficulty = p;
}

Parse* PromptSelector::getDifficulty() [
        return difficulty;
}
