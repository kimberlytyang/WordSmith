#include "gtest/gtest.h"
#include "../tests/rectangle_test.hpp"
#include "../header/rectangle.hpp"
#include "../header/graphic.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
