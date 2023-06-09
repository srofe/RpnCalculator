#include "Stack.h"

Stack &Stack::instance() {
    static Stack instance;
    return instance;
}

void Stack::push(double item) {
    content.push_front(item);
}

double Stack::pop() {
    auto item = content.front();
    content.pop_front();
    return item;
}

std::vector<double> Stack::getElements(int length) {
    if (length < 0) {
        length = content.size();
    }
    std::vector<double> elements;
    elements.insert(elements.begin(), content.begin(), content.begin() + length);
    return elements;
}

void Stack::clear() {
    content.clear();
}

void Stack::swapTop() {
    auto first = pop();
    auto second = pop();
    content.push_front(first);
    content.push_front(second);
}
