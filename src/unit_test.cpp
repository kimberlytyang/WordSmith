#include "gtest/gtest.h"
#include "../tests/line_test.hpp"
#include "../tests/rectangle_test.hpp"

#include "../tests/character_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
