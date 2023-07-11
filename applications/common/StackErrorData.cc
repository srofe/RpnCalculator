#include "StackErrorData.h"

std::string StackErrorData::message() {
    switch (errorCondition) {
        case ErrorCondition::Empty: return "Attempting to pop from empty stack.";
        case ErrorCondition::TooFewArguments: return "At least two stack elements required for this operation.";
    }
    return "Unknown error.";
}
