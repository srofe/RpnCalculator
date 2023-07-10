#include <gmock/gmock.h>

enum class ErrorCondition {
    Empty
};

class StackErrorData {
public:
    StackErrorData(ErrorCondition condition) { errorCondition = condition; }
    ErrorCondition error() { return errorCondition; }

private:
    ErrorCondition errorCondition;
};

TEST(StackErrorDataTests, StackErrorDataHasErrorConditionEmpty) {
    StackErrorData errorData { ErrorCondition::Empty };
    ASSERT_EQ(errorData.error(), ErrorCondition::Empty) << "The StackErrorData shall have an error condition of Empty.";
}
