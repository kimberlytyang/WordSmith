#include "../header/promptselector.hpp"

PromptSelector::PromptSelector() {
	difficulty = nullptr;
}

PromptSelector::PromptSelector(Parse* difficulty) {
        this->difficulty = difficulty;
}

std::vector<char> PromptSelector::parsePrompt(int i) {
        return difficulty->parse(i);
}

void PromptSelector::setDifficulty(Parse* p) {
        difficulty = p;
}

Parse* PromptSelector::getDifficulty() {
        return difficulty;
}
