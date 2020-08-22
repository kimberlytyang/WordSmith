#ifndef STATISTICS_TEST_HPP
#define STATISTICS_TEST_HPP

#include "../header/statistics.hpp"
#include <iostream>

TEST(StatisticsTest, SortByDifficulty) {
	Statistics* test = new Statistics();	
	test->addStats(2, 100, 98);
	test->addStats(1, 80, 100);
	test->addStats(3, 60, 99);
	test->addStats(1, 110, 89);
	test->addStats(2, 85, 92);

	ASSERT_EQ(test->getStats().size(), 5);
	test->sort(difficulty);	
	ASSERT_EQ(test->getStats().size(), 5);
	
	vector<tuple<int, int, int>> v = test->getStats();
	EXPECT_EQ(std::get<0>(v.at(0)), 1);
	EXPECT_EQ(std::get<1>(v.at(0)), 80);
	EXPECT_EQ(std::get<2>(v.at(0)), 100);
	
	EXPECT_EQ(std::get<0>(v.at(1)), 1);
        EXPECT_EQ(std::get<1>(v.at(1)), 110);
        EXPECT_EQ(std::get<2>(v.at(1)), 89);
	
	EXPECT_EQ(std::get<0>(v.at(2)), 2);
        EXPECT_EQ(std::get<1>(v.at(2)), 100);
        EXPECT_EQ(std::get<2>(v.at(2)), 98);

	EXPECT_EQ(std::get<0>(v.at(3)), 2);
        EXPECT_EQ(std::get<1>(v.at(3)), 85);
        EXPECT_EQ(std::get<2>(v.at(3)), 92);

	EXPECT_EQ(std::get<0>(v.at(4)), 3);
        EXPECT_EQ(std::get<1>(v.at(4)), 60);
        EXPECT_EQ(std::get<2>(v.at(4)), 99);
}

TEST(StatisticsTest, SortByWPM) {
        Statistics* test = new Statistics();
        test->addStats(2, 100, 98);
        test->addStats(1, 80, 100);
        test->addStats(3, 60, 99);
        test->addStats(1, 110, 89);
        test->addStats(2, 85, 92);

        ASSERT_EQ(test->getStats().size(), 5);
        test->sort(wpm);
        ASSERT_EQ(test->getStats().size(), 5);

        vector<tuple<int, int, int>> v = test->getStats();
        EXPECT_EQ(std::get<0>(v.at(0)), 3);
        EXPECT_EQ(std::get<1>(v.at(0)), 60);
        EXPECT_EQ(std::get<2>(v.at(0)), 99);

        EXPECT_EQ(std::get<0>(v.at(1)), 1);
        EXPECT_EQ(std::get<1>(v.at(1)), 80);
        EXPECT_EQ(std::get<2>(v.at(1)), 100);

        EXPECT_EQ(std::get<0>(v.at(2)), 2);
        EXPECT_EQ(std::get<1>(v.at(2)), 85);
        EXPECT_EQ(std::get<2>(v.at(2)), 92);

        EXPECT_EQ(std::get<0>(v.at(3)), 2);
        EXPECT_EQ(std::get<1>(v.at(3)), 100);
        EXPECT_EQ(std::get<2>(v.at(3)), 98);

        EXPECT_EQ(std::get<0>(v.at(4)), 1);
        EXPECT_EQ(std::get<1>(v.at(4)), 110);
        EXPECT_EQ(std::get<2>(v.at(4)), 89);
}

TEST(StatisticsTest, SortByAccuracy) {
        Statistics* test = new Statistics();
        test->addStats(2, 100, 98);
        test->addStats(1, 80, 100);
        test->addStats(3, 60, 99);
        test->addStats(1, 110, 89);
        test->addStats(2, 85, 92);

        ASSERT_EQ(test->getStats().size(), 5);
        test->sort(accuracy);
        ASSERT_EQ(test->getStats().size(), 5);

        vector<tuple<int, int, int>> v = test->getStats();
        EXPECT_EQ(std::get<0>(v.at(0)), 1);
        EXPECT_EQ(std::get<1>(v.at(0)), 110);
        EXPECT_EQ(std::get<2>(v.at(0)), 89);

        EXPECT_EQ(std::get<0>(v.at(1)), 2);
        EXPECT_EQ(std::get<1>(v.at(1)), 85);
        EXPECT_EQ(std::get<2>(v.at(1)), 92);

        EXPECT_EQ(std::get<0>(v.at(2)), 2);
        EXPECT_EQ(std::get<1>(v.at(2)), 100);
        EXPECT_EQ(std::get<2>(v.at(2)), 98);

        EXPECT_EQ(std::get<0>(v.at(3)), 3);
        EXPECT_EQ(std::get<1>(v.at(3)), 60);
        EXPECT_EQ(std::get<2>(v.at(3)), 99);

        EXPECT_EQ(std::get<0>(v.at(4)), 1);
        EXPECT_EQ(std::get<1>(v.at(4)), 80);
        EXPECT_EQ(std::get<2>(v.at(4)), 100);
}


#endif // STATISTICS_TEST_HPP
