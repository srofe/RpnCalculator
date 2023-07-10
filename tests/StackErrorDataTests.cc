#include <gmock/gmock.h>

enum class ErrorCondition {
    Empty,
    TooFewArguments
};

class StackErrorData {
public:
    StackErrorData(ErrorCondition condition) { errorCondition = condition; }
    ErrorCondition error() { return errorCondition; }

private:
    StackErrorData();
    ErrorCondition errorCondition;
};

TEST(StackErrorDataTests, StackErrorDataHasErrorConditionEmpty) {
    StackErrorData errorData { ErrorCondition::Empty };
    ASSERT_EQ(errorData.error(), ErrorCondition::Empty) << "The StackErrorData shall have an error condition of Empty.";
}

TEST(StackeErrorDataTests, StackErrorDataHasErrorConditionTooFewArguments) {
    StackErrorData errorData { ErrorCondition::TooFewArguments };
    ASSERT_EQ(errorData.error(), ErrorCondition::TooFewArguments) << "The StackErrorData shall have an error condition of TooFewArguments.";
}
