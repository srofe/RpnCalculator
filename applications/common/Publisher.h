#pragma once

#include <list>
#include <Observer.h>
#include <Exception.h>

using ObserverList = std::list<Observer*>;

class Publisher {
public:
    void attach(Observer *observer);
    void detach(const std::string &name);

protected:
    ObserverList observers;
    void notify();
};

void Publisher::attach(Observer *observer) {
    observers.push_back(observer);
}

void Publisher::detach(const std::string &name) {
    auto toDelete = std::find_if(
            observers.begin(),
            observers.end(),
            [name](Observer *item) { return item->name() == name;}
            );
    if (toDelete == observers.end()) {
        throw Exception("Cannot detach Observer: Unknown observer name.");
    }
    observers.erase(toDelete);
}

void Publisher::notify() {
    for (auto observer : observers) {
        observer->update(EventData());
    }
}
