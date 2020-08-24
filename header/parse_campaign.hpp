#ifndef PARSE_CAMPAIGN_HPP
#define PARSE_CAMPAIGN_HPP

#include "parse.hpp"

class ParseCampaign : public Parse {
	public:
		vector<char> parse(int i);
		void incrementProgress();
};

#endif // PARSE_CAMPAIGN_HPP
