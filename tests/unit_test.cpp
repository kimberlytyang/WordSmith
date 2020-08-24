#include "gtest/gtest.h"
#include "line_test.hpp"
#include "rectangle_test.hpp"
#include "character_test.hpp"
#include "flyweight_test.hpp"
#include "window_test.hpp"
#include "parse_novice_test.hpp"
#include "parse_intermediate_test.hpp"
#include "parse_advanced_test.hpp"
#include "parse_random_test.hpp"
#include "prompt_selector_test.hpp"
#include "statistics_test.hpp"
#include "parse_ranked_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
