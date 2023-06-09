#pragma once

#include <deque>
#include <vector>

class Stack {
private:
    Stack() = default;
    ~Stack() = default;
    Stack(const Stack&) = delete;
    Stack &operator=(const Stack&) = delete;

    std::deque<double> content;

public:
    static Stack & instance();
    void push(double item);
    double pop();
    std::vector<double> getElements(int length = -1);
    void clear();
    void swapTop();
};
