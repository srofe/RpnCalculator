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
    ASSERT_EQ(stack.content.size(), 1) << "Pushing an item to the stack shall create a container with one item.";
}

TEST(StackTests, PushItemToStackAddsThatItem) {
    Stack stack;
    stack.push(4.5);
    ASSERT_EQ(stack.content[0], 4.5) << "Pushing an item to the stack shall add that item to the top of the container.";
}
