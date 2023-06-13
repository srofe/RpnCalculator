#include "gmock/gmock.h"

#import<stack>

class Stack {
public:
    std::deque<double> content;

    void push(double item) {
        content.push_front(item);
    }

    double pop() {
        auto item = content.front();
        content.pop_front();
        return item;
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
    auto item = sut.pop();
    ASSERT_EQ(item, 2.1) << "Popping an item from the stack shall retrieve that item from the stack.";
}

TEST_F(StackTests, PopItemFromStackRemovesTheItem) {
    sut.push(3.5);
    ASSERT_EQ(sut.content.size(), 1);
    sut.pop();
    ASSERT_EQ(sut.content.size(), 0) << "Popping and item from the stack shall remove the item from the stack.";
}

TEST_F(StackTests, PushingMultipleItemsAddsThemToTheStack) {
    sut.push(1.2);
    sut.push(3.4);
    sut.push(5.6);
    ASSERT_EQ(sut.content[0], 5.6) << "Pushing multiple items to the stack shall add those items to the container - third item.";
    ASSERT_EQ(sut.content[1], 3.4) << "Pushing multiple items to the stack shall add those items to the container - second item.";
    ASSERT_EQ(sut.content[2], 1.2) << "Pushing multiple items to the stack shall add those items to the container - first item.";
}
