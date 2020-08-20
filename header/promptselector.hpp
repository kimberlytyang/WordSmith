#ifndef PROMPT_SELECTOR_HPP
#define PROMPT_SELECTOR_HPP

#include "parse.hpp"

class PromptSelector {
        private:
                Parse* difficulty;
        public:
                PromptSelector() {};
                PromptSelector(Parse* difficulty);
                void setDifficulty(Parse* p);
                Parse* getDifficulty();
                vector<char> findDifficulty(int i);
};

#endif
