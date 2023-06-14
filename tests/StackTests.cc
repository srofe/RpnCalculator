#include "gmock/gmock.h"
#include <Stack.h>

class StackTests : public testing::Test {
public:
    Stack &sut = Stack::instance();

protected:
    void SetUp() override {
        sut.clear();
    }
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

TEST_F(StackTests, GetElementsReturnsNoItemsIfNoneRequested) {
    sut.push(1.5);
    sut.push(7.5);
    sut.push(3.4);
    sut.push(2.1);
    std::vector<double> emptyVector = {};
    ASSERT_EQ(sut.getElements(0), emptyVector) << "A Stack's getElements(size_t) method shall return no items if zero are requested.";
}

TEST_F(StackTests, ClearRemovesAllElements) {
    sut.push(5.4);
    sut.push(3.9);
    sut.push(6.7);
    sut.push(9.0);
    sut.clear();
    std::vector<double> emptyVector = {};
    ASSERT_EQ(sut.getElements(), emptyVector) << "A Stack's clear() method shall remove all elements.";
}

TEST_F(StackTests, SwapTopExchangesTopTwoItems) {
    sut.push(2.6);
    sut.push(9.4);
    sut.push(0.3);
    sut.push(7.5);
    sut.swapTop();
    std::vector<double> emptyVector = { 0.3, 7.5, 9.4, 2.6 };
    ASSERT_EQ(sut.getElements(), emptyVector) << "A Stack's clear() method shall remove all elements.";
}
