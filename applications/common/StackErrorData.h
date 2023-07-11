#include <string>

enum class ErrorCondition {
    Empty,
    TooFewArguments
};

class StackErrorData {
public:
    explicit StackErrorData(ErrorCondition condition) : errorCondition(condition) {};
    inline ErrorCondition error() { return errorCondition; }
    std::string message();

protected:
    StackErrorData() = default;

private:
    ErrorCondition errorCondition = static_cast<ErrorCondition>(-1);
};
