#include <gmock/gmock.h>

enum class ErrorCondition {
    Empty
};

class StackErrorData {
public:
    ErrorCondition error() { return ErrorCondition::Empty; }
};

TEST(StackErrorDataTests, StackErrorDataHasErrorCondition) {
    StackErrorData errorData;
    ASSERT_EQ(errorData.error(), ErrorCondition::Empty) << "The StackErrorData shall have an error condition of Empty.";
}
