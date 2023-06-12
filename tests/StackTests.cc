#include "gmock/gmock.h"

#import<stack>

class Stack {
public:
    std::stack<double> content;
    void push(double item) {
        content.push(item);
    }
};

TEST(StackTests, PushItemToStackResultsInOneItemOnStack) {
    Stack stack;
    stack.push(3.2);
    ASSERT_EQ(stack.content.size(), 1);
}
