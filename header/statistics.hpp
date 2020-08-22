#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <vector>
#include <string>
#include <tuple>

using namespace std;

enum Filter { difficulty, wpm, accuracy };

class Statistics {
	private:
		vector<tuple<int, int, int>> vars;
	public:
		Statistics();
		void readStats();
		void writeStats();
		void addStats(int difficulty, int wpm, int accuracy);
		vector<tuple<int, int, int>> getStats();
		vector<string> getStatsFormatted();
		void clearStats();
		void sort(Filter f);
};

#endif // STATISTICS_HPP
