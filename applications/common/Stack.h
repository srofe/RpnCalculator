#ifndef __STACK_H__
#define __STACK_H__

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
    std::vector<double> getElements(size_t length = 0);
};

#endif // __STACK_H__
