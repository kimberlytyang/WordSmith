#ifndef STATISTICS_TEST_HPP
#define STATISTICS_TEST_HPP

#include "../header/statistics.hpp"
#include <iostream>
#include <fstream>

TEST(StatisticsTest, EmptyFileTest) {
	Statistics* test = new Statistics();
        test->clearStats();
	test->readStats();
	vector<tuple<int, int, int>> hold = test->getStats();

	EXPECT_EQ(hold.size(), 0);
}

TEST(StatisticsTest, AddStatsTest) {
        Statistics* test = new Statistics();
        test->clearStats();
	test->addStats(2, 67, 97);
	test->addStats(3, 52, 88);
	vector<tuple<int, int, int>> hold = test->getStats();

	EXPECT_EQ(hold.size(), 2);
	EXPECT_EQ(get<0>(hold.at(0)), 2);
        EXPECT_EQ(get<1>(hold.at(0)), 67);
        EXPECT_EQ(get<2>(hold.at(0)), 97);
        EXPECT_EQ(get<0>(hold.at(1)), 3);
        EXPECT_EQ(get<1>(hold.at(1)), 52);
        EXPECT_EQ(get<2>(hold.at(1)), 88);
}

TEST(StatisticsTest, WriteStatsTest) {
        Statistics* test = new Statistics();
        test->clearStats();
        test->addStats(1, 50, 50);
        test->addStats(3, 75, 100);
        test->writeStats();
        ifstream inFS("res/stats.txt");
        if (!inFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }

        string hold = "";
        getline(inFS, hold);
        EXPECT_EQ(hold, "1 50 50");
        getline(inFS, hold);
        EXPECT_EQ(hold, "3 75 100");
        inFS.close();
}

TEST(StatisticsTest, ReadStatsTest) {
        Statistics* test = new Statistics();
        test->clearStats();
        ofstream outFS("res/stats.txt");
        if (!outFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }
        outFS << "2 83 99" << endl << "1 49 64" << endl << "2 57 100";
        outFS.close();
        test->readStats();
        vector<tuple<int, int, int>> hold = test->getStats();

        EXPECT_EQ(hold.size(), 3);
        EXPECT_EQ(get<0>(hold.at(0)), 2);
        EXPECT_EQ(get<1>(hold.at(0)), 83);
        EXPECT_EQ(get<2>(hold.at(0)), 99);
        EXPECT_EQ(get<0>(hold.at(1)), 1);
        EXPECT_EQ(get<1>(hold.at(1)), 49);
        EXPECT_EQ(get<2>(hold.at(1)), 64);
        EXPECT_EQ(get<0>(hold.at(2)), 2);
        EXPECT_EQ(get<1>(hold.at(2)), 57);
        EXPECT_EQ(get<2>(hold.at(2)), 100);
}

TEST(StatisticsTest, getStatsFormattedTest) {
        Statistics* test = new Statistics();
        test->clearStats();
        test->addStats(1, 50, 50);
        test->addStats(3, 75, 100);
        test->addStats(2, 83, 99);
        test->addStats(1, 49, 64);
        vector<string> hold = test->getStatsFormatted();

        EXPECT_EQ(hold.at(0), "Difficulty: Novice -- WPM: 50 -- Accuracy: 50%");
        EXPECT_EQ(hold.at(1), "Difficulty: Advanced -- WPM: 75 -- Accuracy: 100%");
        EXPECT_EQ(hold.at(2), "Difficulty: Intermediate -- WPM: 83 -- Accuracy: 99%");
        EXPECT_EQ(hold.at(3), "Difficulty: Novice -- WPM: 49 -- Accuracy: 64%");
}

TEST(StatisticsTest, MultiFunctionTest) {
        Statistics* test = new Statistics();
        test->clearStats();
        test->addStats(3, 82, 84);
        test->addStats(2, 12, 34);
        test->addStats(1, 38, 48);
        test->addStats(2, 74, 25);

        vector<tuple<int, int, int>> hold1 = test->getStats();

        EXPECT_EQ(hold1.size(), 4);
        EXPECT_EQ(get<0>(hold1.at(0)), 3);
        EXPECT_EQ(get<1>(hold1.at(0)), 82);
        EXPECT_EQ(get<2>(hold1.at(0)), 84);
        EXPECT_EQ(get<0>(hold1.at(1)), 2);
        EXPECT_EQ(get<1>(hold1.at(1)), 12);
        EXPECT_EQ(get<2>(hold1.at(1)), 34);
        EXPECT_EQ(get<0>(hold1.at(2)), 1);
        EXPECT_EQ(get<1>(hold1.at(2)), 38);
        EXPECT_EQ(get<2>(hold1.at(2)), 48);
        EXPECT_EQ(get<0>(hold1.at(3)), 2);
        EXPECT_EQ(get<1>(hold1.at(3)), 74);
        EXPECT_EQ(get<2>(hold1.at(3)), 25);

        test->writeStats();

        ifstream inFS("res/stats.txt");
        if (!inFS.is_open()) {
                cout << "Error opening stats.txt to test." << endl;
        }

        string hold2 = "";
        getline(inFS, hold2);
        EXPECT_EQ(hold2, "3 82 84");
        getline(inFS, hold2);
        EXPECT_EQ(hold2, "2 12 34");
        getline(inFS, hold2);
        EXPECT_EQ(hold2, "1 38 48");
        getline(inFS, hold2);
        EXPECT_EQ(hold2, "2 74 25");

        inFS.close();
        
        vector<string> hold3 = test->getStatsFormatted();

        EXPECT_EQ(hold3.at(0), "Difficulty: Advanced -- WPM: 82 -- Accuracy: 84%");
        EXPECT_EQ(hold3.at(1), "Difficulty: Intermediate -- WPM: 12 -- Accuracy: 34%");
        EXPECT_EQ(hold3.at(2), "Difficulty: Novice -- WPM: 38 -- Accuracy: 48%");
        EXPECT_EQ(hold3.at(3), "Difficulty: Intermediate -- WPM: 74 -- Accuracy: 25%");
}

#endif // STATISTICS_TEST_HPP
