#include "gmock/gmock.h"

#import<stack>

class Stack {
private:
    std::deque<double> content;

public:

    void push(double item) {
        content.push_front(item);
    }

    double pop() {
        auto item = content.front();
        content.pop_front();
        return item;
    }

    std::vector<double> getElements(size_t length = -1) {
        if (length == -1) {
            length = content.size();
        }
        std::vector<double> elements;
        elements.insert(elements.begin(), content.begin(), content.begin() + length);
        return elements;
    }
};

class StackTests : public testing::Test {
public:
    Stack sut;
};

TEST_F(StackTests, PushItemToStackResultsInOneItemOnStack) {
    sut.push(3.2);
    ASSERT_EQ(sut.getElements().size(), 1) << "Pushing an item to the stack shall create a container with one item.";
}

TEST_F(StackTests, PushItemToStackAddsThatItem) {
    sut.push(4.5);
    ASSERT_EQ(sut.getElements()[0], 4.5) << "Pushing an item to the stack shall add that item to the top of the container.";
}

TEST_F(StackTests, PopItemRetrievesItemFromStack) {
    sut.push(2.1);
    auto item = sut.pop();
    ASSERT_EQ(item, 2.1) << "Popping an item from the stack shall retrieve that item from the stack.";
}

TEST_F(StackTests, PopItemFromStackRemovesTheItem) {
    sut.push(3.5);
    ASSERT_EQ(sut.getElements().size(), 1);
    sut.pop();
    ASSERT_EQ(sut.getElements().size(), 0) << "Popping and item from the stack shall remove the item from the stack.";
}

TEST_F(StackTests, PushingMultipleItemsAddsThemToTheStack) {
    sut.push(1.2);
    sut.push(3.4);
    sut.push(5.6);
    ASSERT_EQ(sut.getElements(3)[0], 5.6) << "Pushing multiple items to the stack shall add those items to the container - third item.";
    ASSERT_EQ(sut.getElements(3)[1], 3.4) << "Pushing multiple items to the stack shall add those items to the container - second item.";
    ASSERT_EQ(sut.getElements(3)[2], 1.2) << "Pushing multiple items to the stack shall add those items to the container - first item.";
}

TEST_F(StackTests, GetElementsReturnsStackElements) {
    sut.push(9.4);
    sut.push(6.7);
    sut.push(8.3);
    sut.push(1.9);
    std::vector<double> stackItems = { 1.9, 8.3, 6.7 };
    ASSERT_EQ(sut.getElements(3), stackItems) << "A Stack shall have a getElements(size_t) method which returns a vector containing the specified elements from the top of the stack.";
}

TEST_F(StackTests, GetElementsReturnsAllElementsByDefault) {
    sut.push(7.3);
    sut.push(8.9);
    sut.push(2.5);
    sut.push(6.1);
    std::vector<double> stackItems = { 6.1, 2.5, 8.9, 7.3 };
    ASSERT_EQ(sut.getElements(), stackItems) << "A Stack's getElements(size_t) method shall return all elements by default.";
}
