#ifndef PARSE_HPP
#define PARSE_HPP

#include <vector>

using namespace std;

class Parse {
	public:
		virtual vector<char> parse(int i) = 0;
};

#endif // PARSE_HPP
