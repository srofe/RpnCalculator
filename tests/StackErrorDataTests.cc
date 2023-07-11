#include <gmock/gmock.h>
#include <StackErrorData.h>

class StackErrorDataMock : public StackErrorData {
public:
    using StackErrorData::StackErrorData;
};

TEST(StackErrorDataTests, StackErrorDataHasErrorConditionEmpty) {
    StackErrorData errorData { ErrorCondition::Empty };
    ASSERT_EQ(errorData.error(), ErrorCondition::Empty) << "The StackErrorData shall have an error condition of Empty.";
}

TEST(StackErrorDataTests, StackErrorDataHasErrorConditionTooFewArguments) {
    StackErrorData errorData { ErrorCondition::TooFewArguments };
    ASSERT_EQ(errorData.error(), ErrorCondition::TooFewArguments) << "The StackErrorData shall have an error condition of TooFewArguments.";
}

TEST(StackErrorDataTests, StackErrorDataProvidesEmptyErrorMessage) {
    StackErrorData errorData { ErrorCondition::Empty };
    ASSERT_EQ(errorData.message(), "Attempting to pop from empty stack.") << "The StackErrorData shall provide a message for an error condition.";
}

TEST(StackErrorDataTests, StackErrorDataProvidesTooFewArgumentsMessage) {
    StackErrorData errorData { ErrorCondition::TooFewArguments };
    ASSERT_EQ(errorData.message(), "At least two stack elements required for this operation.") << "The StackErrorData shall provide a message for an error condition.";
}

TEST(StackErrorDataTests, StackErrorDataProvidesUnkownErrorMessage) {
    StackErrorDataMock mockErrorData;
    ASSERT_EQ(mockErrorData.message(), "Unknown error.") << " A StackErrorData shall provide a default message for unknown error condition.";
}
