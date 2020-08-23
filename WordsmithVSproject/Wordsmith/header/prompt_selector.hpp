#ifndef PROMPT_SELECTOR_HPP
#define PROMPT_SELECTOR_HPP

#include "parse.hpp"
#include <vector>

class PromptSelector {
        private:
                Parse* difficulty;
        public:
                PromptSelector();
                PromptSelector(Parse* difficulty);
                void setDifficulty(Parse* p);
                Parse* getDifficulty();
                std::vector<char> parsePrompt(int i);
};

#endif
