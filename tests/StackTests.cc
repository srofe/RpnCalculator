#include "gmock/gmock.h"

class Stack {};

TEST(StackTests, InitialPassingTest) {
    Stack soundex;
    ASSERT_EQ(1, 1);
}
