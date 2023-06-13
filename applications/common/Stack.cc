#include "Stack.h"

void Stack::push(double item) {
    content.push_front(item);
}

double Stack::pop() {
    auto item = content.front();
    content.pop_front();
    return item;
}

std::vector<double> Stack::getElements(size_t length) {
    if (length == -1) {
        length = content.size();
    }
    std::vector<double> elements;
    elements.insert(elements.begin(), content.begin(), content.begin() + length);
    return elements;
}
