#include "gtest/gtest.h"
#include "line_test.hpp"
#include "rectangle_test.hpp"
#include "character_test.hpp"
#include "char_iterator_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
