#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <vector>
#include <string>

using namespace std;

class Statistics {
	private:
		vector<string> stats;
	public:
		Statistics();
		void addStats(string difficulty, int wpm, int accuracy);
		vector<string> getStats();
};

#endif // STATISTICS_HPP
