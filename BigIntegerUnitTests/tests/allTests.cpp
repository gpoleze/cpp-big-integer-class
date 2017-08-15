#include "gtest/gtest.h"
#include "LinkedListTest.cpp"
#include "BigIntegerTest.cpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
