#include "gmock/gmock.h"

class Stack {};

TEST(Stack, InitialPassingTest) {
    Stack soundex;
    ASSERT_EQ(1, 1);
}
