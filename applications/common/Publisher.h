#pragma once

#include <list>
#include <Observer.h>

class Publisher {
public:
    void attach(Observer *observer);
    void detach(Observer *observer);

protected:
    std::list<Observer*> observers;
};

void Publisher::attach(Observer *observer) {
    observers.push_back(observer);
}

void Publisher::detach(Observer *observer) {
    observers.remove(observer);
}
