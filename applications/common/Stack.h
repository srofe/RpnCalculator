#pragma once

#include <deque>
#include <vector>
#include <Publisher.h>

class Stack : private Publisher {
public:
    Stack(const Stack&) = delete;
    Stack &operator=(const Stack&) = delete;
    static Stack & instance();
    void push(double item);
    double pop();
    std::vector<double> getElements(int length = -1);
    void clear();
    void swapTop();

    using Publisher::attach;

private:
    Stack();
    ~Stack() = default;

    std::deque<double> content;
};
