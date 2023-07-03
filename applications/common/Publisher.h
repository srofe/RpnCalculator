#pragma once

#include <list>
#include <Observer.h>

class Publisher {
public:
    void attach(Observer *observer);
    void detach(const std::string &name);

protected:
    std::list<Observer*> observers;
};

void Publisher::attach(Observer *observer) {
    observers.push_back(observer);
}

void Publisher::detach(const std::string &name) {
    auto toDelete = std::find_if(observers.begin(), observers.end(), [name](Observer *item) { return item->name() == name; } );
    observers.erase(toDelete);
}
