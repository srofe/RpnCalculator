#include "gmock/gmock.h"

#import<stack>

class Stack {
public:
    std::deque<double> content;
    void push(double item) {
        content.push_front(item);
    }
};

TEST(StackTests, PushItemToStackResultsInOneItemOnStack) {
    Stack stack;
    stack.push(3.2);
    ASSERT_EQ(stack.content.size(), 1);
}
