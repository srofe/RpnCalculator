#include "gmock/gmock.h"

#import<stack>

class Stack {
public:
    std::deque<double> content;
    void push(double item) {
        content.push_front(item);
    }

    double pop() {
        return content[0];
    }
};

class StackTests : public testing::Test {
public:
    Stack sut;
};

TEST_F(StackTests, PushItemToStackResultsInOneItemOnStack) {
    sut.push(3.2);
    ASSERT_EQ(sut.content.size(), 1) << "Pushing an item to the stack shall create a container with one item.";
}

TEST_F(StackTests, PushItemToStackAddsThatItem) {
    sut.push(4.5);
    ASSERT_EQ(sut.content[0], 4.5) << "Pushing an item to the stack shall add that item to the top of the container.";
}

TEST_F(StackTests, PopItemRetrievesItemFromStack) {
    sut.push(2.1);
    double item = sut.pop();
    ASSERT_EQ(item, 2.1) << "Popping an item from the stack shall retrieve that item from the stack.";
}
