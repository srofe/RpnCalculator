#ifndef __STACK_H__
#define __STACK_H__

#include <stack>

class Stack {
private:
    std::deque<double> content;

public:

    void push(double item) {
        content.push_front(item);
    }

    double pop() {
        auto item = content.front();
        content.pop_front();
        return item;
    }

    std::vector<double> getElements(size_t length = -1) {
        if (length == -1) {
            length = content.size();
        }
        std::vector<double> elements;
        elements.insert(elements.begin(), content.begin(), content.begin() + length);
        return elements;
    }
};

#endif // __STACK_H__
