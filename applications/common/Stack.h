#ifndef __STACK_H__
#define __STACK_H__

#include <deque>
#include <vector>

class Stack {
private:
    std::deque<double> content;

public:
    void push(double item);
    double pop();
    std::vector<double> getElements(size_t length = -1);
};

#endif // __STACK_H__
