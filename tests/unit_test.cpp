#include "gtest/gtest.h"
#include "line_test.hpp"
#include "rectangle_test.hpp"
#include "character_test.hpp"
#include "flyweight_test.hpp"
#include "window_test.hpp"
#include "promptselector_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
